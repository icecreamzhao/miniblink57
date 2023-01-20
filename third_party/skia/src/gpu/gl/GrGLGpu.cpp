/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "GrGLGpu.h"
#include "GrGLBuffer.h"
#include "GrGLGLSL.h"
#include "GrGLGpuCommandBuffer.h"
#include "GrGLStencilAttachment.h"
#include "GrGLTextureRenderTarget.h"
#include "GrGpuResourcePriv.h"
#include "GrMesh.h"
#include "GrPLSGeometryProcessor.h"
#include "GrPipeline.h"
#include "GrRenderTargetPriv.h"
#include "GrSurfacePriv.h"
#include "GrTexturePriv.h"
#include "GrTypes.h"
#include "SkMipMap.h"
#include "SkPixmap.h"
#include "SkStrokeRec.h"
#include "SkTemplates.h"
#include "SkTypes.h"
#include "builders/GrGLShaderStringBuilder.h"
#include "glsl/GrGLSL.h"
#include "glsl/GrGLSLCaps.h"
#include "glsl/GrGLSLPLSPathRendering.h"
=======

#include "GrGLGpu.h"
#include "GrGLGLSL.h"
#include "GrGLStencilAttachment.h"
#include "GrGLTextureRenderTarget.h"
#include "GrGpuResourcePriv.h"
#include "GrPipeline.h"
#include "GrRenderTargetPriv.h"
#include "GrSurfacePriv.h"
#include "GrTemplates.h"
#include "GrTexturePriv.h"
#include "GrTypes.h"
#include "GrVertices.h"
#include "builders/GrGLShaderStringBuilder.h"
#include "glsl/GrGLSLCaps.h"
#include "SkStrokeRec.h"
#include "SkTemplates.h"
>>>>>>> miniblink49

#define GL_CALL(X) GR_GL_CALL(this->glInterface(), X)
#define GL_CALL_RET(RET, X) GR_GL_CALL_RET(this->glInterface(), RET, X)

<<<<<<< HEAD
#define SKIP_CACHE_CHECK true

#if GR_GL_CHECK_ALLOC_WITH_GET_ERROR
#define CLEAR_ERROR_BEFORE_ALLOC(iface) GrGLClearErr(iface)
#define GL_ALLOC_CALL(iface, call) GR_GL_CALL_NOERRCHECK(iface, call)
#define CHECK_ALLOC_ERROR(iface) GR_GL_GET_ERROR(iface)
#else
#define CLEAR_ERROR_BEFORE_ALLOC(iface)
#define GL_ALLOC_CALL(iface, call) GR_GL_CALL(iface, call)
#define CHECK_ALLOC_ERROR(iface) GR_GL_NO_ERROR
#endif

///////////////////////////////////////////////////////////////////////////////

=======
#define SKIP_CACHE_CHECK    true

#if GR_GL_CHECK_ALLOC_WITH_GET_ERROR
    #define CLEAR_ERROR_BEFORE_ALLOC(iface)   GrGLClearErr(iface)
    #define GL_ALLOC_CALL(iface, call)        GR_GL_CALL_NOERRCHECK(iface, call)
    #define CHECK_ALLOC_ERROR(iface)          GR_GL_GET_ERROR(iface)
#else
    #define CLEAR_ERROR_BEFORE_ALLOC(iface)
    #define GL_ALLOC_CALL(iface, call)        GR_GL_CALL(iface, call)
    #define CHECK_ALLOC_ERROR(iface)          GR_GL_NO_ERROR
#endif


///////////////////////////////////////////////////////////////////////////////


>>>>>>> miniblink49
static const GrGLenum gXfermodeEquation2Blend[] = {
    // Basic OpenGL blend equations.
    GR_GL_FUNC_ADD,
    GR_GL_FUNC_SUBTRACT,
    GR_GL_FUNC_REVERSE_SUBTRACT,

    // GL_KHR_blend_equation_advanced.
    GR_GL_SCREEN,
    GR_GL_OVERLAY,
    GR_GL_DARKEN,
    GR_GL_LIGHTEN,
    GR_GL_COLORDODGE,
    GR_GL_COLORBURN,
    GR_GL_HARDLIGHT,
    GR_GL_SOFTLIGHT,
    GR_GL_DIFFERENCE,
    GR_GL_EXCLUSION,
    GR_GL_MULTIPLY,
    GR_GL_HSL_HUE,
    GR_GL_HSL_SATURATION,
    GR_GL_HSL_COLOR,
    GR_GL_HSL_LUMINOSITY
};
GR_STATIC_ASSERT(0 == kAdd_GrBlendEquation);
GR_STATIC_ASSERT(1 == kSubtract_GrBlendEquation);
GR_STATIC_ASSERT(2 == kReverseSubtract_GrBlendEquation);
GR_STATIC_ASSERT(3 == kScreen_GrBlendEquation);
GR_STATIC_ASSERT(4 == kOverlay_GrBlendEquation);
GR_STATIC_ASSERT(5 == kDarken_GrBlendEquation);
GR_STATIC_ASSERT(6 == kLighten_GrBlendEquation);
GR_STATIC_ASSERT(7 == kColorDodge_GrBlendEquation);
GR_STATIC_ASSERT(8 == kColorBurn_GrBlendEquation);
GR_STATIC_ASSERT(9 == kHardLight_GrBlendEquation);
GR_STATIC_ASSERT(10 == kSoftLight_GrBlendEquation);
GR_STATIC_ASSERT(11 == kDifference_GrBlendEquation);
GR_STATIC_ASSERT(12 == kExclusion_GrBlendEquation);
GR_STATIC_ASSERT(13 == kMultiply_GrBlendEquation);
GR_STATIC_ASSERT(14 == kHSLHue_GrBlendEquation);
GR_STATIC_ASSERT(15 == kHSLSaturation_GrBlendEquation);
GR_STATIC_ASSERT(16 == kHSLColor_GrBlendEquation);
GR_STATIC_ASSERT(17 == kHSLLuminosity_GrBlendEquation);
GR_STATIC_ASSERT(SK_ARRAY_COUNT(gXfermodeEquation2Blend) == kGrBlendEquationCnt);

static const GrGLenum gXfermodeCoeff2Blend[] = {
    GR_GL_ZERO,
    GR_GL_ONE,
    GR_GL_SRC_COLOR,
    GR_GL_ONE_MINUS_SRC_COLOR,
    GR_GL_DST_COLOR,
    GR_GL_ONE_MINUS_DST_COLOR,
    GR_GL_SRC_ALPHA,
    GR_GL_ONE_MINUS_SRC_ALPHA,
    GR_GL_DST_ALPHA,
    GR_GL_ONE_MINUS_DST_ALPHA,
    GR_GL_CONSTANT_COLOR,
    GR_GL_ONE_MINUS_CONSTANT_COLOR,
    GR_GL_CONSTANT_ALPHA,
    GR_GL_ONE_MINUS_CONSTANT_ALPHA,

    // extended blend coeffs
    GR_GL_SRC1_COLOR,
    GR_GL_ONE_MINUS_SRC1_COLOR,
    GR_GL_SRC1_ALPHA,
    GR_GL_ONE_MINUS_SRC1_ALPHA,
};

<<<<<<< HEAD
bool GrGLGpu::BlendCoeffReferencesConstant(GrBlendCoeff coeff)
{
=======
bool GrGLGpu::BlendCoeffReferencesConstant(GrBlendCoeff coeff) {
>>>>>>> miniblink49
    static const bool gCoeffReferencesBlendConst[] = {
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        true,
        true,
        true,
        true,

        // extended blend coeffs
        false,
        false,
        false,
        false,
    };
    return gCoeffReferencesBlendConst[coeff];
    GR_STATIC_ASSERT(kGrBlendCoeffCnt == SK_ARRAY_COUNT(gCoeffReferencesBlendConst));

    GR_STATIC_ASSERT(0 == kZero_GrBlendCoeff);
    GR_STATIC_ASSERT(1 == kOne_GrBlendCoeff);
    GR_STATIC_ASSERT(2 == kSC_GrBlendCoeff);
    GR_STATIC_ASSERT(3 == kISC_GrBlendCoeff);
    GR_STATIC_ASSERT(4 == kDC_GrBlendCoeff);
    GR_STATIC_ASSERT(5 == kIDC_GrBlendCoeff);
    GR_STATIC_ASSERT(6 == kSA_GrBlendCoeff);
    GR_STATIC_ASSERT(7 == kISA_GrBlendCoeff);
    GR_STATIC_ASSERT(8 == kDA_GrBlendCoeff);
    GR_STATIC_ASSERT(9 == kIDA_GrBlendCoeff);
    GR_STATIC_ASSERT(10 == kConstC_GrBlendCoeff);
    GR_STATIC_ASSERT(11 == kIConstC_GrBlendCoeff);
    GR_STATIC_ASSERT(12 == kConstA_GrBlendCoeff);
    GR_STATIC_ASSERT(13 == kIConstA_GrBlendCoeff);

    GR_STATIC_ASSERT(14 == kS2C_GrBlendCoeff);
    GR_STATIC_ASSERT(15 == kIS2C_GrBlendCoeff);
    GR_STATIC_ASSERT(16 == kS2A_GrBlendCoeff);
    GR_STATIC_ASSERT(17 == kIS2A_GrBlendCoeff);

    // assertion for gXfermodeCoeff2Blend have to be in GrGpu scope
    GR_STATIC_ASSERT(kGrBlendCoeffCnt == SK_ARRAY_COUNT(gXfermodeCoeff2Blend));
}

///////////////////////////////////////////////////////////////////////////////

GrGpu* GrGLGpu::Create(GrBackendContext backendContext, const GrContextOptions& options,
<<<<<<< HEAD
    GrContext* context)
{
=======
                       GrContext* context) {
>>>>>>> miniblink49
    SkAutoTUnref<const GrGLInterface> glInterface(
        reinterpret_cast<const GrGLInterface*>(backendContext));
    if (!glInterface) {
        glInterface.reset(GrGLDefaultInterface());
    } else {
        glInterface->ref();
    }
    if (!glInterface) {
<<<<<<< HEAD
        return nullptr;
    }
    GrGLContext* glContext = GrGLContext::Create(glInterface, options);
    if (glContext) {
        return new GrGLGpu(glContext, context);
    }
    return nullptr;
=======
        return NULL;
    }
    GrGLContext* glContext = GrGLContext::Create(glInterface, options);
    if (glContext) {
        return SkNEW_ARGS(GrGLGpu, (glContext, context));
    }
    return NULL;
>>>>>>> miniblink49
}

static bool gPrintStartupSpew;

GrGLGpu::GrGLGpu(GrGLContext* ctx, GrContext* context)
    : GrGpu(context)
<<<<<<< HEAD
    , fGLContext(ctx)
    , fProgramCache(new ProgramCache(this))
    , fHWProgramID(0)
    , fTempSrcFBOID(0)
    , fTempDstFBOID(0)
    , fStencilClearFBOID(0)
    , fHWMaxUsedBufferTextureUnit(-1)
    , fHWPLSEnabled(false)
    , fPLSHasBeenUsed(false)
    , fHWMinSampleShading(0.0)
{
    for (size_t i = 0; i < SK_ARRAY_COUNT(fCopyPrograms); ++i) {
        fCopyPrograms[i].fProgram = 0;
    }
    for (size_t i = 0; i < SK_ARRAY_COUNT(fMipmapPrograms); ++i) {
        fMipmapPrograms[i].fProgram = 0;
    }
    fWireRectProgram.fProgram = 0;
    fPLSSetupProgram.fProgram = 0;

    SkASSERT(ctx);
    fCaps.reset(SkRef(ctx->caps()));

    fHWBoundTextureUniqueIDs.reset(this->glCaps().glslCaps()->maxCombinedSamplers());

    fHWBufferState[kVertex_GrBufferType].fGLTarget = GR_GL_ARRAY_BUFFER;
    fHWBufferState[kIndex_GrBufferType].fGLTarget = GR_GL_ELEMENT_ARRAY_BUFFER;
    fHWBufferState[kTexel_GrBufferType].fGLTarget = GR_GL_TEXTURE_BUFFER;
    fHWBufferState[kDrawIndirect_GrBufferType].fGLTarget = GR_GL_DRAW_INDIRECT_BUFFER;
    if (GrGLCaps::kChromium_TransferBufferType == this->glCaps().transferBufferType()) {
        fHWBufferState[kXferCpuToGpu_GrBufferType].fGLTarget = GR_GL_PIXEL_UNPACK_TRANSFER_BUFFER_CHROMIUM;
        fHWBufferState[kXferGpuToCpu_GrBufferType].fGLTarget = GR_GL_PIXEL_PACK_TRANSFER_BUFFER_CHROMIUM;
    } else {
        fHWBufferState[kXferCpuToGpu_GrBufferType].fGLTarget = GR_GL_PIXEL_UNPACK_BUFFER;
        fHWBufferState[kXferGpuToCpu_GrBufferType].fGLTarget = GR_GL_PIXEL_PACK_BUFFER;
    }
    GR_STATIC_ASSERT(6 == SK_ARRAY_COUNT(fHWBufferState));

    if (this->caps()->shaderCaps()->texelBufferSupport()) {
        fHWBufferTextures.reset(this->glCaps().glslCaps()->maxCombinedSamplers());
    }

    if (this->glCaps().shaderCaps()->pathRenderingSupport()) {
        fPathRendering.reset(new GrGLPathRendering(this));
    }
=======
    , fGLContext(ctx) {
    SkASSERT(ctx);
    fCaps.reset(SkRef(ctx->caps()));

    fHWBoundTextureUniqueIDs.reset(this->glCaps().maxFragmentTextureUnits());
>>>>>>> miniblink49

    GrGLClearErr(this->glInterface());
    if (gPrintStartupSpew) {
        const GrGLubyte* vendor;
        const GrGLubyte* renderer;
        const GrGLubyte* version;
        GL_CALL_RET(vendor, GetString(GR_GL_VENDOR));
        GL_CALL_RET(renderer, GetString(GR_GL_RENDERER));
        GL_CALL_RET(version, GetString(GR_GL_VERSION));
        SkDebugf("------------------------- create GrGLGpu %p --------------\n",
<<<<<<< HEAD
            this);
        SkDebugf("------ VENDOR %s\n", vendor);
        SkDebugf("------ RENDERER %s\n", renderer);
        SkDebugf("------ VERSION %s\n", version);
=======
                 this);
        SkDebugf("------ VENDOR %s\n", vendor);
        SkDebugf("------ RENDERER %s\n", renderer);
        SkDebugf("------ VERSION %s\n",  version);
>>>>>>> miniblink49
        SkDebugf("------ EXTENSIONS\n");
        this->glContext().extensions().print();
        SkDebugf("\n");
        SkDebugf("%s", this->glCaps().dump().c_str());
    }
<<<<<<< HEAD
}

GrGLGpu::~GrGLGpu()
{
    // Ensure any GrGpuResource objects get deleted first, since they may require a working GrGLGpu
    // to release the resources held by the objects themselves.
    fPathRendering.reset();
    fCopyProgramArrayBuffer.reset();
    fMipmapProgramArrayBuffer.reset();
    fWireRectArrayBuffer.reset();
    fPLSSetupProgram.fArrayBuffer.reset();

=======

    fProgramCache = SkNEW_ARGS(ProgramCache, (this));

    SkASSERT(this->glCaps().maxVertexAttributes() >= GrGeometryProcessor::kMaxVertexAttribs);

    fLastSuccessfulStencilFmtIdx = 0;
    fHWProgramID = 0;
    fTempSrcFBOID = 0;
    fTempDstFBOID = 0;
    fStencilClearFBOID = 0;

    if (this->glCaps().shaderCaps()->pathRenderingSupport()) {
        fPathRendering.reset(new GrGLPathRendering(this));
    }

    this->createCopyProgram();
}

GrGLGpu::~GrGLGpu() {
>>>>>>> miniblink49
    if (0 != fHWProgramID) {
        // detach the current program so there is no confusion on OpenGL's part
        // that we want it to be deleted
        GL_CALL(UseProgram(0));
    }

    if (0 != fTempSrcFBOID) {
        GL_CALL(DeleteFramebuffers(1, &fTempSrcFBOID));
    }
    if (0 != fTempDstFBOID) {
        GL_CALL(DeleteFramebuffers(1, &fTempDstFBOID));
    }
    if (0 != fStencilClearFBOID) {
        GL_CALL(DeleteFramebuffers(1, &fStencilClearFBOID));
    }

<<<<<<< HEAD
    for (size_t i = 0; i < SK_ARRAY_COUNT(fCopyPrograms); ++i) {
        if (0 != fCopyPrograms[i].fProgram) {
            GL_CALL(DeleteProgram(fCopyPrograms[i].fProgram));
        }
    }

    for (size_t i = 0; i < SK_ARRAY_COUNT(fMipmapPrograms); ++i) {
        if (0 != fMipmapPrograms[i].fProgram) {
            GL_CALL(DeleteProgram(fMipmapPrograms[i].fProgram));
        }
    }

    if (0 != fWireRectProgram.fProgram) {
        GL_CALL(DeleteProgram(fWireRectProgram.fProgram));
    }

    if (0 != fPLSSetupProgram.fProgram) {
        GL_CALL(DeleteProgram(fPLSSetupProgram.fProgram));
=======
    if (0 != fCopyProgram.fArrayBuffer) {
        GL_CALL(DeleteBuffers(1, &fCopyProgram.fArrayBuffer));
    }

    if (0 != fCopyProgram.fProgram) {
        GL_CALL(DeleteProgram(fCopyProgram.fProgram));
>>>>>>> miniblink49
    }

    delete fProgramCache;
}

<<<<<<< HEAD
bool GrGLGpu::createPLSSetupProgram()
{
    if (!fPLSSetupProgram.fArrayBuffer) {
        static const GrGLfloat vdata[] = {
            0, 0,
            0, 1,
            1, 0,
            1, 1
        };
        fPLSSetupProgram.fArrayBuffer.reset(GrGLBuffer::Create(this, sizeof(vdata),
            kVertex_GrBufferType,
            kStatic_GrAccessPattern, vdata));
        if (!fPLSSetupProgram.fArrayBuffer) {
            return false;
        }
    }

    SkASSERT(!fPLSSetupProgram.fProgram);
    GL_CALL_RET(fPLSSetupProgram.fProgram, CreateProgram());
    if (!fPLSSetupProgram.fProgram) {
        return false;
    }

    const GrGLSLCaps* glslCaps = this->glCaps().glslCaps();
    const char* version = glslCaps->versionDeclString();

    GrGLSLShaderVar aVertex("a_vertex", kVec2f_GrSLType, GrShaderVar::kAttribute_TypeModifier);
    GrGLSLShaderVar uTexCoordXform("u_texCoordXform", kVec4f_GrSLType,
        GrShaderVar::kUniform_TypeModifier);
    GrGLSLShaderVar uPosXform("u_posXform", kVec4f_GrSLType, GrShaderVar::kUniform_TypeModifier);
    GrGLSLShaderVar uTexture("u_texture", kSampler2D_GrSLType, GrShaderVar::kUniform_TypeModifier);
    GrGLSLShaderVar vTexCoord("v_texCoord", kVec2f_GrSLType, GrShaderVar::kVaryingOut_TypeModifier);

    SkString vshaderTxt(version);
    if (glslCaps->noperspectiveInterpolationSupport()) {
        if (const char* extension = glslCaps->noperspectiveInterpolationExtensionString()) {
            vshaderTxt.appendf("#extension %s : require\n", extension);
        }
        vTexCoord.addModifier("noperspective");
    }
    aVertex.appendDecl(glslCaps, &vshaderTxt);
    vshaderTxt.append(";");
    uTexCoordXform.appendDecl(glslCaps, &vshaderTxt);
    vshaderTxt.append(";");
    uPosXform.appendDecl(glslCaps, &vshaderTxt);
    vshaderTxt.append(";");
    vTexCoord.appendDecl(glslCaps, &vshaderTxt);
    vshaderTxt.append(";");

    vshaderTxt.append(
        "// PLS Setup Program VS\n"
        "void main() {"
        "  gl_Position.xy = a_vertex * u_posXform.xy + u_posXform.zw;"
        "  gl_Position.zw = vec2(0, 1);"
        "}");

    SkString fshaderTxt(version);
    if (glslCaps->noperspectiveInterpolationSupport()) {
        if (const char* extension = glslCaps->noperspectiveInterpolationExtensionString()) {
            fshaderTxt.appendf("#extension %s : require\n", extension);
        }
    }
    fshaderTxt.append("#extension ");
    fshaderTxt.append(glslCaps->fbFetchExtensionString());
    fshaderTxt.append(" : require\n");
    fshaderTxt.append("#extension GL_EXT_shader_pixel_local_storage : require\n");
    GrGLSLAppendDefaultFloatPrecisionDeclaration(kDefault_GrSLPrecision, *glslCaps, &fshaderTxt);
    vTexCoord.setTypeModifier(GrShaderVar::kVaryingIn_TypeModifier);
    vTexCoord.appendDecl(glslCaps, &fshaderTxt);
    fshaderTxt.append(";");
    uTexture.appendDecl(glslCaps, &fshaderTxt);
    fshaderTxt.append(";");

    fshaderTxt.appendf(
        "// PLS Setup Program FS\n" GR_GL_PLS_PATH_DATA_DECL
        "void main() {\n"
        "    " GR_GL_PLS_DSTCOLOR_NAME " = gl_LastFragColorARM;\n"
        "    pls.windings = ivec4(0, 0, 0, 0);\n"
        "}");

    const char* str;
    GrGLint length;

    str = vshaderTxt.c_str();
    length = SkToInt(vshaderTxt.size());
    GrGLuint vshader = GrGLCompileAndAttachShader(*fGLContext, fPLSSetupProgram.fProgram,
        GR_GL_VERTEX_SHADER, &str, &length, 1, &fStats);

    str = fshaderTxt.c_str();
    length = SkToInt(fshaderTxt.size());
    GrGLuint fshader = GrGLCompileAndAttachShader(*fGLContext, fPLSSetupProgram.fProgram,
        GR_GL_FRAGMENT_SHADER, &str, &length, 1, &fStats);

    GL_CALL(LinkProgram(fPLSSetupProgram.fProgram));

    GL_CALL_RET(fPLSSetupProgram.fPosXformUniform, GetUniformLocation(fPLSSetupProgram.fProgram, "u_posXform"));

    GL_CALL(BindAttribLocation(fPLSSetupProgram.fProgram, 0, "a_vertex"));

    GL_CALL(DeleteShader(vshader));
    GL_CALL(DeleteShader(fshader));

    return true;
}

void GrGLGpu::disconnect(DisconnectType type)
{
    INHERITED::disconnect(type);
    if (DisconnectType::kCleanup == type) {
        if (fHWProgramID) {
            GL_CALL(UseProgram(0));
        }
        if (fTempSrcFBOID) {
            GL_CALL(DeleteFramebuffers(1, &fTempSrcFBOID));
        }
        if (fTempDstFBOID) {
            GL_CALL(DeleteFramebuffers(1, &fTempDstFBOID));
        }
        if (fStencilClearFBOID) {
            GL_CALL(DeleteFramebuffers(1, &fStencilClearFBOID));
        }
        for (size_t i = 0; i < SK_ARRAY_COUNT(fCopyPrograms); ++i) {
            if (fCopyPrograms[i].fProgram) {
                GL_CALL(DeleteProgram(fCopyPrograms[i].fProgram));
            }
        }
        for (size_t i = 0; i < SK_ARRAY_COUNT(fMipmapPrograms); ++i) {
            if (fMipmapPrograms[i].fProgram) {
                GL_CALL(DeleteProgram(fMipmapPrograms[i].fProgram));
            }
        }
        if (fWireRectProgram.fProgram) {
            GL_CALL(DeleteProgram(fWireRectProgram.fProgram));
        }
        if (fPLSSetupProgram.fProgram) {
            GL_CALL(DeleteProgram(fPLSSetupProgram.fProgram));
        }
    } else {
        if (fProgramCache) {
            fProgramCache->abandon();
        }
    }

    delete fProgramCache;
    fProgramCache = nullptr;

=======
void GrGLGpu::contextAbandoned() {
    INHERITED::contextAbandoned();
    fProgramCache->abandon();
>>>>>>> miniblink49
    fHWProgramID = 0;
    fTempSrcFBOID = 0;
    fTempDstFBOID = 0;
    fStencilClearFBOID = 0;
<<<<<<< HEAD
    fCopyProgramArrayBuffer.reset();
    for (size_t i = 0; i < SK_ARRAY_COUNT(fCopyPrograms); ++i) {
        fCopyPrograms[i].fProgram = 0;
    }
    fMipmapProgramArrayBuffer.reset();
    for (size_t i = 0; i < SK_ARRAY_COUNT(fMipmapPrograms); ++i) {
        fMipmapPrograms[i].fProgram = 0;
    }
    fWireRectProgram.fProgram = 0;
    fWireRectArrayBuffer.reset();
    fPLSSetupProgram.fProgram = 0;
    fPLSSetupProgram.fArrayBuffer.reset();
    if (this->glCaps().shaderCaps()->pathRenderingSupport()) {
        this->glPathRendering()->disconnect(type);
=======
    fCopyProgram.fArrayBuffer = 0;
    fCopyProgram.fProgram = 0;
    if (this->glCaps().shaderCaps()->pathRenderingSupport()) {
        this->glPathRendering()->abandonGpuResources();
>>>>>>> miniblink49
    }
}

///////////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD

void GrGLGpu::onResetContext(uint32_t resetBits)
{
=======
GrPixelConfig GrGLGpu::preferredReadPixelsConfig(GrPixelConfig readConfig,
                                                 GrPixelConfig surfaceConfig) const {
    if (GR_GL_RGBA_8888_PIXEL_OPS_SLOW && kRGBA_8888_GrPixelConfig == readConfig) {
        return kBGRA_8888_GrPixelConfig;
    } else if (kMesa_GrGLDriver == this->glContext().driver() &&
               GrBytesPerPixel(readConfig) == 4 &&
               GrPixelConfigSwapRAndB(readConfig) == surfaceConfig) {
        // Mesa 3D takes a slow path on when reading back  BGRA from an RGBA surface and vice-versa.
        // Perhaps this should be guarded by some compiletime or runtime check.
        return surfaceConfig;
    } else if (readConfig == kBGRA_8888_GrPixelConfig
            && !this->glCaps().readPixelsSupported(
                this->glInterface(),
                GR_GL_BGRA,
                GR_GL_UNSIGNED_BYTE,
                surfaceConfig
            )) {
        return kRGBA_8888_GrPixelConfig;
    } else {
        return readConfig;
    }
}

GrPixelConfig GrGLGpu::preferredWritePixelsConfig(GrPixelConfig writeConfig,
                                                  GrPixelConfig surfaceConfig) const {
    if (GR_GL_RGBA_8888_PIXEL_OPS_SLOW && kRGBA_8888_GrPixelConfig == writeConfig) {
        return kBGRA_8888_GrPixelConfig;
    } else {
        return writeConfig;
    }
}

bool GrGLGpu::canWriteTexturePixels(const GrTexture* texture, GrPixelConfig srcConfig) const {
    if (kIndex_8_GrPixelConfig == srcConfig || kIndex_8_GrPixelConfig == texture->config()) {
        return false;
    }
    if (srcConfig != texture->config() && kGLES_GrGLStandard == this->glStandard()) {
        // In general ES2 requires the internal format of the texture and the format of the src
        // pixels to match. However, It may or may not be possible to upload BGRA data to a RGBA
        // texture. It depends upon which extension added BGRA. The Apple extension allows it
        // (BGRA's internal format is RGBA) while the EXT extension does not (BGRA is its own
        // internal format).
        if (this->glCaps().isConfigTexturable(kBGRA_8888_GrPixelConfig) &&
            !this->glCaps().bgraIsInternalFormat() &&
            kBGRA_8888_GrPixelConfig == srcConfig &&
            kRGBA_8888_GrPixelConfig == texture->config()) {
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }
}

bool GrGLGpu::fullReadPixelsIsFasterThanPartial() const {
    return SkToBool(GR_GL_FULL_READPIXELS_FASTER_THAN_PARTIAL);
}

void GrGLGpu::onResetContext(uint32_t resetBits) {
>>>>>>> miniblink49
    // we don't use the zb at all
    if (resetBits & kMisc_GrGLBackendState) {
        GL_CALL(Disable(GR_GL_DEPTH_TEST));
        GL_CALL(DepthMask(GR_GL_FALSE));

<<<<<<< HEAD
        fHWBufferState[kTexel_GrBufferType].invalidate();
        fHWBufferState[kDrawIndirect_GrBufferType].invalidate();
        fHWBufferState[kXferCpuToGpu_GrBufferType].invalidate();
        fHWBufferState[kXferGpuToCpu_GrBufferType].invalidate();

        fHWDrawFace = GrPipelineBuilder::kInvalid_DrawFace;
=======
        fHWDrawFace = GrPipelineBuilder::kInvalid_DrawFace;
        fHWDitherEnabled = kUnknown_TriState;
>>>>>>> miniblink49

        if (kGL_GrGLStandard == this->glStandard()) {
            // Desktop-only state that we never change
            if (!this->glCaps().isCoreProfile()) {
                GL_CALL(Disable(GR_GL_POINT_SMOOTH));
                GL_CALL(Disable(GR_GL_LINE_SMOOTH));
                GL_CALL(Disable(GR_GL_POLYGON_SMOOTH));
                GL_CALL(Disable(GR_GL_POLYGON_STIPPLE));
                GL_CALL(Disable(GR_GL_COLOR_LOGIC_OP));
                GL_CALL(Disable(GR_GL_INDEX_LOGIC_OP));
            }
            // The windows NVIDIA driver has GL_ARB_imaging in the extension string when using a
            // core profile. This seems like a bug since the core spec removes any mention of
            // GL_ARB_imaging.
            if (this->glCaps().imagingSupport() && !this->glCaps().isCoreProfile()) {
                GL_CALL(Disable(GR_GL_COLOR_TABLE));
            }
            GL_CALL(Disable(GR_GL_POLYGON_OFFSET_FILL));
            // Since ES doesn't support glPointSize at all we always use the VS to
            // set the point size
            GL_CALL(Enable(GR_GL_VERTEX_PROGRAM_POINT_SIZE));

            // We should set glPolygonMode(FRONT_AND_BACK,FILL) here, too. It isn't
            // currently part of our gl interface. There are probably others as
            // well.
        }

<<<<<<< HEAD
        if (kGLES_GrGLStandard == this->glStandard() && this->hasExtension("GL_ARM_shader_framebuffer_fetch")) {
=======
        if (kGLES_GrGLStandard == this->glStandard() &&
                this->hasExtension("GL_ARM_shader_framebuffer_fetch")) {
>>>>>>> miniblink49
            // The arm extension requires specifically enabling MSAA fetching per sample.
            // On some devices this may have a perf hit.  Also multiple render targets are disabled
            GL_CALL(Enable(GR_GL_FETCH_PER_SAMPLE_ARM));
        }
        fHWWriteToColor = kUnknown_TriState;
        // we only ever use lines in hairline mode
        GL_CALL(LineWidth(1));
<<<<<<< HEAD
        GL_CALL(Disable(GR_GL_DITHER));
=======
>>>>>>> miniblink49
    }

    if (resetBits & kMSAAEnable_GrGLBackendState) {
        fMSAAEnabled = kUnknown_TriState;

<<<<<<< HEAD
        if (this->caps()->usesMixedSamples()) {
            if (0 != this->caps()->maxRasterSamples()) {
                fHWRasterMultisampleEnabled = kUnknown_TriState;
                fHWNumRasterSamples = 0;
            }

            // The skia blend modes all use premultiplied alpha and therefore expect RGBA coverage
            // modulation. This state has no effect when not rendering to a mixed sampled target.
=======
        // In mixed samples mode coverage modulation allows the coverage to be converted to
        // "opacity", which can then be blended into the color buffer to accomplish antialiasing.
        // Enable coverage modulation suitable for premultiplied alpha colors.
        // This state has no effect when not rendering to a mixed sampled target.
        if (this->glCaps().shaderCaps()->mixedSamplesSupport()) {
>>>>>>> miniblink49
            GL_CALL(CoverageModulation(GR_GL_RGBA));
        }
    }

    fHWActiveTextureUnitIdx = -1; // invalid

    if (resetBits & kTextureBinding_GrGLBackendState) {
        for (int s = 0; s < fHWBoundTextureUniqueIDs.count(); ++s) {
            fHWBoundTextureUniqueIDs[s] = SK_InvalidUniqueID;
        }
<<<<<<< HEAD
        for (int b = 0; b < fHWBufferTextures.count(); ++b) {
            SkASSERT(this->caps()->shaderCaps()->texelBufferSupport());
            fHWBufferTextures[b].fKnownBound = false;
        }
=======
>>>>>>> miniblink49
    }

    if (resetBits & kBlend_GrGLBackendState) {
        fHWBlendState.invalidate();
    }

    if (resetBits & kView_GrGLBackendState) {
        fHWScissorSettings.invalidate();
        fHWViewport.invalidate();
    }

    if (resetBits & kStencil_GrGLBackendState) {
        fHWStencilSettings.invalidate();
        fHWStencilTestEnabled = kUnknown_TriState;
    }

    // Vertex
    if (resetBits & kVertex_GrGLBackendState) {
<<<<<<< HEAD
        fHWVertexArrayState.invalidate();
        fHWBufferState[kVertex_GrBufferType].invalidate();
        fHWBufferState[kIndex_GrBufferType].invalidate();
=======
        fHWGeometryState.invalidate();
>>>>>>> miniblink49
    }

    if (resetBits & kRenderTarget_GrGLBackendState) {
        fHWBoundRenderTargetUniqueID = SK_InvalidUniqueID;
<<<<<<< HEAD
        fHWSRGBFramebuffer = kUnknown_TriState;
=======
>>>>>>> miniblink49
    }

    if (resetBits & kPathRendering_GrGLBackendState) {
        if (this->caps()->shaderCaps()->pathRenderingSupport()) {
            this->glPathRendering()->resetContext();
        }
    }

    // we assume these values
    if (resetBits & kPixelStore_GrGLBackendState) {
        if (this->glCaps().unpackRowLengthSupport()) {
            GL_CALL(PixelStorei(GR_GL_UNPACK_ROW_LENGTH, 0));
        }
        if (this->glCaps().packRowLengthSupport()) {
            GL_CALL(PixelStorei(GR_GL_PACK_ROW_LENGTH, 0));
        }
        if (this->glCaps().unpackFlipYSupport()) {
            GL_CALL(PixelStorei(GR_GL_UNPACK_FLIP_Y, GR_GL_FALSE));
        }
        if (this->glCaps().packFlipYSupport()) {
            GL_CALL(PixelStorei(GR_GL_PACK_REVERSE_ROW_ORDER, GR_GL_FALSE));
        }
    }

    if (resetBits & kProgram_GrGLBackendState) {
        fHWProgramID = 0;
    }
}

<<<<<<< HEAD
static GrSurfaceOrigin resolve_origin(GrSurfaceOrigin origin, bool renderTarget)
{
=======
static GrSurfaceOrigin resolve_origin(GrSurfaceOrigin origin, bool renderTarget) {
>>>>>>> miniblink49
    // By default, GrRenderTargets are GL's normal orientation so that they
    // can be drawn to by the outside world without the client having
    // to render upside down.
    if (kDefault_GrSurfaceOrigin == origin) {
        return renderTarget ? kBottomLeft_GrSurfaceOrigin : kTopLeft_GrSurfaceOrigin;
    } else {
        return origin;
    }
}

GrTexture* GrGLGpu::onWrapBackendTexture(const GrBackendTextureDesc& desc,
<<<<<<< HEAD
    GrWrapOwnership ownership)
{
#ifdef SK_IGNORE_GL_TEXTURE_TARGET
    if (!desc.fTextureHandle) {
        return nullptr;
    }
#else
    const GrGLTextureInfo* info = reinterpret_cast<const GrGLTextureInfo*>(desc.fTextureHandle);
    if (!info || !info->fID) {
        return nullptr;
    }
#endif

    // next line relies on GrBackendTextureDesc's flags matching GrTexture's
    bool renderTarget = SkToBool(desc.fFlags & kRenderTarget_GrBackendTextureFlag);
=======
                                         GrWrapOwnership ownership) {
    if (!this->configToGLFormats(desc.fConfig, false, NULL, NULL, NULL)) {
        return NULL;
    }

    if (0 == desc.fTextureHandle) {
        return NULL;
    }

    int maxSize = this->caps()->maxTextureSize();
    if (desc.fWidth > maxSize || desc.fHeight > maxSize) {
        return NULL;
    }
>>>>>>> miniblink49

    GrGLTexture::IDDesc idDesc;
    GrSurfaceDesc surfDesc;

<<<<<<< HEAD
#ifdef SK_IGNORE_GL_TEXTURE_TARGET
    idDesc.fInfo.fID = static_cast<GrGLuint>(desc.fTextureHandle);
    // When we create the texture, we only
    // create GL_TEXTURE_2D at the moment.
    // External clients can do something different.

    idDesc.fInfo.fTarget = GR_GL_TEXTURE_2D;
#else
    idDesc.fInfo = *info;
#endif

    if (GR_GL_TEXTURE_EXTERNAL == idDesc.fInfo.fTarget) {
        if (renderTarget) {
            // This combination is not supported.
            return nullptr;
        }
        if (!this->glCaps().glslCaps()->externalTextureSupport()) {
            return nullptr;
        }
    } else if (GR_GL_TEXTURE_RECTANGLE == idDesc.fInfo.fTarget) {
        if (!this->glCaps().rectangleTextureSupport()) {
            return nullptr;
        }
    } else if (GR_GL_TEXTURE_2D != idDesc.fInfo.fTarget) {
        return nullptr;
    }

    // Sample count is interpreted to mean the number of samples that Gr code should allocate
    // for a render buffer that resolves to the texture. We don't support MSAA textures.
    if (desc.fSampleCnt && !renderTarget) {
        return nullptr;
    }

    if (kAdopt_GrWrapOwnership == ownership) {
        idDesc.fOwnership = GrBackendObjectOwnership::kOwned;
    } else {
        idDesc.fOwnership = GrBackendObjectOwnership::kBorrowed;
    }

    surfDesc.fFlags = (GrSurfaceFlags)desc.fFlags;
=======
    idDesc.fTextureID = static_cast<GrGLuint>(desc.fTextureHandle);
    
    switch (ownership) {
        case kAdopt_GrWrapOwnership:
            idDesc.fLifeCycle = GrGpuResource::kAdopted_LifeCycle;
            break;
        case kBorrow_GrWrapOwnership:
            idDesc.fLifeCycle = GrGpuResource::kBorrowed_LifeCycle;
            break;
    }    

    // next line relies on GrBackendTextureDesc's flags matching GrTexture's
    surfDesc.fFlags = (GrSurfaceFlags) desc.fFlags;
>>>>>>> miniblink49
    surfDesc.fWidth = desc.fWidth;
    surfDesc.fHeight = desc.fHeight;
    surfDesc.fConfig = desc.fConfig;
    surfDesc.fSampleCnt = SkTMin(desc.fSampleCnt, this->caps()->maxSampleCount());
<<<<<<< HEAD
=======
    bool renderTarget = SkToBool(desc.fFlags & kRenderTarget_GrBackendTextureFlag);
>>>>>>> miniblink49
    // FIXME:  this should be calling resolve_origin(), but Chrome code is currently
    // assuming the old behaviour, which is that backend textures are always
    // BottomLeft, even for non-RT's.  Once Chrome is fixed, change this to:
    // glTexDesc.fOrigin = resolve_origin(desc.fOrigin, renderTarget);
    if (kDefault_GrSurfaceOrigin == desc.fOrigin) {
        surfDesc.fOrigin = kBottomLeft_GrSurfaceOrigin;
    } else {
        surfDesc.fOrigin = desc.fOrigin;
    }

<<<<<<< HEAD
    GrGLTexture* texture = nullptr;
    if (renderTarget) {
        GrGLRenderTarget::IDDesc rtIDDesc;
        if (!this->createRenderTargetObjects(surfDesc, idDesc.fInfo, &rtIDDesc)) {
            return nullptr;
        }
        texture = GrGLTextureRenderTarget::CreateWrapped(this, surfDesc, idDesc, rtIDDesc);
    } else {
        texture = GrGLTexture::CreateWrapped(this, surfDesc, idDesc);
    }
    if (nullptr == texture) {
        return nullptr;
=======
    GrGLTexture* texture = NULL;
    if (renderTarget) {
        GrGLRenderTarget::IDDesc rtIDDesc;
        if (!this->createRenderTargetObjects(surfDesc, GrGpuResource::kUncached_LifeCycle,
                                             idDesc.fTextureID, &rtIDDesc)) {
            return NULL;
        }
        texture = SkNEW_ARGS(GrGLTextureRenderTarget, (this, surfDesc, idDesc, rtIDDesc));
    } else {
        texture = SkNEW_ARGS(GrGLTexture, (this, surfDesc, idDesc));
    }
    if (NULL == texture) {
        return NULL;
>>>>>>> miniblink49
    }

    return texture;
}

GrRenderTarget* GrGLGpu::onWrapBackendRenderTarget(const GrBackendRenderTargetDesc& wrapDesc,
<<<<<<< HEAD
    GrWrapOwnership ownership)
{
=======
                                                   GrWrapOwnership ownership) {
>>>>>>> miniblink49
    GrGLRenderTarget::IDDesc idDesc;
    idDesc.fRTFBOID = static_cast<GrGLuint>(wrapDesc.fRenderTargetHandle);
    idDesc.fMSColorRenderbufferID = 0;
    idDesc.fTexFBOID = GrGLRenderTarget::kUnresolvableFBOID;
<<<<<<< HEAD
    if (kAdopt_GrWrapOwnership == ownership) {
        idDesc.fRTFBOOwnership = GrBackendObjectOwnership::kOwned;
    } else {
        idDesc.fRTFBOOwnership = GrBackendObjectOwnership::kBorrowed;
    }
=======
    switch (ownership) {
        case kAdopt_GrWrapOwnership:
            idDesc.fLifeCycle = GrGpuResource::kAdopted_LifeCycle;
            break;
        case kBorrow_GrWrapOwnership:
            idDesc.fLifeCycle = GrGpuResource::kBorrowed_LifeCycle;
            break;
    }    
>>>>>>> miniblink49
    idDesc.fSampleConfig = GrRenderTarget::kUnified_SampleConfig;

    GrSurfaceDesc desc;
    desc.fConfig = wrapDesc.fConfig;
<<<<<<< HEAD
    desc.fFlags = kCheckAllocation_GrSurfaceFlag | kRenderTarget_GrSurfaceFlag;
=======
    desc.fFlags = kCheckAllocation_GrSurfaceFlag;
>>>>>>> miniblink49
    desc.fWidth = wrapDesc.fWidth;
    desc.fHeight = wrapDesc.fHeight;
    desc.fSampleCnt = SkTMin(wrapDesc.fSampleCnt, this->caps()->maxSampleCount());
    desc.fOrigin = resolve_origin(wrapDesc.fOrigin, true);

<<<<<<< HEAD
    return GrGLRenderTarget::CreateWrapped(this, desc, idDesc, wrapDesc.fStencilBits);
}

GrRenderTarget* GrGLGpu::onWrapBackendTextureAsRenderTarget(const GrBackendTextureDesc& desc)
{
#ifdef SK_IGNORE_GL_TEXTURE_TARGET
    if (!desc.fTextureHandle) {
        return nullptr;
    }
#else
    const GrGLTextureInfo* info = reinterpret_cast<const GrGLTextureInfo*>(desc.fTextureHandle);
    if (!info || !info->fID) {
        return nullptr;
    }
#endif

    GrGLTextureInfo texInfo;
    GrSurfaceDesc surfDesc;

#ifdef SK_IGNORE_GL_TEXTURE_TARGET
    texInfo.fID = static_cast<GrGLuint>(desc.fTextureHandle);
    // We only support GL_TEXTURE_2D at the moment.
    texInfo.fTarget = GR_GL_TEXTURE_2D;
#else
    texInfo = *info;
#endif

    if (GR_GL_TEXTURE_RECTANGLE != texInfo.fTarget && GR_GL_TEXTURE_2D != texInfo.fTarget) {
        // Only texture rectangle and texture 2d are supported. We do not check whether texture
        // rectangle is supported by Skia - if the caller provided us with a texture rectangle,
        // we assume the necessary support exists.
        return nullptr;
    }

    surfDesc.fFlags = (GrSurfaceFlags)desc.fFlags;
    surfDesc.fWidth = desc.fWidth;
    surfDesc.fHeight = desc.fHeight;
    surfDesc.fConfig = desc.fConfig;
    surfDesc.fSampleCnt = SkTMin(desc.fSampleCnt, this->caps()->maxSampleCount());
    // FIXME:  this should be calling resolve_origin(), but Chrome code is currently
    // assuming the old behaviour, which is that backend textures are always
    // BottomLeft, even for non-RT's.  Once Chrome is fixed, change this to:
    // glTexDesc.fOrigin = resolve_origin(desc.fOrigin, renderTarget);
    if (kDefault_GrSurfaceOrigin == desc.fOrigin) {
        surfDesc.fOrigin = kBottomLeft_GrSurfaceOrigin;
    } else {
        surfDesc.fOrigin = desc.fOrigin;
    }

    GrGLRenderTarget::IDDesc rtIDDesc;
    if (!this->createRenderTargetObjects(surfDesc, texInfo, &rtIDDesc)) {
        return nullptr;
    }
    return GrGLRenderTarget::CreateWrapped(this, surfDesc, rtIDDesc, 0);
=======
    GrRenderTarget* tgt = SkNEW_ARGS(GrGLRenderTarget, (this, desc, idDesc));
    if (wrapDesc.fStencilBits) {
        GrGLStencilAttachment::IDDesc sbDesc;
        GrGLStencilAttachment::Format format;
        format.fInternalFormat = GrGLStencilAttachment::kUnknownInternalFormat;
        format.fPacked = false;
        format.fStencilBits = wrapDesc.fStencilBits;
        format.fTotalBits = wrapDesc.fStencilBits;
        GrGLStencilAttachment* sb = SkNEW_ARGS(GrGLStencilAttachment,
                                           (this,
                                            sbDesc,
                                            desc.fWidth,
                                            desc.fHeight,
                                            desc.fSampleCnt,
                                            format));
        tgt->renderTargetPriv().didAttachStencilAttachment(sb);
        sb->unref();
    }
    return tgt;
>>>>>>> miniblink49
}

////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
bool GrGLGpu::onGetWritePixelsInfo(GrSurface* dstSurface, int width, int height,
    GrPixelConfig srcConfig,
    DrawPreference* drawPreference,
    WritePixelTempDrawInfo* tempDrawInfo)
{
    if (kIndex_8_GrPixelConfig == srcConfig || GrPixelConfigIsCompressed(dstSurface->config())) {
        return false;
    }

    // This subclass only allows writes to textures. If the dst is not a texture we have to draw
    // into it. We could use glDrawPixels on GLs that have it, but we don't today.
    if (!dstSurface->asTexture()) {
        ElevateDrawPreference(drawPreference, kRequireDraw_DrawPreference);
    } else {
        GrGLTexture* texture = static_cast<GrGLTexture*>(dstSurface->asTexture());
        if (GR_GL_TEXTURE_EXTERNAL == texture->target()) {
            // We don't currently support writing pixels to EXTERNAL textures.
            return false;
        }
    }

    if (GrPixelConfigIsSRGB(dstSurface->config()) != GrPixelConfigIsSRGB(srcConfig)) {
        ElevateDrawPreference(drawPreference, kRequireDraw_DrawPreference);
    }

    // Start off assuming no swizzling
    tempDrawInfo->fSwizzle = GrSwizzle::RGBA();
    tempDrawInfo->fWriteConfig = srcConfig;

    // These settings we will always want if a temp draw is performed. Initially set the config
    // to srcConfig, though that may be modified if we decide to do a R/G swap.
    tempDrawInfo->fTempSurfaceDesc.fFlags = kNone_GrSurfaceFlags;
    tempDrawInfo->fTempSurfaceDesc.fConfig = srcConfig;
    tempDrawInfo->fTempSurfaceDesc.fWidth = width;
    tempDrawInfo->fTempSurfaceDesc.fHeight = height;
    tempDrawInfo->fTempSurfaceDesc.fSampleCnt = 0;
    tempDrawInfo->fTempSurfaceDesc.fOrigin = kTopLeft_GrSurfaceOrigin; // no CPU y-flip for TL.

    bool configsAreRBSwaps = GrPixelConfigSwapRAndB(srcConfig) == dstSurface->config();

    if (configsAreRBSwaps) {
        if (!this->caps()->isConfigTexturable(srcConfig)) {
            ElevateDrawPreference(drawPreference, kRequireDraw_DrawPreference);
            tempDrawInfo->fTempSurfaceDesc.fConfig = dstSurface->config();
            tempDrawInfo->fSwizzle = GrSwizzle::BGRA();
            tempDrawInfo->fWriteConfig = dstSurface->config();
        } else if (this->glCaps().rgba8888PixelsOpsAreSlow() && kRGBA_8888_GrPixelConfig == srcConfig) {
            ElevateDrawPreference(drawPreference, kGpuPrefersDraw_DrawPreference);
            tempDrawInfo->fTempSurfaceDesc.fConfig = dstSurface->config();
            tempDrawInfo->fSwizzle = GrSwizzle::BGRA();
            tempDrawInfo->fWriteConfig = dstSurface->config();
        } else if (kGLES_GrGLStandard == this->glStandard() && this->glCaps().bgraIsInternalFormat()) {
            // The internal format and external formats must match texture uploads so we can't
            // swizzle while uploading when BGRA is a distinct internal format.
            ElevateDrawPreference(drawPreference, kRequireDraw_DrawPreference);
            tempDrawInfo->fTempSurfaceDesc.fConfig = dstSurface->config();
            tempDrawInfo->fSwizzle = GrSwizzle::BGRA();
            tempDrawInfo->fWriteConfig = dstSurface->config();
        }
    }

    if (!this->glCaps().unpackFlipYSupport() && kBottomLeft_GrSurfaceOrigin == dstSurface->origin()) {
        ElevateDrawPreference(drawPreference, kGpuPrefersDraw_DrawPreference);
    }

    return true;
}

static bool check_write_and_transfer_input(GrGLTexture* glTex, GrSurface* surface,
    GrPixelConfig config)
{
    if (!glTex) {
        return false;
    }

    // OpenGL doesn't do sRGB <-> linear conversions when reading and writing pixels.
    if (GrPixelConfigIsSRGB(surface->config()) != GrPixelConfigIsSRGB(config)) {
        return false;
    }

    // Write or transfer of pixels is not implemented for TEXTURE_EXTERNAL textures
    if (GR_GL_TEXTURE_EXTERNAL == glTex->target()) {
        return false;
    }

    return true;
}

bool GrGLGpu::onWritePixels(GrSurface* surface,
    int left, int top, int width, int height,
    GrPixelConfig config,
    const SkTArray<GrMipLevel>& texels)
{
    GrGLTexture* glTex = static_cast<GrGLTexture*>(surface->asTexture());

    if (!check_write_and_transfer_input(glTex, surface, config)) {
        return false;
    }

    this->setScratchTextureUnit();
    GL_CALL(BindTexture(glTex->target(), glTex->textureID()));
=======
bool GrGLGpu::onWriteTexturePixels(GrTexture* texture,
                                   int left, int top, int width, int height,
                                   GrPixelConfig config, const void* buffer,
                                   size_t rowBytes) {
    if (NULL == buffer) {
        return false;
    }
    GrGLTexture* glTex = static_cast<GrGLTexture*>(texture);

    this->setScratchTextureUnit();
    GL_CALL(BindTexture(GR_GL_TEXTURE_2D, glTex->textureID()));
>>>>>>> miniblink49

    bool success = false;
    if (GrPixelConfigIsCompressed(glTex->desc().fConfig)) {
        // We check that config == desc.fConfig in GrGLGpu::canWriteTexturePixels()
        SkASSERT(config == glTex->desc().fConfig);
<<<<<<< HEAD
        success = this->uploadCompressedTexData(glTex->desc(), glTex->target(), texels,
            kWrite_UploadType, left, top, width, height);
    } else {
        success = this->uploadTexData(glTex->desc(), glTex->target(), kWrite_UploadType,
            left, top, width, height, config, texels);
    }

    return success;
}

bool GrGLGpu::onTransferPixels(GrSurface* surface,
    int left, int top, int width, int height,
    GrPixelConfig config, GrBuffer* transferBuffer,
    size_t offset, size_t rowBytes)
{
    GrGLTexture* glTex = static_cast<GrGLTexture*>(surface->asTexture());

    if (!check_write_and_transfer_input(glTex, surface, config)) {
        return false;
    }

    // For the moment, can't transfer compressed data
    if (GrPixelConfigIsCompressed(glTex->desc().fConfig)) {
        return false;
    }

    this->setScratchTextureUnit();
    GL_CALL(BindTexture(glTex->target(), glTex->textureID()));

    SkASSERT(!transferBuffer->isMapped());
    SkASSERT(!transferBuffer->isCPUBacked());
    const GrGLBuffer* glBuffer = static_cast<const GrGLBuffer*>(transferBuffer);
    this->bindBuffer(kXferCpuToGpu_GrBufferType, glBuffer);

    bool success = false;
    GrMipLevel mipLevel;
    mipLevel.fPixels = transferBuffer;
    mipLevel.fRowBytes = rowBytes;
    SkSTArray<1, GrMipLevel> texels;
    texels.push_back(mipLevel);
    success = this->uploadTexData(glTex->desc(), glTex->target(), kTransfer_UploadType,
        left, top, width, height, config, texels);
    return success;
}

// For GL_[UN]PACK_ALIGNMENT.
static inline GrGLint config_alignment(GrPixelConfig config)
{
    SkASSERT(!GrPixelConfigIsCompressed(config));
    switch (config) {
    case kAlpha_8_GrPixelConfig:
        return 1;
    case kRGB_565_GrPixelConfig:
    case kRGBA_4444_GrPixelConfig:
    case kAlpha_half_GrPixelConfig:
    case kRGBA_half_GrPixelConfig:
        return 2;
    case kRGBA_8888_GrPixelConfig:
    case kBGRA_8888_GrPixelConfig:
    case kSRGBA_8888_GrPixelConfig:
    case kSBGRA_8888_GrPixelConfig:
    case kRGBA_float_GrPixelConfig:
        return 4;
    default:
        return 0;
    }
}

static inline GrGLenum check_alloc_error(const GrSurfaceDesc& desc,
    const GrGLInterface* interface)
{
=======
        success = this->uploadCompressedTexData(glTex->desc(), buffer, false, left, top, width,
                                                height);
    } else {
        success = this->uploadTexData(glTex->desc(), false, left, top, width, height, config,
                                      buffer, rowBytes);
    }

    if (success) {
        texture->texturePriv().dirtyMipMaps(true);
        return true;
    }

    return false;
}

static bool adjust_pixel_ops_params(int surfaceWidth,
                                    int surfaceHeight,
                                    size_t bpp,
                                    int* left, int* top, int* width, int* height,
                                    const void** data,
                                    size_t* rowBytes) {
    if (!*rowBytes) {
        *rowBytes = *width * bpp;
    }

    SkIRect subRect = SkIRect::MakeXYWH(*left, *top, *width, *height);
    SkIRect bounds = SkIRect::MakeWH(surfaceWidth, surfaceHeight);

    if (!subRect.intersect(bounds)) {
        return false;
    }
    *data = reinterpret_cast<const void*>(reinterpret_cast<intptr_t>(*data) +
          (subRect.fTop - *top) * *rowBytes + (subRect.fLeft - *left) * bpp);

    *left = subRect.fLeft;
    *top = subRect.fTop;
    *width = subRect.width();
    *height = subRect.height();
    return true;
}

static inline GrGLenum check_alloc_error(const GrSurfaceDesc& desc,
                                         const GrGLInterface* interface) {
>>>>>>> miniblink49
    if (SkToBool(desc.fFlags & kCheckAllocation_GrSurfaceFlag)) {
        return GR_GL_GET_ERROR(interface);
    } else {
        return CHECK_ALLOC_ERROR(interface);
    }
}

<<<<<<< HEAD
/**
 * Creates storage space for the texture and fills it with texels.
 *
 * @param desc           The surface descriptor for the texture being created.
 * @param interface      The GL interface in use.
 * @param caps           The capabilities of the GL device.
 * @param internalFormat The data format used for the internal storage of the texture.
 * @param externalFormat The data format used for the external storage of the texture.
 * @param externalType   The type of the data used for the external storage of the texture.
 * @param texels         The texel data of the texture being created.
 * @param baseWidth      The width of the texture's base mipmap level
 * @param baseHeight     The height of the texture's base mipmap level
 * @param succeeded      Set to true if allocating and populating the texture completed
 *                       without error.
 */
static bool allocate_and_populate_uncompressed_texture(const GrSurfaceDesc& desc,
    const GrGLInterface& interface,
    const GrGLCaps& caps,
    GrGLenum target,
    GrGLenum internalFormat,
    GrGLenum externalFormat,
    GrGLenum externalType,
    const SkTArray<GrMipLevel>& texels,
    int baseWidth, int baseHeight)
{
    CLEAR_ERROR_BEFORE_ALLOC(&interface);

    bool useTexStorage = caps.isConfigTexSupportEnabled(desc.fConfig);
    // We can only use TexStorage if we know we will not later change the storage requirements.
    // This means if we may later want to add mipmaps, we cannot use TexStorage.
    // Right now, we cannot know if we will later add mipmaps or not.
    // The only time we can use TexStorage is when we already have the
    // mipmaps.
    useTexStorage &= texels.count() > 1;

    if (useTexStorage) {
        // We never resize or change formats of textures.
        GL_ALLOC_CALL(&interface,
            TexStorage2D(target,
                texels.count(),
                internalFormat,
                desc.fWidth, desc.fHeight));
        GrGLenum error = check_alloc_error(desc, &interface);
        if (error != GR_GL_NO_ERROR) {
            return false;
        } else {
            for (int currentMipLevel = 0; currentMipLevel < texels.count(); currentMipLevel++) {
                const void* currentMipData = texels[currentMipLevel].fPixels;
                if (currentMipData == nullptr) {
                    continue;
                }
                int twoToTheMipLevel = 1 << currentMipLevel;
                int currentWidth = SkTMax(1, desc.fWidth / twoToTheMipLevel);
                int currentHeight = SkTMax(1, desc.fHeight / twoToTheMipLevel);

                GR_GL_CALL(&interface,
                    TexSubImage2D(target,
                        currentMipLevel,
                        0, // left
                        0, // top
                        currentWidth,
                        currentHeight,
                        externalFormat, externalType,
                        currentMipData));
            }
            return true;
        }
    } else {
        if (texels.empty()) {
            GL_ALLOC_CALL(&interface,
                TexImage2D(target,
                    0,
                    internalFormat,
                    baseWidth,
                    baseHeight,
                    0, // border
                    externalFormat, externalType,
                    nullptr));
            GrGLenum error = check_alloc_error(desc, &interface);
            if (error != GR_GL_NO_ERROR) {
                return false;
            }
        } else {
            for (int currentMipLevel = 0; currentMipLevel < texels.count(); currentMipLevel++) {
                int twoToTheMipLevel = 1 << currentMipLevel;
                int currentWidth = SkTMax(1, baseWidth / twoToTheMipLevel);
                int currentHeight = SkTMax(1, baseHeight / twoToTheMipLevel);
                const void* currentMipData = texels[currentMipLevel].fPixels;
                // Even if curremtMipData is nullptr, continue to call TexImage2D.
                // This will allocate texture memory which we can later populate.
                GL_ALLOC_CALL(&interface,
                    TexImage2D(target,
                        currentMipLevel,
                        internalFormat,
                        currentWidth,
                        currentHeight,
                        0, // border
                        externalFormat, externalType,
                        currentMipData));
                GrGLenum error = check_alloc_error(desc, &interface);
                if (error != GR_GL_NO_ERROR) {
                    return false;
                }
            }
        }
    }
    return true;
}

/**
 * Creates storage space for the texture and fills it with texels.
 *
 * @param desc           The surface descriptor for the texture being created.
 * @param interface      The GL interface in use.
 * @param caps           The capabilities of the GL device.
 * @param internalFormat The data format used for the internal storage of the texture.
 * @param texels         The texel data of the texture being created.
 */
static bool allocate_and_populate_compressed_texture(const GrSurfaceDesc& desc,
    const GrGLInterface& interface,
    const GrGLCaps& caps,
    GrGLenum target, GrGLenum internalFormat,
    const SkTArray<GrMipLevel>& texels,
    int baseWidth, int baseHeight)
{
    CLEAR_ERROR_BEFORE_ALLOC(&interface);

    bool useTexStorage = caps.isConfigTexSupportEnabled(desc.fConfig);
    // We can only use TexStorage if we know we will not later change the storage requirements.
    // This means if we may later want to add mipmaps, we cannot use TexStorage.
    // Right now, we cannot know if we will later add mipmaps or not.
    // The only time we can use TexStorage is when we already have the
    // mipmaps.
    useTexStorage &= texels.count() > 1;

    if (useTexStorage) {
        // We never resize or change formats of textures.
        GL_ALLOC_CALL(&interface,
            TexStorage2D(target,
                texels.count(),
                internalFormat,
                baseWidth, baseHeight));
        GrGLenum error = check_alloc_error(desc, &interface);
        if (error != GR_GL_NO_ERROR) {
            return false;
        } else {
            for (int currentMipLevel = 0; currentMipLevel < texels.count(); currentMipLevel++) {
                const void* currentMipData = texels[currentMipLevel].fPixels;
                if (currentMipData == nullptr) {
                    continue;
                }

                int twoToTheMipLevel = 1 << currentMipLevel;
                int currentWidth = SkTMax(1, baseWidth / twoToTheMipLevel);
                int currentHeight = SkTMax(1, baseHeight / twoToTheMipLevel);

                // Make sure that the width and height that we pass to OpenGL
                // is a multiple of the block size.
                size_t dataSize = GrCompressedFormatDataSize(desc.fConfig, currentWidth,
                    currentHeight);
                GR_GL_CALL(&interface, CompressedTexSubImage2D(target, currentMipLevel,
                                           0, // left
                                           0, // top
                                           currentWidth, currentHeight, internalFormat, SkToInt(dataSize), currentMipData));
            }
        }
    } else {
        for (int currentMipLevel = 0; currentMipLevel < texels.count(); currentMipLevel++) {
            int twoToTheMipLevel = 1 << currentMipLevel;
            int currentWidth = SkTMax(1, baseWidth / twoToTheMipLevel);
            int currentHeight = SkTMax(1, baseHeight / twoToTheMipLevel);

            // Make sure that the width and height that we pass to OpenGL
            // is a multiple of the block size.
            size_t dataSize = GrCompressedFormatDataSize(desc.fConfig, baseWidth, baseHeight);

            GL_ALLOC_CALL(&interface,
                CompressedTexImage2D(target,
                    currentMipLevel,
                    internalFormat,
                    currentWidth,
                    currentHeight,
                    0, // border
                    SkToInt(dataSize),
                    texels[currentMipLevel].fPixels));

            GrGLenum error = check_alloc_error(desc, &interface);
            if (error != GR_GL_NO_ERROR) {
                return false;
            }
        }
    }

    return true;
}

/**
 * After a texture is created, any state which was altered during its creation
 * needs to be restored.
 *
 * @param interface          The GL interface to use.
 * @param caps               The capabilities of the GL device.
 * @param restoreGLRowLength Should the row length unpacking be restored?
 * @param glFlipY            Did GL flip the texture vertically?
 */
static void restore_pixelstore_state(const GrGLInterface& interface, const GrGLCaps& caps,
    bool restoreGLRowLength, bool glFlipY)
{
    if (restoreGLRowLength) {
        SkASSERT(caps.unpackRowLengthSupport());
        GR_GL_CALL(&interface, PixelStorei(GR_GL_UNPACK_ROW_LENGTH, 0));
    }
    if (glFlipY) {
        GR_GL_CALL(&interface, PixelStorei(GR_GL_UNPACK_FLIP_Y, GR_GL_FALSE));
    }
}

bool GrGLGpu::uploadTexData(const GrSurfaceDesc& desc,
    GrGLenum target,
    UploadType uploadType,
    int left, int top, int width, int height,
    GrPixelConfig dataConfig,
    const SkTArray<GrMipLevel>& texels)
{
    // If we're uploading compressed data then we should be using uploadCompressedTexData
    SkASSERT(!GrPixelConfigIsCompressed(dataConfig));

    SkASSERT(this->caps()->isConfigTexturable(desc.fConfig));

    // texels is const.
    // But we may need to flip the texture vertically to prepare it.
    // Rather than flip in place and alter the incoming data,
    // we allocate a new buffer to flip into.
    // This means we need to make a non-const shallow copy of texels.
    SkTArray<GrMipLevel> texelsShallowCopy(texels);

    for (int currentMipLevel = texelsShallowCopy.count() - 1; currentMipLevel >= 0;
         currentMipLevel--) {
        SkASSERT(texelsShallowCopy[currentMipLevel].fPixels || kTransfer_UploadType == uploadType);
    }

    const GrGLInterface* interface = this->glInterface();
    const GrGLCaps& caps = this->glCaps();

    size_t bpp = GrBytesPerPixel(dataConfig);

    if (width == 0 || height == 0) {
        return false;
    }

    for (int currentMipLevel = 0; currentMipLevel < texelsShallowCopy.count(); currentMipLevel++) {
        int twoToTheMipLevel = 1 << currentMipLevel;
        int currentWidth = SkTMax(1, width / twoToTheMipLevel);
        int currentHeight = SkTMax(1, height / twoToTheMipLevel);

        if (currentHeight > SK_MaxS32 || currentWidth > SK_MaxS32) {
            return false;
        }
        if (!GrSurfacePriv::AdjustWritePixelParams(desc.fWidth, desc.fHeight, bpp, &left, &top,
                &currentWidth,
                &currentHeight,
                &texelsShallowCopy[currentMipLevel].fPixels,
                &texelsShallowCopy[currentMipLevel].fRowBytes)) {
            return false;
        }
        if (currentWidth < 0 || currentHeight < 0) {
            return false;
        }
    }

    // Internal format comes from the texture desc.
    GrGLenum internalFormat;
    // External format and type come from the upload data.
    GrGLenum externalFormat;
    GrGLenum externalType;
    if (!this->glCaps().getTexImageFormats(desc.fConfig, dataConfig, &internalFormat,
            &externalFormat, &externalType)) {
        return false;
    }
    /*
     *  Check whether to allocate a temporary buffer for flipping y or
=======
bool GrGLGpu::uploadTexData(const GrSurfaceDesc& desc,
                            bool isNewTexture,
                            int left, int top, int width, int height,
                            GrPixelConfig dataConfig,
                            const void* data,
                            size_t rowBytes) {
    SkASSERT(data || isNewTexture);

    // If we're uploading compressed data then we should be using uploadCompressedTexData
    SkASSERT(!GrPixelConfigIsCompressed(dataConfig));

    size_t bpp = GrBytesPerPixel(dataConfig);
    if (!adjust_pixel_ops_params(desc.fWidth, desc.fHeight, bpp, &left, &top,
                                 &width, &height, &data, &rowBytes)) {
        return false;
    }
    size_t trimRowBytes = width * bpp;

    // in case we need a temporary, trimmed copy of the src pixels
    SkAutoSMalloc<128 * 128> tempStorage;

    // We currently lazily create MIPMAPs when the we see a draw with
    // GrTextureParams::kMipMap_FilterMode. Using texture storage requires that the
    // MIP levels are all created when the texture is created. So for now we don't use
    // texture storage.
    bool useTexStorage = false &&
                         isNewTexture &&
                         this->glCaps().texStorageSupport();

    if (useTexStorage && kGL_GrGLStandard == this->glStandard()) {
        // 565 is not a sized internal format on desktop GL. So on desktop with
        // 565 we always use an unsized internal format to let the system pick
        // the best sized format to convert the 565 data to. Since TexStorage
        // only allows sized internal formats we will instead use TexImage2D.
        useTexStorage = desc.fConfig != kRGB_565_GrPixelConfig;
    }

    GrGLenum internalFormat = 0x0; // suppress warning
    GrGLenum externalFormat = 0x0; // suppress warning
    GrGLenum externalType = 0x0;   // suppress warning

    // glTexStorage requires sized internal formats on both desktop and ES. ES2 requires an unsized
    // format for glTexImage, unlike ES3 and desktop.
    bool useSizedFormat = useTexStorage;
    if (kGL_GrGLStandard == this->glStandard() ||
        (this->glVersion() >= GR_GL_VER(3, 0) &&
         // ES3 only works with sized BGRA8 format if "GL_APPLE_texture_format_BGRA8888" enabled
         (kBGRA_8888_GrPixelConfig != dataConfig || !this->glCaps().bgraIsInternalFormat())))  {
        useSizedFormat = true;
    }

    if (!this->configToGLFormats(dataConfig, useSizedFormat, &internalFormat,
                                 &externalFormat, &externalType)) {
        return false;
    }

    /*
     *  check whether to allocate a temporary buffer for flipping y or
>>>>>>> miniblink49
     *  because our srcData has extra bytes past each row. If so, we need
     *  to trim those off here, since GL ES may not let us specify
     *  GL_UNPACK_ROW_LENGTH.
     */
    bool restoreGLRowLength = false;
    bool swFlipY = false;
    bool glFlipY = false;
<<<<<<< HEAD

    if (kBottomLeft_GrSurfaceOrigin == desc.fOrigin && !texelsShallowCopy.empty()) {
        if (caps.unpackFlipYSupport()) {
            glFlipY = true;
        } else {
            swFlipY = true;
        }
    }

    // in case we need a temporary, trimmed copy of the src pixels
    SkAutoSMalloc<128 * 128> tempStorage;

    // find the combined size of all the mip levels and the relative offset of
    // each into the collective buffer
    size_t combined_buffer_size = 0;
    SkTArray<size_t> individual_mip_offsets(texelsShallowCopy.count());
    for (int currentMipLevel = 0; currentMipLevel < texelsShallowCopy.count(); currentMipLevel++) {
        int twoToTheMipLevel = 1 << currentMipLevel;
        int currentWidth = SkTMax(1, width / twoToTheMipLevel);
        int currentHeight = SkTMax(1, height / twoToTheMipLevel);
        const size_t trimmedSize = currentWidth * bpp * currentHeight;
        individual_mip_offsets.push_back(combined_buffer_size);
        combined_buffer_size += trimmedSize;
    }
    char* buffer = (char*)tempStorage.reset(combined_buffer_size);

    for (int currentMipLevel = 0; currentMipLevel < texelsShallowCopy.count(); currentMipLevel++) {
        int twoToTheMipLevel = 1 << currentMipLevel;
        int currentWidth = SkTMax(1, width / twoToTheMipLevel);
        int currentHeight = SkTMax(1, height / twoToTheMipLevel);
        const size_t trimRowBytes = currentWidth * bpp;

        /*
         *  check whether to allocate a temporary buffer for flipping y or
         *  because our srcData has extra bytes past each row. If so, we need
         *  to trim those off here, since GL ES may not let us specify
         *  GL_UNPACK_ROW_LENGTH.
         */
        restoreGLRowLength = false;

        const size_t rowBytes = texelsShallowCopy[currentMipLevel].fRowBytes;

        // TODO: This optimization should be enabled with or without mips.
        // For use with mips, we must set GR_GL_UNPACK_ROW_LENGTH once per
        // mip level, before calling glTexImage2D.
        const bool usesMips = texelsShallowCopy.count() > 1;
        if (caps.unpackRowLengthSupport() && !swFlipY && !usesMips) {
            // can't use this for flipping, only non-neg values allowed. :(
            if (rowBytes != trimRowBytes) {
                GrGLint rowLength = static_cast<GrGLint>(rowBytes / bpp);
                GR_GL_CALL(interface, PixelStorei(GR_GL_UNPACK_ROW_LENGTH, rowLength));
                restoreGLRowLength = true;
            }
        } else if (kTransfer_UploadType != uploadType) {
            if (trimRowBytes != rowBytes || swFlipY) {
                // copy data into our new storage, skipping the trailing bytes
                const char* src = (const char*)texelsShallowCopy[currentMipLevel].fPixels;
                if (swFlipY && currentHeight >= 1) {
                    src += (currentHeight - 1) * rowBytes;
                }
                char* dst = buffer + individual_mip_offsets[currentMipLevel];
                for (int y = 0; y < currentHeight; y++) {
=======
    if (data) {
        if (kBottomLeft_GrSurfaceOrigin == desc.fOrigin) {
            if (this->glCaps().unpackFlipYSupport()) {
                glFlipY = true;
            } else {
                swFlipY = true;
            }
        }
        if (this->glCaps().unpackRowLengthSupport() && !swFlipY) {
            // can't use this for flipping, only non-neg values allowed. :(
            if (rowBytes != trimRowBytes) {
                GrGLint rowLength = static_cast<GrGLint>(rowBytes / bpp);
                GL_CALL(PixelStorei(GR_GL_UNPACK_ROW_LENGTH, rowLength));
                restoreGLRowLength = true;
            }
        } else {
            if (trimRowBytes != rowBytes || swFlipY) {
                // copy data into our new storage, skipping the trailing bytes
                size_t trimSize = height * trimRowBytes;
                const char* src = (const char*)data;
                if (swFlipY) {
                    src += (height - 1) * rowBytes;
                }
                char* dst = (char*)tempStorage.reset(trimSize);
                for (int y = 0; y < height; y++) {
>>>>>>> miniblink49
                    memcpy(dst, src, trimRowBytes);
                    if (swFlipY) {
                        src -= rowBytes;
                    } else {
                        src += rowBytes;
                    }
                    dst += trimRowBytes;
                }
                // now point data to our copied version
<<<<<<< HEAD
                texelsShallowCopy[currentMipLevel].fPixels = buffer + individual_mip_offsets[currentMipLevel];
                texelsShallowCopy[currentMipLevel].fRowBytes = trimRowBytes;
            }
        } else {
            return false;
        }
    }

    if (!texelsShallowCopy.empty()) {
        if (glFlipY) {
            GR_GL_CALL(interface, PixelStorei(GR_GL_UNPACK_FLIP_Y, GR_GL_TRUE));
        }
        GR_GL_CALL(interface, PixelStorei(GR_GL_UNPACK_ALIGNMENT, config_alignment(desc.fConfig)));
    }

    bool succeeded = true;
    if (kNewTexture_UploadType == uploadType && 0 == left && 0 == top && desc.fWidth == width && desc.fHeight == height) {
        succeeded = allocate_and_populate_uncompressed_texture(desc, *interface, caps, target,
            internalFormat, externalFormat,
            externalType, texelsShallowCopy,
            width, height);
=======
                data = tempStorage.get();
            }
        }
        if (glFlipY) {
            GL_CALL(PixelStorei(GR_GL_UNPACK_FLIP_Y, GR_GL_TRUE));
        }
        GL_CALL(PixelStorei(GR_GL_UNPACK_ALIGNMENT,
              static_cast<GrGLint>(GrUnpackAlignment(dataConfig))));
    }
    bool succeeded = true;
    if (isNewTexture &&
        0 == left && 0 == top &&
        desc.fWidth == width && desc.fHeight == height) {
        CLEAR_ERROR_BEFORE_ALLOC(this->glInterface());
        if (useTexStorage) {
            // We never resize  or change formats of textures.
            GL_ALLOC_CALL(this->glInterface(),
                          TexStorage2D(GR_GL_TEXTURE_2D,
                                       1, // levels
                                       internalFormat,
                                       desc.fWidth, desc.fHeight));
        } else {
            GL_ALLOC_CALL(this->glInterface(),
                          TexImage2D(GR_GL_TEXTURE_2D,
                                     0, // level
                                     internalFormat,
                                     desc.fWidth, desc.fHeight,
                                     0, // border
                                     externalFormat, externalType,
                                     data));
        }
        GrGLenum error = check_alloc_error(desc, this->glInterface());
        if (error != GR_GL_NO_ERROR) {
            succeeded = false;
        } else {
            // if we have data and we used TexStorage to create the texture, we
            // now upload with TexSubImage.
            if (data && useTexStorage) {
                GL_CALL(TexSubImage2D(GR_GL_TEXTURE_2D,
                                      0, // level
                                      left, top,
                                      width, height,
                                      externalFormat, externalType,
                                      data));
            }
        }
>>>>>>> miniblink49
    } else {
        if (swFlipY || glFlipY) {
            top = desc.fHeight - (top + height);
        }
<<<<<<< HEAD
        for (int currentMipLevel = 0; currentMipLevel < texelsShallowCopy.count();
             currentMipLevel++) {
            int twoToTheMipLevel = 1 << currentMipLevel;
            int currentWidth = SkTMax(1, width / twoToTheMipLevel);
            int currentHeight = SkTMax(1, height / twoToTheMipLevel);

            GL_CALL(TexSubImage2D(target,
                currentMipLevel,
                left, top,
                currentWidth,
                currentHeight,
                externalFormat, externalType,
                texelsShallowCopy[currentMipLevel].fPixels));
        }
    }

    restore_pixelstore_state(*interface, caps, restoreGLRowLength, glFlipY);

=======
        GL_CALL(TexSubImage2D(GR_GL_TEXTURE_2D,
                              0, // level
                              left, top,
                              width, height,
                              externalFormat, externalType, data));
    }

    if (restoreGLRowLength) {
        SkASSERT(this->glCaps().unpackRowLengthSupport());
        GL_CALL(PixelStorei(GR_GL_UNPACK_ROW_LENGTH, 0));
    }
    if (glFlipY) {
        GL_CALL(PixelStorei(GR_GL_UNPACK_FLIP_Y, GR_GL_FALSE));
    }
>>>>>>> miniblink49
    return succeeded;
}

// TODO: This function is using a lot of wonky semantics like, if width == -1
// then set width = desc.fWdith ... blah. A better way to do it might be to
// create a CompressedTexData struct that takes a desc/ptr and figures out
// the proper upload semantics. Then users can construct this function how they
// see fit if they want to go against the "standard" way to do it.
bool GrGLGpu::uploadCompressedTexData(const GrSurfaceDesc& desc,
<<<<<<< HEAD
    GrGLenum target,
    const SkTArray<GrMipLevel>& texels,
    UploadType uploadType,
    int left, int top, int width, int height)
{
    SkASSERT(this->caps()->isConfigTexturable(desc.fConfig));
=======
                                      const void* data,
                                      bool isNewTexture,
                                      int left, int top, int width, int height) {
    SkASSERT(data || isNewTexture);
>>>>>>> miniblink49

    // No support for software flip y, yet...
    SkASSERT(kBottomLeft_GrSurfaceOrigin != desc.fOrigin);

<<<<<<< HEAD
    const GrGLInterface* interface = this->glInterface();
    const GrGLCaps& caps = this->glCaps();

=======
>>>>>>> miniblink49
    if (-1 == width) {
        width = desc.fWidth;
    }
#ifdef SK_DEBUG
    else {
        SkASSERT(width <= desc.fWidth);
    }
#endif

    if (-1 == height) {
        height = desc.fHeight;
    }
#ifdef SK_DEBUG
    else {
        SkASSERT(height <= desc.fHeight);
    }
#endif

<<<<<<< HEAD
    // We only need the internal format for compressed 2D textures.
    GrGLenum internalFormat;
    if (!caps.getCompressedTexImageFormats(desc.fConfig, &internalFormat)) {
        return false;
    }

    if (kNewTexture_UploadType == uploadType) {
        return allocate_and_populate_compressed_texture(desc, *interface, caps, target,
            internalFormat, texels, width, height);
=======
    // Make sure that the width and height that we pass to OpenGL
    // is a multiple of the block size.
    size_t dataSize = GrCompressedFormatDataSize(desc.fConfig, width, height);

    // We only need the internal format for compressed 2D textures.
    GrGLenum internalFormat = 0;
    if (!this->configToGLFormats(desc.fConfig, false, &internalFormat, NULL, NULL)) {
        return false;
    }

    if (isNewTexture) {
        CLEAR_ERROR_BEFORE_ALLOC(this->glInterface());
        GL_ALLOC_CALL(this->glInterface(),
                      CompressedTexImage2D(GR_GL_TEXTURE_2D,
                                           0, // level
                                           internalFormat,
                                           width, height,
                                           0, // border
                                           SkToInt(dataSize),
                                           data));
        GrGLenum error = check_alloc_error(desc, this->glInterface());
        if (error != GR_GL_NO_ERROR) {
            return false;
        }
>>>>>>> miniblink49
    } else {
        // Paletted textures can't be updated.
        if (GR_GL_PALETTE8_RGBA8 == internalFormat) {
            return false;
        }
<<<<<<< HEAD
        for (int currentMipLevel = 0; currentMipLevel < texels.count(); currentMipLevel++) {
            SkASSERT(texels[currentMipLevel].fPixels || kTransfer_UploadType == uploadType);

            int twoToTheMipLevel = 1 << currentMipLevel;
            int currentWidth = SkTMax(1, width / twoToTheMipLevel);
            int currentHeight = SkTMax(1, height / twoToTheMipLevel);

            // Make sure that the width and height that we pass to OpenGL
            // is a multiple of the block size.
            size_t dataSize = GrCompressedFormatDataSize(desc.fConfig, currentWidth,
                currentHeight);
            GL_CALL(CompressedTexSubImage2D(target,
                currentMipLevel,
                left, top,
                currentWidth,
                currentHeight,
                internalFormat,
                SkToInt(dataSize),
                texels[currentMipLevel].fPixels));
        }
=======
        GL_CALL(CompressedTexSubImage2D(GR_GL_TEXTURE_2D,
                                        0, // level
                                        left, top,
                                        width, height,
                                        internalFormat,
                                        SkToInt(dataSize),
                                        data));
>>>>>>> miniblink49
    }

    return true;
}

static bool renderbuffer_storage_msaa(const GrGLContext& ctx,
<<<<<<< HEAD
    int sampleCount,
    GrGLenum format,
    int width, int height)
{
    CLEAR_ERROR_BEFORE_ALLOC(ctx.interface());
    SkASSERT(GrGLCaps::kNone_MSFBOType != ctx.caps()->msFBOType());
    switch (ctx.caps()->msFBOType()) {
    case GrGLCaps::kDesktop_ARB_MSFBOType:
    case GrGLCaps::kDesktop_EXT_MSFBOType:
    case GrGLCaps::kMixedSamples_MSFBOType:
    case GrGLCaps::kES_3_0_MSFBOType:
        GL_ALLOC_CALL(ctx.interface(),
            RenderbufferStorageMultisample(GR_GL_RENDERBUFFER,
                sampleCount,
                format,
                width, height));
        break;
    case GrGLCaps::kES_Apple_MSFBOType:
        GL_ALLOC_CALL(ctx.interface(),
            RenderbufferStorageMultisampleES2APPLE(GR_GL_RENDERBUFFER,
                sampleCount,
                format,
                width, height));
        break;
    case GrGLCaps::kES_EXT_MsToTexture_MSFBOType:
    case GrGLCaps::kES_IMG_MsToTexture_MSFBOType:
        GL_ALLOC_CALL(ctx.interface(),
            RenderbufferStorageMultisampleES2EXT(GR_GL_RENDERBUFFER,
                sampleCount,
                format,
                width, height));
        break;
    case GrGLCaps::kNone_MSFBOType:
        SkFAIL("Shouldn't be here if we don't support multisampled renderbuffers.");
        break;
=======
                                      int sampleCount,
                                      GrGLenum format,
                                      int width, int height) {
    CLEAR_ERROR_BEFORE_ALLOC(ctx.interface());
    SkASSERT(GrGLCaps::kNone_MSFBOType != ctx.caps()->msFBOType());
    switch (ctx.caps()->msFBOType()) {
        case GrGLCaps::kDesktop_ARB_MSFBOType:
        case GrGLCaps::kDesktop_EXT_MSFBOType:
        case GrGLCaps::kMixedSamples_MSFBOType:
        case GrGLCaps::kES_3_0_MSFBOType:
            GL_ALLOC_CALL(ctx.interface(),
                            RenderbufferStorageMultisample(GR_GL_RENDERBUFFER,
                                                            sampleCount,
                                                            format,
                                                            width, height));
            break;
        case GrGLCaps::kES_Apple_MSFBOType:
            GL_ALLOC_CALL(ctx.interface(),
                            RenderbufferStorageMultisampleES2APPLE(GR_GL_RENDERBUFFER,
                                                                    sampleCount,
                                                                    format,
                                                                    width, height));
            break;
        case GrGLCaps::kES_EXT_MsToTexture_MSFBOType:
        case GrGLCaps::kES_IMG_MsToTexture_MSFBOType:
            GL_ALLOC_CALL(ctx.interface(),
                            RenderbufferStorageMultisampleES2EXT(GR_GL_RENDERBUFFER,
                                                                sampleCount,
                                                                format,
                                                                width, height));
            break;
        case GrGLCaps::kNone_MSFBOType:
            SkFAIL("Shouldn't be here if we don't support multisampled renderbuffers.");
            break;
>>>>>>> miniblink49
    }
    return (GR_GL_NO_ERROR == CHECK_ALLOC_ERROR(ctx.interface()));
}

bool GrGLGpu::createRenderTargetObjects(const GrSurfaceDesc& desc,
<<<<<<< HEAD
    const GrGLTextureInfo& texInfo,
    GrGLRenderTarget::IDDesc* idDesc)
{
    idDesc->fMSColorRenderbufferID = 0;
    idDesc->fRTFBOID = 0;
    idDesc->fRTFBOOwnership = GrBackendObjectOwnership::kOwned;
    idDesc->fTexFBOID = 0;
    SkASSERT((GrGLCaps::kMixedSamples_MSFBOType == this->glCaps().msFBOType()) == this->caps()->usesMixedSamples());
    idDesc->fSampleConfig = GrRenderTarget::ComputeSampleConfig(*this->caps(), desc.fSampleCnt);

    GrGLenum status;

    GrGLenum colorRenderbufferFormat = 0; // suppress warning
=======
                                        GrGpuResource::LifeCycle lifeCycle,
                                        GrGLuint texID,
                                        GrGLRenderTarget::IDDesc* idDesc) {
    idDesc->fMSColorRenderbufferID = 0;
    idDesc->fRTFBOID = 0;
    idDesc->fTexFBOID = 0;
    idDesc->fLifeCycle = lifeCycle;
    idDesc->fSampleConfig = (GrGLCaps::kMixedSamples_MSFBOType == this->glCaps().msFBOType() &&
                            desc.fSampleCnt > 0) ? GrRenderTarget::kStencil_SampleConfig :
                                                   GrRenderTarget::kUnified_SampleConfig;

    GrGLenum status;

    GrGLenum msColorFormat = 0; // suppress warning
>>>>>>> miniblink49

    if (desc.fSampleCnt > 0 && GrGLCaps::kNone_MSFBOType == this->glCaps().msFBOType()) {
        goto FAILED;
    }

    GL_CALL(GenFramebuffers(1, &idDesc->fTexFBOID));
    if (!idDesc->fTexFBOID) {
        goto FAILED;
    }

<<<<<<< HEAD
=======

>>>>>>> miniblink49
    // If we are using multisampling we will create two FBOS. We render to one and then resolve to
    // the texture bound to the other. The exception is the IMG multisample extension. With this
    // extension the texture is multisampled when rendered to and then auto-resolves it when it is
    // rendered from.
    if (desc.fSampleCnt > 0 && this->glCaps().usesMSAARenderBuffers()) {
        GL_CALL(GenFramebuffers(1, &idDesc->fRTFBOID));
        GL_CALL(GenRenderbuffers(1, &idDesc->fMSColorRenderbufferID));
<<<<<<< HEAD
        if (!idDesc->fRTFBOID || !idDesc->fMSColorRenderbufferID) {
            goto FAILED;
        }
        if (!this->glCaps().getRenderbufferFormat(desc.fConfig, &colorRenderbufferFormat)) {
            return false;
        }
=======
        if (!idDesc->fRTFBOID ||
            !idDesc->fMSColorRenderbufferID ||
            !this->configToGLFormats(desc.fConfig,
                                     // ES2 and ES3 require sized internal formats for rb storage.
                                     kGLES_GrGLStandard == this->glStandard(),
                                     &msColorFormat,
                                     NULL,
                                     NULL)) {
            goto FAILED;
        }
>>>>>>> miniblink49
    } else {
        idDesc->fRTFBOID = idDesc->fTexFBOID;
    }

    // below here we may bind the FBO
    fHWBoundRenderTargetUniqueID = SK_InvalidUniqueID;
    if (idDesc->fRTFBOID != idDesc->fTexFBOID) {
        SkASSERT(desc.fSampleCnt > 0);
        GL_CALL(BindRenderbuffer(GR_GL_RENDERBUFFER, idDesc->fMSColorRenderbufferID));
        if (!renderbuffer_storage_msaa(*fGLContext,
<<<<<<< HEAD
                desc.fSampleCnt,
                colorRenderbufferFormat,
                desc.fWidth, desc.fHeight)) {
=======
                                       desc.fSampleCnt,
                                       msColorFormat,
                                       desc.fWidth, desc.fHeight)) {
>>>>>>> miniblink49
            goto FAILED;
        }
        fStats.incRenderTargetBinds();
        GL_CALL(BindFramebuffer(GR_GL_FRAMEBUFFER, idDesc->fRTFBOID));
        GL_CALL(FramebufferRenderbuffer(GR_GL_FRAMEBUFFER,
<<<<<<< HEAD
            GR_GL_COLOR_ATTACHMENT0,
            GR_GL_RENDERBUFFER,
            idDesc->fMSColorRenderbufferID));
        if ((desc.fFlags & kCheckAllocation_GrSurfaceFlag) || !this->glCaps().isConfigVerifiedColorAttachment(desc.fConfig)) {
=======
                                      GR_GL_COLOR_ATTACHMENT0,
                                      GR_GL_RENDERBUFFER,
                                      idDesc->fMSColorRenderbufferID));
        if ((desc.fFlags & kCheckAllocation_GrSurfaceFlag) ||
            !this->glCaps().isConfigVerifiedColorAttachment(desc.fConfig)) {
>>>>>>> miniblink49
            GL_CALL_RET(status, CheckFramebufferStatus(GR_GL_FRAMEBUFFER));
            if (status != GR_GL_FRAMEBUFFER_COMPLETE) {
                goto FAILED;
            }
            fGLContext->caps()->markConfigAsValidColorAttachment(desc.fConfig);
        }
    }
    fStats.incRenderTargetBinds();
    GL_CALL(BindFramebuffer(GR_GL_FRAMEBUFFER, idDesc->fTexFBOID));

    if (this->glCaps().usesImplicitMSAAResolve() && desc.fSampleCnt > 0) {
        GL_CALL(FramebufferTexture2DMultisample(GR_GL_FRAMEBUFFER,
<<<<<<< HEAD
            GR_GL_COLOR_ATTACHMENT0,
            texInfo.fTarget,
            texInfo.fID, 0, desc.fSampleCnt));
    } else {
        GL_CALL(FramebufferTexture2D(GR_GL_FRAMEBUFFER,
            GR_GL_COLOR_ATTACHMENT0,
            texInfo.fTarget,
            texInfo.fID, 0));
    }
    if ((desc.fFlags & kCheckAllocation_GrSurfaceFlag) || !this->glCaps().isConfigVerifiedColorAttachment(desc.fConfig)) {
=======
                                                GR_GL_COLOR_ATTACHMENT0,
                                                GR_GL_TEXTURE_2D,
                                                texID, 0, desc.fSampleCnt));
    } else {
        GL_CALL(FramebufferTexture2D(GR_GL_FRAMEBUFFER,
                                     GR_GL_COLOR_ATTACHMENT0,
                                     GR_GL_TEXTURE_2D,
                                     texID, 0));
    }
    if ((desc.fFlags & kCheckAllocation_GrSurfaceFlag) ||
        !this->glCaps().isConfigVerifiedColorAttachment(desc.fConfig)) {
>>>>>>> miniblink49
        GL_CALL_RET(status, CheckFramebufferStatus(GR_GL_FRAMEBUFFER));
        if (status != GR_GL_FRAMEBUFFER_COMPLETE) {
            goto FAILED;
        }
        fGLContext->caps()->markConfigAsValidColorAttachment(desc.fConfig);
    }

    return true;

FAILED:
    if (idDesc->fMSColorRenderbufferID) {
        GL_CALL(DeleteRenderbuffers(1, &idDesc->fMSColorRenderbufferID));
    }
    if (idDesc->fRTFBOID != idDesc->fTexFBOID) {
        GL_CALL(DeleteFramebuffers(1, &idDesc->fRTFBOID));
    }
    if (idDesc->fTexFBOID) {
        GL_CALL(DeleteFramebuffers(1, &idDesc->fTexFBOID));
    }
    return false;
}

// good to set a break-point here to know when createTexture fails
<<<<<<< HEAD
static GrTexture* return_null_texture()
{
    //    SkDEBUGFAIL("null texture");
    return nullptr;
=======
static GrTexture* return_null_texture() {
//    SkDEBUGFAIL("null texture");
    return NULL;
>>>>>>> miniblink49
}

#if 0 && defined(SK_DEBUG)
static size_t as_size_t(int x) {
    return x;
}
#endif

<<<<<<< HEAD
static GrGLTexture::IDDesc generate_gl_texture(const GrGLInterface* interface)
{
    GrGLTexture::IDDesc idDesc;
    idDesc.fInfo.fID = 0;
    GR_GL_CALL(interface, GenTextures(1, &idDesc.fInfo.fID));
    idDesc.fOwnership = GrBackendObjectOwnership::kOwned;
    // When we create the texture, we only
    // create GL_TEXTURE_2D at the moment.
    // External clients can do something different.
    idDesc.fInfo.fTarget = GR_GL_TEXTURE_2D;
    return idDesc;
}

static void set_initial_texture_params(const GrGLInterface* interface,
    const GrGLTextureInfo& info,
    GrGLTexture::TexParams* initialTexParams)
{
    // Some drivers like to know filter/wrap before seeing glTexImage2D. Some
    // drivers have a bug where an FBO won't be complete if it includes a
    // texture that is not mipmap complete (considering the filter in use).
    // we only set a subset here so invalidate first
    initialTexParams->invalidate();
    initialTexParams->fMinFilter = GR_GL_NEAREST;
    initialTexParams->fMagFilter = GR_GL_NEAREST;
    initialTexParams->fWrapS = GR_GL_CLAMP_TO_EDGE;
    initialTexParams->fWrapT = GR_GL_CLAMP_TO_EDGE;
    GR_GL_CALL(interface, TexParameteri(info.fTarget, GR_GL_TEXTURE_MAG_FILTER, initialTexParams->fMagFilter));
    GR_GL_CALL(interface, TexParameteri(info.fTarget, GR_GL_TEXTURE_MIN_FILTER, initialTexParams->fMinFilter));
    GR_GL_CALL(interface, TexParameteri(info.fTarget, GR_GL_TEXTURE_WRAP_S, initialTexParams->fWrapS));
    GR_GL_CALL(interface, TexParameteri(info.fTarget, GR_GL_TEXTURE_WRAP_T, initialTexParams->fWrapT));
}

GrTexture* GrGLGpu::onCreateTexture(const GrSurfaceDesc& desc,
    SkBudgeted budgeted,
    const SkTArray<GrMipLevel>& texels)
{
=======
GrTexture* GrGLGpu::onCreateTexture(const GrSurfaceDesc& desc,
                                    GrGpuResource::LifeCycle lifeCycle,
                                    const void* srcData, size_t rowBytes) {
>>>>>>> miniblink49
    // We fail if the MSAA was requested and is not available.
    if (GrGLCaps::kNone_MSFBOType == this->glCaps().msFBOType() && desc.fSampleCnt) {
        //SkDebugf("MSAA RT requested but not supported on this platform.");
        return return_null_texture();
    }

    bool renderTarget = SkToBool(desc.fFlags & kRenderTarget_GrSurfaceFlag);

    GrGLTexture::IDDesc idDesc;
<<<<<<< HEAD
    idDesc.fOwnership = GrBackendObjectOwnership::kOwned;
    GrGLTexture::TexParams initialTexParams;
    if (!this->createTextureImpl(desc, &idDesc.fInfo, renderTarget, &initialTexParams, texels)) {
=======
    GL_CALL(GenTextures(1, &idDesc.fTextureID));
    idDesc.fLifeCycle = lifeCycle;

    if (!idDesc.fTextureID) {
        return return_null_texture();
    }

    this->setScratchTextureUnit();
    GL_CALL(BindTexture(GR_GL_TEXTURE_2D, idDesc.fTextureID));

    if (renderTarget && this->glCaps().textureUsageSupport()) {
        // provides a hint about how this texture will be used
        GL_CALL(TexParameteri(GR_GL_TEXTURE_2D,
                              GR_GL_TEXTURE_USAGE,
                              GR_GL_FRAMEBUFFER_ATTACHMENT));
    }

    // Some drivers like to know filter/wrap before seeing glTexImage2D. Some
    // drivers have a bug where an FBO won't be complete if it includes a
    // texture that is not mipmap complete (considering the filter in use).
    GrGLTexture::TexParams initialTexParams;
    // we only set a subset here so invalidate first
    initialTexParams.invalidate();
    initialTexParams.fMinFilter = GR_GL_NEAREST;
    initialTexParams.fMagFilter = GR_GL_NEAREST;
    initialTexParams.fWrapS = GR_GL_CLAMP_TO_EDGE;
    initialTexParams.fWrapT = GR_GL_CLAMP_TO_EDGE;
    GL_CALL(TexParameteri(GR_GL_TEXTURE_2D,
                          GR_GL_TEXTURE_MAG_FILTER,
                          initialTexParams.fMagFilter));
    GL_CALL(TexParameteri(GR_GL_TEXTURE_2D,
                          GR_GL_TEXTURE_MIN_FILTER,
                          initialTexParams.fMinFilter));
    GL_CALL(TexParameteri(GR_GL_TEXTURE_2D,
                          GR_GL_TEXTURE_WRAP_S,
                          initialTexParams.fWrapS));
    GL_CALL(TexParameteri(GR_GL_TEXTURE_2D,
                          GR_GL_TEXTURE_WRAP_T,
                          initialTexParams.fWrapT));
    if (!this->uploadTexData(desc, true, 0, 0,
                             desc.fWidth, desc.fHeight,
                             desc.fConfig, srcData, rowBytes)) {
        GL_CALL(DeleteTextures(1, &idDesc.fTextureID));
>>>>>>> miniblink49
        return return_null_texture();
    }

    GrGLTexture* tex;
    if (renderTarget) {
        // unbind the texture from the texture unit before binding it to the frame buffer
<<<<<<< HEAD
        GL_CALL(BindTexture(idDesc.fInfo.fTarget, 0));
        GrGLRenderTarget::IDDesc rtIDDesc;

        if (!this->createRenderTargetObjects(desc, idDesc.fInfo, &rtIDDesc)) {
            GL_CALL(DeleteTextures(1, &idDesc.fInfo.fID));
            return return_null_texture();
        }
        tex = new GrGLTextureRenderTarget(this, budgeted, desc, idDesc, rtIDDesc);
    } else {
        bool wasMipMapDataProvided = false;
        if (texels.count() > 1) {
            wasMipMapDataProvided = true;
        }
        tex = new GrGLTexture(this, budgeted, desc, idDesc, wasMipMapDataProvided);
=======
        GL_CALL(BindTexture(GR_GL_TEXTURE_2D, 0));
        GrGLRenderTarget::IDDesc rtIDDesc;

        if (!this->createRenderTargetObjects(desc, lifeCycle, idDesc.fTextureID, &rtIDDesc)) {
            GL_CALL(DeleteTextures(1, &idDesc.fTextureID));
            return return_null_texture();
        }
        tex = SkNEW_ARGS(GrGLTextureRenderTarget, (this, desc, idDesc, rtIDDesc));
    } else {
        tex = SkNEW_ARGS(GrGLTexture, (this, desc, idDesc));
>>>>>>> miniblink49
    }
    tex->setCachedTexParams(initialTexParams, this->getResetTimestamp());
#ifdef TRACE_TEXTURE_CREATION
    SkDebugf("--- new texture [%d] size=(%d %d) config=%d\n",
<<<<<<< HEAD
        glTexDesc.fInfo.fID, desc.fWidth, desc.fHeight, desc.fConfig);
=======
             glTexDesc.fTextureID, desc.fWidth, desc.fHeight, desc.fConfig);
>>>>>>> miniblink49
#endif
    return tex;
}

GrTexture* GrGLGpu::onCreateCompressedTexture(const GrSurfaceDesc& desc,
<<<<<<< HEAD
    SkBudgeted budgeted,
    const SkTArray<GrMipLevel>& texels)
{
=======
                                              GrGpuResource::LifeCycle lifeCycle,
                                              const void* srcData) {
>>>>>>> miniblink49
    // Make sure that we're not flipping Y.
    if (kBottomLeft_GrSurfaceOrigin == desc.fOrigin) {
        return return_null_texture();
    }

<<<<<<< HEAD
    GrGLTexture::IDDesc idDesc = generate_gl_texture(this->glInterface());
    if (!idDesc.fInfo.fID) {
=======
    GrGLTexture::IDDesc idDesc;
    GL_CALL(GenTextures(1, &idDesc.fTextureID));
    idDesc.fLifeCycle = lifeCycle;

    if (!idDesc.fTextureID) {
>>>>>>> miniblink49
        return return_null_texture();
    }

    this->setScratchTextureUnit();
<<<<<<< HEAD
    GL_CALL(BindTexture(idDesc.fInfo.fTarget, idDesc.fInfo.fID));

    GrGLTexture::TexParams initialTexParams;
    set_initial_texture_params(this->glInterface(), idDesc.fInfo, &initialTexParams);

    if (!this->uploadCompressedTexData(desc, idDesc.fInfo.fTarget, texels)) {
        GL_CALL(DeleteTextures(1, &idDesc.fInfo.fID));
=======
    GL_CALL(BindTexture(GR_GL_TEXTURE_2D, idDesc.fTextureID));

    // Some drivers like to know filter/wrap before seeing glTexImage2D. Some
    // drivers have a bug where an FBO won't be complete if it includes a
    // texture that is not mipmap complete (considering the filter in use).
    GrGLTexture::TexParams initialTexParams;
    // we only set a subset here so invalidate first
    initialTexParams.invalidate();
    initialTexParams.fMinFilter = GR_GL_NEAREST;
    initialTexParams.fMagFilter = GR_GL_NEAREST;
    initialTexParams.fWrapS = GR_GL_CLAMP_TO_EDGE;
    initialTexParams.fWrapT = GR_GL_CLAMP_TO_EDGE;
    GL_CALL(TexParameteri(GR_GL_TEXTURE_2D,
                          GR_GL_TEXTURE_MAG_FILTER,
                          initialTexParams.fMagFilter));
    GL_CALL(TexParameteri(GR_GL_TEXTURE_2D,
                          GR_GL_TEXTURE_MIN_FILTER,
                          initialTexParams.fMinFilter));
    GL_CALL(TexParameteri(GR_GL_TEXTURE_2D,
                          GR_GL_TEXTURE_WRAP_S,
                          initialTexParams.fWrapS));
    GL_CALL(TexParameteri(GR_GL_TEXTURE_2D,
                          GR_GL_TEXTURE_WRAP_T,
                          initialTexParams.fWrapT));

    if (!this->uploadCompressedTexData(desc, srcData)) {
        GL_CALL(DeleteTextures(1, &idDesc.fTextureID));
>>>>>>> miniblink49
        return return_null_texture();
    }

    GrGLTexture* tex;
<<<<<<< HEAD
    tex = new GrGLTexture(this, budgeted, desc, idDesc);
    tex->setCachedTexParams(initialTexParams, this->getResetTimestamp());
#ifdef TRACE_TEXTURE_CREATION
    SkDebugf("--- new compressed texture [%d] size=(%d %d) config=%d\n",
        glTexDesc.fInfo.fID, desc.fWidth, desc.fHeight, desc.fConfig);
=======
    tex = SkNEW_ARGS(GrGLTexture, (this, desc, idDesc));
    tex->setCachedTexParams(initialTexParams, this->getResetTimestamp());
#ifdef TRACE_TEXTURE_CREATION
    SkDebugf("--- new compressed texture [%d] size=(%d %d) config=%d\n",
             glTexDesc.fTextureID, desc.fWidth, desc.fHeight, desc.fConfig);
>>>>>>> miniblink49
#endif
    return tex;
}

namespace {

const GrGLuint kUnknownBitCount = GrGLStencilAttachment::kUnknownBitCount;

void inline get_stencil_rb_sizes(const GrGLInterface* gl,
<<<<<<< HEAD
    GrGLStencilAttachment::Format* format)
{

    // we shouldn't ever know one size and not the other
    SkASSERT((kUnknownBitCount == format->fStencilBits) == (kUnknownBitCount == format->fTotalBits));
    if (kUnknownBitCount == format->fStencilBits) {
        GR_GL_GetRenderbufferParameteriv(gl, GR_GL_RENDERBUFFER,
            GR_GL_RENDERBUFFER_STENCIL_SIZE,
            (GrGLint*)&format->fStencilBits);
        if (format->fPacked) {
            GR_GL_GetRenderbufferParameteriv(gl, GR_GL_RENDERBUFFER,
                GR_GL_RENDERBUFFER_DEPTH_SIZE,
                (GrGLint*)&format->fTotalBits);
=======
                                 GrGLStencilAttachment::Format* format) {

    // we shouldn't ever know one size and not the other
    SkASSERT((kUnknownBitCount == format->fStencilBits) ==
             (kUnknownBitCount == format->fTotalBits));
    if (kUnknownBitCount == format->fStencilBits) {
        GR_GL_GetRenderbufferParameteriv(gl, GR_GL_RENDERBUFFER,
                                         GR_GL_RENDERBUFFER_STENCIL_SIZE,
                                         (GrGLint*)&format->fStencilBits);
        if (format->fPacked) {
            GR_GL_GetRenderbufferParameteriv(gl, GR_GL_RENDERBUFFER,
                                             GR_GL_RENDERBUFFER_DEPTH_SIZE,
                                             (GrGLint*)&format->fTotalBits);
>>>>>>> miniblink49
            format->fTotalBits += format->fStencilBits;
        } else {
            format->fTotalBits = format->fStencilBits;
        }
    }
}
}

<<<<<<< HEAD
int GrGLGpu::getCompatibleStencilIndex(GrPixelConfig config)
{
    static const int kSize = 16;
    SkASSERT(this->caps()->isConfigRenderable(config, false));
    if (!this->glCaps().hasStencilFormatBeenDeterminedForConfig(config)) {
        // Default to unsupported, set this if we find a stencil format that works.
        int firstWorkingStencilFormatIndex = -1;
        // Create color texture
        GrGLuint colorID = 0;
        GL_CALL(GenTextures(1, &colorID));
        this->setScratchTextureUnit();
        GL_CALL(BindTexture(GR_GL_TEXTURE_2D, colorID));
        GL_CALL(TexParameteri(GR_GL_TEXTURE_2D,
            GR_GL_TEXTURE_MAG_FILTER,
            GR_GL_NEAREST));
        GL_CALL(TexParameteri(GR_GL_TEXTURE_2D,
            GR_GL_TEXTURE_MIN_FILTER,
            GR_GL_NEAREST));
        GL_CALL(TexParameteri(GR_GL_TEXTURE_2D,
            GR_GL_TEXTURE_WRAP_S,
            GR_GL_CLAMP_TO_EDGE));
        GL_CALL(TexParameteri(GR_GL_TEXTURE_2D,
            GR_GL_TEXTURE_WRAP_T,
            GR_GL_CLAMP_TO_EDGE));

        GrGLenum internalFormat;
        GrGLenum externalFormat;
        GrGLenum externalType;
        if (!this->glCaps().getTexImageFormats(config, config, &internalFormat, &externalFormat,
                &externalType)) {
            return false;
        }
        CLEAR_ERROR_BEFORE_ALLOC(this->glInterface());
        GL_ALLOC_CALL(this->glInterface(), TexImage2D(GR_GL_TEXTURE_2D, 0, internalFormat, kSize, kSize, 0, externalFormat, externalType, NULL));
        if (GR_GL_NO_ERROR != CHECK_ALLOC_ERROR(this->glInterface())) {
            GL_CALL(DeleteTextures(1, &colorID));
            return -1;
        }

        // unbind the texture from the texture unit before binding it to the frame buffer
        GL_CALL(BindTexture(GR_GL_TEXTURE_2D, 0));

        // Create Framebuffer
        GrGLuint fb = 0;
        GL_CALL(GenFramebuffers(1, &fb));
        GL_CALL(BindFramebuffer(GR_GL_FRAMEBUFFER, fb));
        fHWBoundRenderTargetUniqueID = SK_InvalidUniqueID;
        GL_CALL(FramebufferTexture2D(GR_GL_FRAMEBUFFER,
            GR_GL_COLOR_ATTACHMENT0,
            GR_GL_TEXTURE_2D,
            colorID,
            0));
        GrGLuint sbRBID = 0;
        GL_CALL(GenRenderbuffers(1, &sbRBID));

        // look over formats till I find a compatible one
        int stencilFmtCnt = this->glCaps().stencilFormats().count();
        if (sbRBID) {
            GL_CALL(BindRenderbuffer(GR_GL_RENDERBUFFER, sbRBID));
            for (int i = 0; i < stencilFmtCnt && sbRBID; ++i) {
                const GrGLCaps::StencilFormat& sFmt = this->glCaps().stencilFormats()[i];
                CLEAR_ERROR_BEFORE_ALLOC(this->glInterface());
                GL_ALLOC_CALL(this->glInterface(), RenderbufferStorage(GR_GL_RENDERBUFFER, sFmt.fInternalFormat, kSize, kSize));
                if (GR_GL_NO_ERROR == CHECK_ALLOC_ERROR(this->glInterface())) {
                    GL_CALL(FramebufferRenderbuffer(GR_GL_FRAMEBUFFER,
                        GR_GL_STENCIL_ATTACHMENT,
                        GR_GL_RENDERBUFFER, sbRBID));
                    if (sFmt.fPacked) {
                        GL_CALL(FramebufferRenderbuffer(GR_GL_FRAMEBUFFER,
                            GR_GL_DEPTH_ATTACHMENT,
                            GR_GL_RENDERBUFFER, sbRBID));
                    } else {
                        GL_CALL(FramebufferRenderbuffer(GR_GL_FRAMEBUFFER,
                            GR_GL_DEPTH_ATTACHMENT,
                            GR_GL_RENDERBUFFER, 0));
                    }
                    GrGLenum status;
                    GL_CALL_RET(status, CheckFramebufferStatus(GR_GL_FRAMEBUFFER));
                    if (status == GR_GL_FRAMEBUFFER_COMPLETE) {
                        firstWorkingStencilFormatIndex = i;
                        break;
                    }
                    GL_CALL(FramebufferRenderbuffer(GR_GL_FRAMEBUFFER,
                        GR_GL_STENCIL_ATTACHMENT,
                        GR_GL_RENDERBUFFER, 0));
                    if (sFmt.fPacked) {
                        GL_CALL(FramebufferRenderbuffer(GR_GL_FRAMEBUFFER,
                            GR_GL_DEPTH_ATTACHMENT,
                            GR_GL_RENDERBUFFER, 0));
                    }
                }
            }
            GL_CALL(DeleteRenderbuffers(1, &sbRBID));
        }
        GL_CALL(DeleteTextures(1, &colorID));
        GL_CALL(BindFramebuffer(GR_GL_FRAMEBUFFER, 0));
        GL_CALL(DeleteFramebuffers(1, &fb));
        fGLContext->caps()->setStencilFormatIndexForConfig(config, firstWorkingStencilFormatIndex);
    }
    return this->glCaps().getStencilFormatIndexForConfig(config);
}

bool GrGLGpu::createTextureImpl(const GrSurfaceDesc& desc, GrGLTextureInfo* info,
    bool renderTarget, GrGLTexture::TexParams* initialTexParams,
    const SkTArray<GrMipLevel>& texels)
{
    info->fID = 0;
    info->fTarget = GR_GL_TEXTURE_2D;
    GL_CALL(GenTextures(1, &(info->fID)));

    if (!info->fID) {
        return false;
    }

    this->setScratchTextureUnit();
    GL_CALL(BindTexture(info->fTarget, info->fID));

    if (renderTarget && this->glCaps().textureUsageSupport()) {
        // provides a hint about how this texture will be used
        GL_CALL(TexParameteri(info->fTarget,
            GR_GL_TEXTURE_USAGE,
            GR_GL_FRAMEBUFFER_ATTACHMENT));
    }

    if (info) {
        set_initial_texture_params(this->glInterface(), *info, initialTexParams);
    }
    if (!this->uploadTexData(desc, info->fTarget, kNewTexture_UploadType, 0, 0,
            desc.fWidth, desc.fHeight,
            desc.fConfig, texels)) {
        GL_CALL(DeleteTextures(1, &(info->fID)));
        return false;
    }
    return true;
}

GrStencilAttachment* GrGLGpu::createStencilAttachmentForRenderTarget(const GrRenderTarget* rt,
    int width,
    int height)
{
=======
bool GrGLGpu::createStencilAttachmentForRenderTarget(GrRenderTarget* rt, int width, int height) {
    // All internally created RTs are also textures. We don't create
    // SBs for a client's standalone RT (that is a RT that isn't also a texture).
    SkASSERT(rt->asTexture());
>>>>>>> miniblink49
    SkASSERT(width >= rt->width());
    SkASSERT(height >= rt->height());

    int samples = rt->numStencilSamples();
    GrGLStencilAttachment::IDDesc sbDesc;

<<<<<<< HEAD
    int sIdx = this->getCompatibleStencilIndex(rt->config());
    if (sIdx < 0) {
        return nullptr;
    }

    if (!sbDesc.fRenderbufferID) {
        GL_CALL(GenRenderbuffers(1, &sbDesc.fRenderbufferID));
    }
    if (!sbDesc.fRenderbufferID) {
        return nullptr;
    }
    GL_CALL(BindRenderbuffer(GR_GL_RENDERBUFFER, sbDesc.fRenderbufferID));
    const GrGLCaps::StencilFormat& sFmt = this->glCaps().stencilFormats()[sIdx];
    CLEAR_ERROR_BEFORE_ALLOC(this->glInterface());
    // we do this "if" so that we don't call the multisample
    // version on a GL that doesn't have an MSAA extension.
    if (samples > 0) {
        SkAssertResult(renderbuffer_storage_msaa(*fGLContext,
            samples,
            sFmt.fInternalFormat,
            width, height));
    } else {
        GL_ALLOC_CALL(this->glInterface(), RenderbufferStorage(GR_GL_RENDERBUFFER, sFmt.fInternalFormat, width, height));
        SkASSERT(GR_GL_NO_ERROR == check_alloc_error(rt->desc(), this->glInterface()));
    }
    fStats.incStencilAttachmentCreates();
    // After sized formats we attempt an unsized format and take
    // whatever sizes GL gives us. In that case we query for the size.
    GrGLStencilAttachment::Format format = sFmt;
    get_stencil_rb_sizes(this->glInterface(), &format);
    GrGLStencilAttachment* stencil = new GrGLStencilAttachment(this,
        sbDesc,
        width,
        height,
        samples,
        format);
    return stencil;
=======
    int stencilFmtCnt = this->glCaps().stencilFormats().count();
    for (int i = 0; i < stencilFmtCnt; ++i) {
        if (!sbDesc.fRenderbufferID) {
            GL_CALL(GenRenderbuffers(1, &sbDesc.fRenderbufferID));
        }
        if (!sbDesc.fRenderbufferID) {
            return false;
        }
        GL_CALL(BindRenderbuffer(GR_GL_RENDERBUFFER, sbDesc.fRenderbufferID));
        // we start with the last stencil format that succeeded in hopes
        // that we won't go through this loop more than once after the
        // first (painful) stencil creation.
        int sIdx = (i + fLastSuccessfulStencilFmtIdx) % stencilFmtCnt;
        const GrGLCaps::StencilFormat& sFmt = this->glCaps().stencilFormats()[sIdx];
        CLEAR_ERROR_BEFORE_ALLOC(this->glInterface());
        // we do this "if" so that we don't call the multisample
        // version on a GL that doesn't have an MSAA extension.
        bool created;
        if (samples > 0) {
            created = renderbuffer_storage_msaa(*fGLContext,
                                                samples,
                                                sFmt.fInternalFormat,
                                                width, height);
        } else {
            GL_ALLOC_CALL(this->glInterface(), RenderbufferStorage(GR_GL_RENDERBUFFER,
                                                                   sFmt.fInternalFormat,
                                                                   width, height));
            created = (GR_GL_NO_ERROR == check_alloc_error(rt->desc(), this->glInterface()));
        }
        if (created) {
            fStats.incStencilAttachmentCreates();
            // After sized formats we attempt an unsized format and take
            // whatever sizes GL gives us. In that case we query for the size.
            GrGLStencilAttachment::Format format = sFmt;
            get_stencil_rb_sizes(this->glInterface(), &format);
            SkAutoTUnref<GrGLStencilAttachment> sb(SkNEW_ARGS(GrGLStencilAttachment,
                                                  (this, sbDesc, width, height, samples, format)));
            if (this->attachStencilAttachmentToRenderTarget(sb, rt)) {
                fLastSuccessfulStencilFmtIdx = sIdx;
                rt->renderTargetPriv().didAttachStencilAttachment(sb);
// This work around is currently breaking on windows 7 hd2000 bot when we bind a color buffer
#if 0
                // Clear the stencil buffer. We use a special purpose FBO for this so that the
                // entire stencil buffer is cleared, even if it is attached to an FBO with a
                // smaller color target.
                if (0 == fStencilClearFBOID) {
                    GL_CALL(GenFramebuffers(1, &fStencilClearFBOID));
                }

                GL_CALL(BindFramebuffer(GR_GL_FRAMEBUFFER, fStencilClearFBOID));
                fHWBoundRenderTargetUniqueID = SK_InvalidUniqueID;
                fStats.incRenderTargetBinds();
                GL_CALL(FramebufferRenderbuffer(GR_GL_FRAMEBUFFER,
                                                GR_GL_STENCIL_ATTACHMENT,
                                                GR_GL_RENDERBUFFER, sbDesc.fRenderbufferID));
                if (sFmt.fPacked) {
                    GL_CALL(FramebufferRenderbuffer(GR_GL_FRAMEBUFFER,
                                                    GR_GL_DEPTH_ATTACHMENT,
                                                    GR_GL_RENDERBUFFER, sbDesc.fRenderbufferID));
                }

                GL_CALL(ClearStencil(0));
                // Many GL implementations seem to have trouble with clearing an FBO with only
                // a stencil buffer.
                GrGLuint tempRB;
                GL_CALL(GenRenderbuffers(1, &tempRB));
                GL_CALL(BindRenderbuffer(GR_GL_RENDERBUFFER, tempRB));
                if (samples > 0) {
                    renderbuffer_storage_msaa(fGLContext, samples, GR_GL_RGBA8, width, height);
                } else {
                    GL_CALL(RenderbufferStorage(GR_GL_RENDERBUFFER, GR_GL_RGBA8, width, height));
                }
                GL_CALL(FramebufferRenderbuffer(GR_GL_FRAMEBUFFER,
                                                GR_GL_COLOR_ATTACHMENT0,
                                                GR_GL_RENDERBUFFER, tempRB));

                GL_CALL(Clear(GR_GL_STENCIL_BUFFER_BIT));

                GL_CALL(FramebufferRenderbuffer(GR_GL_FRAMEBUFFER,
                                                GR_GL_COLOR_ATTACHMENT0,
                                                GR_GL_RENDERBUFFER, 0));
                GL_CALL(DeleteRenderbuffers(1, &tempRB));

                // Unbind the SB from the FBO so that we don't keep it alive.
                GL_CALL(FramebufferRenderbuffer(GR_GL_FRAMEBUFFER,
                                                GR_GL_STENCIL_ATTACHMENT,
                                                GR_GL_RENDERBUFFER, 0));
                if (sFmt.fPacked) {
                    GL_CALL(FramebufferRenderbuffer(GR_GL_FRAMEBUFFER,
                                                    GR_GL_DEPTH_ATTACHMENT,
                                                    GR_GL_RENDERBUFFER, 0));
                }
#endif
                return true;
            }
            // Remove the scratch key from this resource so we don't grab it from the cache ever
            // again.
            sb->resourcePriv().removeScratchKey();
            // Set this to 0 since we handed the valid ID off to the failed stencil buffer resource.
            sbDesc.fRenderbufferID = 0;
        }
    }
    GL_CALL(DeleteRenderbuffers(1, &sbDesc.fRenderbufferID));
    return false;
}

bool GrGLGpu::attachStencilAttachmentToRenderTarget(GrStencilAttachment* sb, GrRenderTarget* rt) {
    GrGLRenderTarget* glrt = static_cast<GrGLRenderTarget*>(rt);

    GrGLuint fbo = glrt->renderFBOID();

    if (NULL == sb) {
        if (rt->renderTargetPriv().getStencilAttachment()) {
            GL_CALL(FramebufferRenderbuffer(GR_GL_FRAMEBUFFER,
                                            GR_GL_STENCIL_ATTACHMENT,
                                            GR_GL_RENDERBUFFER, 0));
            GL_CALL(FramebufferRenderbuffer(GR_GL_FRAMEBUFFER,
                                            GR_GL_DEPTH_ATTACHMENT,
                                            GR_GL_RENDERBUFFER, 0));
#ifdef SK_DEBUG
            GrGLenum status;
            GL_CALL_RET(status, CheckFramebufferStatus(GR_GL_FRAMEBUFFER));
            SkASSERT(GR_GL_FRAMEBUFFER_COMPLETE == status);
#endif
        }
        return true;
    } else {
        GrGLStencilAttachment* glsb = static_cast<GrGLStencilAttachment*>(sb);
        GrGLuint rb = glsb->renderbufferID();

        fHWBoundRenderTargetUniqueID = SK_InvalidUniqueID;
        fStats.incRenderTargetBinds();
        GL_CALL(BindFramebuffer(GR_GL_FRAMEBUFFER, fbo));
        GL_CALL(FramebufferRenderbuffer(GR_GL_FRAMEBUFFER,
                                        GR_GL_STENCIL_ATTACHMENT,
                                        GR_GL_RENDERBUFFER, rb));
        if (glsb->format().fPacked) {
            GL_CALL(FramebufferRenderbuffer(GR_GL_FRAMEBUFFER,
                                            GR_GL_DEPTH_ATTACHMENT,
                                            GR_GL_RENDERBUFFER, rb));
        } else {
            GL_CALL(FramebufferRenderbuffer(GR_GL_FRAMEBUFFER,
                                            GR_GL_DEPTH_ATTACHMENT,
                                            GR_GL_RENDERBUFFER, 0));
        }

        GrGLenum status;
        if (!this->glCaps().isColorConfigAndStencilFormatVerified(rt->config(), glsb->format())) {
            GL_CALL_RET(status, CheckFramebufferStatus(GR_GL_FRAMEBUFFER));
            if (status != GR_GL_FRAMEBUFFER_COMPLETE) {
                GL_CALL(FramebufferRenderbuffer(GR_GL_FRAMEBUFFER,
                                              GR_GL_STENCIL_ATTACHMENT,
                                              GR_GL_RENDERBUFFER, 0));
                if (glsb->format().fPacked) {
                    GL_CALL(FramebufferRenderbuffer(GR_GL_FRAMEBUFFER,
                                                  GR_GL_DEPTH_ATTACHMENT,
                                                  GR_GL_RENDERBUFFER, 0));
                }
                return false;
            } else {
                fGLContext->caps()->markColorConfigAndStencilFormatAsVerified(
                    rt->config(),
                    glsb->format());
            }
        }
        return true;
    }
>>>>>>> miniblink49
}

////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
// GL_STREAM_DRAW triggers an optimization in Chromium's GPU process where a client's vertex buffer
// objects are implemented as client-side-arrays on tile-deferred architectures.
#define DYNAMIC_USAGE_PARAM GR_GL_STREAM_DRAW

GrBuffer* GrGLGpu::onCreateBuffer(size_t size, GrBufferType intendedType,
    GrAccessPattern accessPattern, const void* data)
{
    return GrGLBuffer::Create(this, size, intendedType, accessPattern, data);
}

void GrGLGpu::flushScissor(const GrScissorState& scissorState,
    const GrGLIRect& rtViewport,
    GrSurfaceOrigin rtOrigin)
{
    if (scissorState.enabled()) {
        GrGLIRect scissor;
        scissor.setRelativeTo(rtViewport,
            scissorState.rect().fLeft,
            scissorState.rect().fTop,
            scissorState.rect().width(),
            scissorState.rect().height(),
            rtOrigin);
=======
GrVertexBuffer* GrGLGpu::onCreateVertexBuffer(size_t size, bool dynamic) {
    GrGLVertexBuffer::Desc desc;
    desc.fDynamic = dynamic;
    desc.fSizeInBytes = size;

    if (this->glCaps().useNonVBOVertexAndIndexDynamicData() && desc.fDynamic) {
        desc.fID = 0;
        GrGLVertexBuffer* vertexBuffer = SkNEW_ARGS(GrGLVertexBuffer, (this, desc));
        return vertexBuffer;
    } else {
        GL_CALL(GenBuffers(1, &desc.fID));
        if (desc.fID) {
            fHWGeometryState.setVertexBufferID(this, desc.fID);
            CLEAR_ERROR_BEFORE_ALLOC(this->glInterface());
            // make sure driver can allocate memory for this buffer
            GL_ALLOC_CALL(this->glInterface(),
                          BufferData(GR_GL_ARRAY_BUFFER,
                                     (GrGLsizeiptr) desc.fSizeInBytes,
                                     NULL,   // data ptr
                                     desc.fDynamic ? GR_GL_DYNAMIC_DRAW : GR_GL_STATIC_DRAW));
            if (CHECK_ALLOC_ERROR(this->glInterface()) != GR_GL_NO_ERROR) {
                GL_CALL(DeleteBuffers(1, &desc.fID));
                this->notifyVertexBufferDelete(desc.fID);
                return NULL;
            }
            GrGLVertexBuffer* vertexBuffer = SkNEW_ARGS(GrGLVertexBuffer, (this, desc));
            return vertexBuffer;
        }
        return NULL;
    }
}

GrIndexBuffer* GrGLGpu::onCreateIndexBuffer(size_t size, bool dynamic) {
    GrGLIndexBuffer::Desc desc;
    desc.fDynamic = dynamic;
    desc.fSizeInBytes = size;

    if (this->glCaps().useNonVBOVertexAndIndexDynamicData() && desc.fDynamic) {
        desc.fID = 0;
        GrIndexBuffer* indexBuffer = SkNEW_ARGS(GrGLIndexBuffer, (this, desc));
        return indexBuffer;
    } else {
        GL_CALL(GenBuffers(1, &desc.fID));
        if (desc.fID) {
            fHWGeometryState.setIndexBufferIDOnDefaultVertexArray(this, desc.fID);
            CLEAR_ERROR_BEFORE_ALLOC(this->glInterface());
            // make sure driver can allocate memory for this buffer
            GL_ALLOC_CALL(this->glInterface(),
                          BufferData(GR_GL_ELEMENT_ARRAY_BUFFER,
                                     (GrGLsizeiptr) desc.fSizeInBytes,
                                     NULL,  // data ptr
                                     desc.fDynamic ? GR_GL_DYNAMIC_DRAW : GR_GL_STATIC_DRAW));
            if (CHECK_ALLOC_ERROR(this->glInterface()) != GR_GL_NO_ERROR) {
                GL_CALL(DeleteBuffers(1, &desc.fID));
                this->notifyIndexBufferDelete(desc.fID);
                return NULL;
            }
            GrIndexBuffer* indexBuffer = SkNEW_ARGS(GrGLIndexBuffer, (this, desc));
            return indexBuffer;
        }
        return NULL;
    }
}

void GrGLGpu::flushScissor(const GrScissorState& scissorState,
                           const GrGLIRect& rtViewport,
                           GrSurfaceOrigin rtOrigin) {
    if (scissorState.enabled()) {
        GrGLIRect scissor;
        scissor.setRelativeTo(rtViewport,
                              scissorState.rect().fLeft,
                              scissorState.rect().fTop,
                              scissorState.rect().width(),
                              scissorState.rect().height(),
                              rtOrigin);
>>>>>>> miniblink49
        // if the scissor fully contains the viewport then we fall through and
        // disable the scissor test.
        if (!scissor.contains(rtViewport)) {
            if (fHWScissorSettings.fRect != scissor) {
                scissor.pushToGLScissor(this->glInterface());
                fHWScissorSettings.fRect = scissor;
            }
            if (kYes_TriState != fHWScissorSettings.fEnabled) {
                GL_CALL(Enable(GR_GL_SCISSOR_TEST));
                fHWScissorSettings.fEnabled = kYes_TriState;
            }
            return;
        }
    }

    // See fall through note above
    this->disableScissor();
}

<<<<<<< HEAD
void GrGLGpu::flushMinSampleShading(float minSampleShading)
{
    if (fHWMinSampleShading != minSampleShading) {
        if (minSampleShading > 0.0) {
            GL_CALL(Enable(GR_GL_SAMPLE_SHADING));
            GL_CALL(MinSampleShading(minSampleShading));
        } else {
            GL_CALL(Disable(GR_GL_SAMPLE_SHADING));
        }
        fHWMinSampleShading = minSampleShading;
    }
}

bool GrGLGpu::flushGLState(const GrPipeline& pipeline, const GrPrimitiveProcessor& primProc)
{
    SkAutoTUnref<GrGLProgram> program(fProgramCache->refProgram(this, pipeline, primProc));
=======
bool GrGLGpu::flushGLState(const DrawArgs& args) {
    GrXferProcessor::BlendInfo blendInfo;
    const GrPipeline& pipeline = *args.fPipeline;
    args.fPipeline->getXferProcessor()->getBlendInfo(&blendInfo);

    this->flushDither(pipeline.isDitherState());
    this->flushColorWrite(blendInfo.fWriteColor);
    this->flushDrawFace(pipeline.getDrawFace());

    SkAutoTUnref<GrGLProgram> program(fProgramCache->refProgram(args));
>>>>>>> miniblink49
    if (!program) {
        GrCapsDebugf(this->caps(), "Failed to create program!\n");
        return false;
    }

<<<<<<< HEAD
    program->generateMipmaps(primProc, pipeline);

    GrXferProcessor::BlendInfo blendInfo;
    pipeline.getXferProcessor().getBlendInfo(&blendInfo);

    this->flushColorWrite(blendInfo.fWriteColor);
    this->flushDrawFace(pipeline.getDrawFace());
    this->flushMinSampleShading(primProc.getSampleShading());

=======
>>>>>>> miniblink49
    GrGLuint programID = program->programID();
    if (fHWProgramID != programID) {
        GL_CALL(UseProgram(programID));
        fHWProgramID = programID;
    }

    if (blendInfo.fWriteColor) {
<<<<<<< HEAD
        // Swizzle the blend to match what the shader will output.
        const GrSwizzle& swizzle = this->glCaps().glslCaps()->configOutputSwizzle(
            pipeline.getRenderTarget()->config());
        this->flushBlend(blendInfo, swizzle);
    }

    program->setData(primProc, pipeline);
=======
        this->flushBlend(blendInfo);
    }

    SkSTArray<8, const GrTextureAccess*> textureAccesses;
    program->setData(*args.fPrimitiveProcessor, pipeline, *args.fBatchTracker, &textureAccesses);

    int numTextureAccesses = textureAccesses.count();
    for (int i = 0; i < numTextureAccesses; i++) {
        this->bindTexture(i, textureAccesses[i]->getParams(),
                          static_cast<GrGLTexture*>(textureAccesses[i]->getTexture()));
    }
>>>>>>> miniblink49

    GrGLRenderTarget* glRT = static_cast<GrGLRenderTarget*>(pipeline.getRenderTarget());
    this->flushStencil(pipeline.getStencil());
    this->flushScissor(pipeline.getScissorState(), glRT->getViewport(), glRT->origin());
<<<<<<< HEAD
    this->flushHWAAState(glRT, pipeline.isHWAntialiasState(), !pipeline.getStencil().isDisabled());

    // This must come after textures are flushed because a texture may need
    // to be msaa-resolved (which will modify bound FBO state).
    this->flushRenderTarget(glRT, nullptr, pipeline.getDisableOutputConversionToSRGB());
=======
    this->flushHWAAState(glRT, pipeline.isHWAntialiasState());

    // This must come after textures are flushed because a texture may need
    // to be msaa-resolved (which will modify bound FBO state).
    this->flushRenderTarget(glRT, NULL);
>>>>>>> miniblink49

    return true;
}

void GrGLGpu::setupGeometry(const GrPrimitiveProcessor& primProc,
<<<<<<< HEAD
    const GrNonInstancedMesh& mesh,
    size_t* indexOffsetInBytes)
{
    const GrGLBuffer* vbuf;
    vbuf = static_cast<const GrGLBuffer*>(mesh.vertexBuffer());
=======
                            const GrNonInstancedVertices& vertices,
                            size_t* indexOffsetInBytes) {
    GrGLVertexBuffer* vbuf;
    vbuf = (GrGLVertexBuffer*) vertices.vertexBuffer();
>>>>>>> miniblink49

    SkASSERT(vbuf);
    SkASSERT(!vbuf->isMapped());

<<<<<<< HEAD
    GrGLAttribArrayState* attribState;
    if (mesh.isIndexed()) {
        SkASSERT(indexOffsetInBytes);

        *indexOffsetInBytes = 0;
        const GrGLBuffer* ibuf = static_cast<const GrGLBuffer*>(mesh.indexBuffer());
=======
    GrGLIndexBuffer* ibuf = NULL;
    if (vertices.isIndexed()) {
        SkASSERT(indexOffsetInBytes);

        *indexOffsetInBytes = 0;
        ibuf = (GrGLIndexBuffer*)vertices.indexBuffer();
>>>>>>> miniblink49

        SkASSERT(ibuf);
        SkASSERT(!ibuf->isMapped());
        *indexOffsetInBytes += ibuf->baseOffset();
<<<<<<< HEAD
        attribState = fHWVertexArrayState.bindInternalVertexArray(this, ibuf);
    } else {
        attribState = fHWVertexArrayState.bindInternalVertexArray(this);
    }
=======
    }
    GrGLAttribArrayState* attribState =
        fHWGeometryState.bindArrayAndBuffersToDraw(this, vbuf, ibuf);
>>>>>>> miniblink49

    int vaCount = primProc.numAttribs();
    if (vaCount > 0) {

        GrGLsizei stride = static_cast<GrGLsizei>(primProc.getVertexStride());

<<<<<<< HEAD
        size_t vertexOffsetInBytes = stride * mesh.startVertex();
=======
        size_t vertexOffsetInBytes = stride * vertices.startVertex();
>>>>>>> miniblink49

        vertexOffsetInBytes += vbuf->baseOffset();

        uint32_t usedAttribArraysMask = 0;
        size_t offset = 0;

        for (int attribIndex = 0; attribIndex < vaCount; attribIndex++) {
            const GrGeometryProcessor::Attribute& attrib = primProc.getAttrib(attribIndex);
            usedAttribArraysMask |= (1 << attribIndex);
            GrVertexAttribType attribType = attrib.fType;
            attribState->set(this,
<<<<<<< HEAD
                attribIndex,
                vbuf,
                attribType,
                stride,
                reinterpret_cast<GrGLvoid*>(vertexOffsetInBytes + offset));
=======
                             attribIndex,
                             vbuf->bufferID(),
                             GrGLAttribTypeToLayout(attribType).fCount,
                             GrGLAttribTypeToLayout(attribType).fType,
                             GrGLAttribTypeToLayout(attribType).fNormalized,
                             stride,
                             reinterpret_cast<GrGLvoid*>(vertexOffsetInBytes + offset));
>>>>>>> miniblink49
            offset += attrib.fOffset;
        }
        attribState->disableUnusedArrays(this, usedAttribArraysMask);
    }
}

<<<<<<< HEAD
GrGLenum GrGLGpu::bindBuffer(GrBufferType type, const GrGLBuffer* buffer)
{
    this->handleDirtyContext();

    // Index buffer state is tied to the vertex array.
    if (kIndex_GrBufferType == type) {
        this->bindVertexArray(0);
    }

    SkASSERT(type >= 0 && type <= kLast_GrBufferType);
    auto& bufferState = fHWBufferState[type];

    if (buffer->getUniqueID() != bufferState.fBoundBufferUniqueID) {
        if (!buffer->isCPUBacked() || !bufferState.fBufferZeroKnownBound) {
            GL_CALL(BindBuffer(bufferState.fGLTarget, buffer->bufferID()));
            bufferState.fBufferZeroKnownBound = buffer->isCPUBacked();
        }
        bufferState.fBoundBufferUniqueID = buffer->getUniqueID();
    }

    return bufferState.fGLTarget;
}

void GrGLGpu::notifyBufferReleased(const GrGLBuffer* buffer)
{
    if (buffer->hasAttachedToTexture()) {
        // Detach this buffer from any textures to ensure the underlying memory is freed.
        uint32_t uniqueID = buffer->getUniqueID();
        for (int i = fHWMaxUsedBufferTextureUnit; i >= 0; --i) {
            auto& buffTex = fHWBufferTextures[i];
            if (uniqueID != buffTex.fAttachedBufferUniqueID) {
                continue;
            }
            if (i == fHWMaxUsedBufferTextureUnit) {
                --fHWMaxUsedBufferTextureUnit;
            }

            this->setTextureUnit(i);
            if (!buffTex.fKnownBound) {
                SkASSERT(buffTex.fTextureID);
                GL_CALL(BindTexture(GR_GL_TEXTURE_BUFFER, buffTex.fTextureID));
                buffTex.fKnownBound = true;
            }
            GL_CALL(TexBuffer(GR_GL_TEXTURE_BUFFER,
                this->glCaps().configSizedInternalFormat(buffTex.fTexelConfig), 0));
        }
    }
}

void GrGLGpu::disableScissor()
{
=======
void GrGLGpu::buildProgramDesc(GrProgramDesc* desc,
                               const GrPrimitiveProcessor& primProc,
                               const GrPipeline& pipeline,
                               const GrBatchTracker& batchTracker) const {
    if (!GrGLProgramDescBuilder::Build(desc, primProc, pipeline, this, batchTracker)) {
        SkDEBUGFAIL("Failed to generate GL program descriptor");
    }
}

void GrGLGpu::disableScissor() {
>>>>>>> miniblink49
    if (kNo_TriState != fHWScissorSettings.fEnabled) {
        GL_CALL(Disable(GR_GL_SCISSOR_TEST));
        fHWScissorSettings.fEnabled = kNo_TriState;
        return;
    }
}

<<<<<<< HEAD
void GrGLGpu::clear(const SkIRect& rect, GrColor color, GrRenderTarget* target)
{
    this->handleDirtyContext();

=======
void GrGLGpu::onClear(GrRenderTarget* target, const SkIRect* rect, GrColor color,
                      bool canIgnoreRect) {
>>>>>>> miniblink49
    // parent class should never let us get here with no RT
    SkASSERT(target);
    GrGLRenderTarget* glRT = static_cast<GrGLRenderTarget*>(target);

<<<<<<< HEAD
    this->flushRenderTarget(glRT, &rect);
    GrScissorState scissorState;
    scissorState.set(rect);
=======
    if (canIgnoreRect && this->glCaps().fullClearIsFree()) {
        rect = NULL;
    }

    SkIRect clippedRect;
    if (rect) {
        // flushScissor expects rect to be clipped to the target.
        clippedRect = *rect;
        SkIRect rtRect = SkIRect::MakeWH(target->width(), target->height());
        if (clippedRect.intersect(rtRect)) {
            rect = &clippedRect;
        } else {
            return;
        }
    }

    this->flushRenderTarget(glRT, rect);
    GrScissorState scissorState;
    if (rect) {
        scissorState.set(*rect);
    }
>>>>>>> miniblink49
    this->flushScissor(scissorState, glRT->getViewport(), glRT->origin());

    GrGLfloat r, g, b, a;
    static const GrGLfloat scale255 = 1.f / 255.f;
    a = GrColorUnpackA(color) * scale255;
    GrGLfloat scaleRGB = scale255;
    r = GrColorUnpackR(color) * scaleRGB;
    g = GrColorUnpackG(color) * scaleRGB;
    b = GrColorUnpackB(color) * scaleRGB;

    GL_CALL(ColorMask(GR_GL_TRUE, GR_GL_TRUE, GR_GL_TRUE, GR_GL_TRUE));
    fHWWriteToColor = kYes_TriState;
    GL_CALL(ClearColor(r, g, b, a));
    GL_CALL(Clear(GR_GL_COLOR_BUFFER_BIT));
}

<<<<<<< HEAD
void GrGLGpu::discard(GrRenderTarget* renderTarget)
{
=======
void GrGLGpu::discard(GrRenderTarget* renderTarget) {
>>>>>>> miniblink49
    SkASSERT(renderTarget);
    if (!this->caps()->discardRenderTargetSupport()) {
        return;
    }

    GrGLRenderTarget* glRT = static_cast<GrGLRenderTarget*>(renderTarget);
    if (renderTarget->getUniqueID() != fHWBoundRenderTargetUniqueID) {
        fHWBoundRenderTargetUniqueID = SK_InvalidUniqueID;
        fStats.incRenderTargetBinds();
        GL_CALL(BindFramebuffer(GR_GL_FRAMEBUFFER, glRT->renderFBOID()));
    }
    switch (this->glCaps().invalidateFBType()) {
<<<<<<< HEAD
    case GrGLCaps::kNone_InvalidateFBType:
        SkFAIL("Should never get here.");
        break;
    case GrGLCaps::kInvalidate_InvalidateFBType:
        if (0 == glRT->renderFBOID()) {
            //  When rendering to the default framebuffer the legal values for attachments
            //  are GL_COLOR, GL_DEPTH, GL_STENCIL, ... rather than the various FBO attachment
            //  types.
            static const GrGLenum attachments[] = { GR_GL_COLOR };
            GL_CALL(InvalidateFramebuffer(GR_GL_FRAMEBUFFER, SK_ARRAY_COUNT(attachments),
                attachments));
        } else {
            static const GrGLenum attachments[] = { GR_GL_COLOR_ATTACHMENT0 };
            GL_CALL(InvalidateFramebuffer(GR_GL_FRAMEBUFFER, SK_ARRAY_COUNT(attachments),
                attachments));
        }
        break;
    case GrGLCaps::kDiscard_InvalidateFBType: {
        if (0 == glRT->renderFBOID()) {
            //  When rendering to the default framebuffer the legal values for attachments
            //  are GL_COLOR, GL_DEPTH, GL_STENCIL, ... rather than the various FBO attachment
            //  types. See glDiscardFramebuffer() spec.
            static const GrGLenum attachments[] = { GR_GL_COLOR };
            GL_CALL(DiscardFramebuffer(GR_GL_FRAMEBUFFER, SK_ARRAY_COUNT(attachments),
                attachments));
        } else {
            static const GrGLenum attachments[] = { GR_GL_COLOR_ATTACHMENT0 };
            GL_CALL(DiscardFramebuffer(GR_GL_FRAMEBUFFER, SK_ARRAY_COUNT(attachments),
                attachments));
        }
        break;
    }
=======
        case GrGLCaps::kNone_InvalidateFBType:
            SkFAIL("Should never get here.");
            break;
        case GrGLCaps::kInvalidate_InvalidateFBType:
            if (0 == glRT->renderFBOID()) {
                //  When rendering to the default framebuffer the legal values for attachments
                //  are GL_COLOR, GL_DEPTH, GL_STENCIL, ... rather than the various FBO attachment
                //  types.
                static const GrGLenum attachments[] = { GR_GL_COLOR };
                GL_CALL(InvalidateFramebuffer(GR_GL_FRAMEBUFFER, SK_ARRAY_COUNT(attachments),
                        attachments));
            } else {
                static const GrGLenum attachments[] = { GR_GL_COLOR_ATTACHMENT0 };
                GL_CALL(InvalidateFramebuffer(GR_GL_FRAMEBUFFER, SK_ARRAY_COUNT(attachments),
                        attachments));
            }
            break;
        case GrGLCaps::kDiscard_InvalidateFBType: {
            if (0 == glRT->renderFBOID()) {
                //  When rendering to the default framebuffer the legal values for attachments
                //  are GL_COLOR, GL_DEPTH, GL_STENCIL, ... rather than the various FBO attachment
                //  types. See glDiscardFramebuffer() spec.
                static const GrGLenum attachments[] = { GR_GL_COLOR };
                GL_CALL(DiscardFramebuffer(GR_GL_FRAMEBUFFER, SK_ARRAY_COUNT(attachments),
                        attachments));
            } else {
                static const GrGLenum attachments[] = { GR_GL_COLOR_ATTACHMENT0 };
                GL_CALL(DiscardFramebuffer(GR_GL_FRAMEBUFFER, SK_ARRAY_COUNT(attachments),
                        attachments));
            }
            break;
        }
>>>>>>> miniblink49
    }
    renderTarget->flagAsResolved();
}

<<<<<<< HEAD
void GrGLGpu::clearStencil(GrRenderTarget* target)
{
    if (nullptr == target) {
=======

void GrGLGpu::clearStencil(GrRenderTarget* target) {
    if (NULL == target) {
>>>>>>> miniblink49
        return;
    }
    GrGLRenderTarget* glRT = static_cast<GrGLRenderTarget*>(target);
    this->flushRenderTarget(glRT, &SkIRect::EmptyIRect());

    this->disableScissor();

    GL_CALL(StencilMask(0xffffffff));
    GL_CALL(ClearStencil(0));
    GL_CALL(Clear(GR_GL_STENCIL_BUFFER_BIT));
    fHWStencilSettings.invalidate();
}

<<<<<<< HEAD
void GrGLGpu::clearStencilClip(const SkIRect& rect, bool insideClip, GrRenderTarget* target)
{
    SkASSERT(target);
    this->handleDirtyContext();
=======
void GrGLGpu::onClearStencilClip(GrRenderTarget* target, const SkIRect& rect, bool insideClip) {
    SkASSERT(target);
>>>>>>> miniblink49

    GrStencilAttachment* sb = target->renderTargetPriv().getStencilAttachment();
    // this should only be called internally when we know we have a
    // stencil buffer.
    SkASSERT(sb);
<<<<<<< HEAD
    GrGLint stencilBitCount = sb->bits();
=======
    GrGLint stencilBitCount =  sb->bits();
>>>>>>> miniblink49
#if 0
    SkASSERT(stencilBitCount > 0);
    GrGLint clipStencilMask  = (1 << (stencilBitCount - 1));
#else
    // we could just clear the clip bit but when we go through
    // ANGLE a partial stencil mask will cause clears to be
    // turned into draws. Our contract on GrDrawTarget says that
    // changing the clip between stencil passes may or may not
    // zero the client's clip bits. So we just clear the whole thing.
<<<<<<< HEAD
    static const GrGLint clipStencilMask = ~0;
=======
    static const GrGLint clipStencilMask  = ~0;
>>>>>>> miniblink49
#endif
    GrGLint value;
    if (insideClip) {
        value = (1 << (stencilBitCount - 1));
    } else {
        value = 0;
    }
    GrGLRenderTarget* glRT = static_cast<GrGLRenderTarget*>(target);
    this->flushRenderTarget(glRT, &SkIRect::EmptyIRect());

    GrScissorState scissorState;
    scissorState.set(rect);
    this->flushScissor(scissorState, glRT->getViewport(), glRT->origin());

<<<<<<< HEAD
    GL_CALL(StencilMask((uint32_t)clipStencilMask));
=======
    GL_CALL(StencilMask((uint32_t) clipStencilMask));
>>>>>>> miniblink49
    GL_CALL(ClearStencil(value));
    GL_CALL(Clear(GR_GL_STENCIL_BUFFER_BIT));
    fHWStencilSettings.invalidate();
}

<<<<<<< HEAD
static bool read_pixels_pays_for_y_flip(GrRenderTarget* renderTarget, const GrGLCaps& caps,
    int width, int height, GrPixelConfig config,
    size_t rowBytes)
{
    // If this render target is already TopLeft, we don't need to flip.
=======
bool GrGLGpu::readPixelsWillPayForYFlip(GrRenderTarget* renderTarget,
                                        int left, int top,
                                        int width, int height,
                                        GrPixelConfig config,
                                        size_t rowBytes) const {
    // If this rendertarget is aready TopLeft, we don't need to flip.
>>>>>>> miniblink49
    if (kTopLeft_GrSurfaceOrigin == renderTarget->origin()) {
        return false;
    }

<<<<<<< HEAD
    // If the read is really small or smaller than the min texture size, don't force a draw.
    static const int kMinSize = 32;
    if (width < kMinSize || height < kMinSize) {
        return false;
    }

    // if GL can do the flip then we'll never pay for it.
    if (caps.packFlipYSupport()) {
=======
    // if GL can do the flip then we'll never pay for it.
    if (this->glCaps().packFlipYSupport()) {
>>>>>>> miniblink49
        return false;
    }

    // If we have to do memcpy to handle non-trim rowBytes then we
    // get the flip for free. Otherwise it costs.
<<<<<<< HEAD
    // Note that we're assuming that 0 rowBytes has already been handled and that the width has been
    // clipped.
    return caps.packRowLengthSupport() || GrBytesPerPixel(config) * width == rowBytes;
}

bool GrGLGpu::readPixelsSupported(GrRenderTarget* target, GrPixelConfig readConfig)
{
    auto bindRenderTarget = [this, target]() -> bool {
        this->flushRenderTarget(static_cast<GrGLRenderTarget*>(target), &SkIRect::EmptyIRect());
        return true;
    };
    auto getIntegerv = [this](GrGLenum query, GrGLint* value) {
        GR_GL_GetIntegerv(this->glInterface(), query, value);
    };
    GrPixelConfig rtConfig = target->config();
    return this->glCaps().readPixelsSupported(rtConfig, readConfig, getIntegerv, bindRenderTarget);
}

bool GrGLGpu::readPixelsSupported(GrPixelConfig rtConfig, GrPixelConfig readConfig)
{
    auto bindRenderTarget = [this, rtConfig]() -> bool {
        GrTextureDesc desc;
        desc.fConfig = rtConfig;
        desc.fWidth = desc.fHeight = 16;
        desc.fFlags = kRenderTarget_GrSurfaceFlag;
        SkAutoTUnref<GrTexture> temp(this->createTexture(desc,
            SkBudgeted::kNo));
        if (!temp) {
            return false;
        }
        GrGLRenderTarget* glrt = static_cast<GrGLRenderTarget*>(temp->asRenderTarget());
        this->flushRenderTarget(glrt, &SkIRect::EmptyIRect());
        return true;
    };
    auto getIntegerv = [this](GrGLenum query, GrGLint* value) {
        GR_GL_GetIntegerv(this->glInterface(), query, value);
    };
    return this->glCaps().readPixelsSupported(rtConfig, readConfig, getIntegerv, bindRenderTarget);
}

bool GrGLGpu::readPixelsSupported(GrSurface* surfaceForConfig, GrPixelConfig readConfig)
{
    if (GrRenderTarget* rt = surfaceForConfig->asRenderTarget()) {
        return this->readPixelsSupported(rt, readConfig);
    } else {
        GrPixelConfig config = surfaceForConfig->config();
        return this->readPixelsSupported(config, readConfig);
    }
}

static bool requires_srgb_conversion(GrPixelConfig a, GrPixelConfig b)
{
    if (GrPixelConfigIsSRGB(a)) {
        return !GrPixelConfigIsSRGB(b) && !GrPixelConfigIsAlphaOnly(b);
    } else if (GrPixelConfigIsSRGB(b)) {
        return !GrPixelConfigIsSRGB(a) && !GrPixelConfigIsAlphaOnly(a);
    }
    return false;
}

bool GrGLGpu::onGetReadPixelsInfo(GrSurface* srcSurface, int width, int height, size_t rowBytes,
    GrPixelConfig readConfig, DrawPreference* drawPreference,
    ReadPixelTempDrawInfo* tempDrawInfo)
{
    GrPixelConfig srcConfig = srcSurface->config();

    // These settings we will always want if a temp draw is performed.
    tempDrawInfo->fTempSurfaceDesc.fFlags = kRenderTarget_GrSurfaceFlag;
    tempDrawInfo->fTempSurfaceDesc.fWidth = width;
    tempDrawInfo->fTempSurfaceDesc.fHeight = height;
    tempDrawInfo->fTempSurfaceDesc.fSampleCnt = 0;
    tempDrawInfo->fTempSurfaceDesc.fOrigin = kTopLeft_GrSurfaceOrigin; // no CPU y-flip for TL.
    tempDrawInfo->fUseExactScratch = this->glCaps().partialFBOReadIsSlow();

    // For now assume no swizzling, we may change that below.
    tempDrawInfo->fSwizzle = GrSwizzle::RGBA();

    // Depends on why we need/want a temp draw. Start off assuming no change, the surface we read
    // from will be srcConfig and we will read readConfig pixels from it.
    // Not that if we require a draw and return a non-renderable format for the temp surface the
    // base class will fail for us.
    tempDrawInfo->fTempSurfaceDesc.fConfig = srcConfig;
    tempDrawInfo->fReadConfig = readConfig;

    if (requires_srgb_conversion(srcConfig, readConfig)) {
        if (!this->readPixelsSupported(readConfig, readConfig)) {
            return false;
        }
        // Draw to do srgb to linear conversion or vice versa.
        ElevateDrawPreference(drawPreference, kRequireDraw_DrawPreference);
        tempDrawInfo->fTempSurfaceDesc.fConfig = readConfig;
        tempDrawInfo->fReadConfig = readConfig;
        return true;
    }

    GrRenderTarget* srcAsRT = srcSurface->asRenderTarget();
    if (!srcAsRT) {
        // For now keep assuming the draw is not a format transformation, just a draw to get to a
        // RT. We may add additional transformations below.
        ElevateDrawPreference(drawPreference, kRequireDraw_DrawPreference);
    }
    if (this->glCaps().rgba8888PixelsOpsAreSlow() && kRGBA_8888_GrPixelConfig == readConfig && this->readPixelsSupported(kBGRA_8888_GrPixelConfig, kBGRA_8888_GrPixelConfig)) {
        tempDrawInfo->fTempSurfaceDesc.fConfig = kBGRA_8888_GrPixelConfig;
        tempDrawInfo->fSwizzle = GrSwizzle::BGRA();
        tempDrawInfo->fReadConfig = kBGRA_8888_GrPixelConfig;
        ElevateDrawPreference(drawPreference, kGpuPrefersDraw_DrawPreference);
    } else if (this->glCaps().rgbaToBgraReadbackConversionsAreSlow() && GrBytesPerPixel(readConfig) == 4 && GrPixelConfigSwapRAndB(readConfig) == srcConfig && this->readPixelsSupported(srcSurface, srcConfig)) {
        // Mesa 3D takes a slow path on when reading back BGRA from an RGBA surface and vice-versa.
        // Better to do a draw with a R/B swap and then read as the original config.
        tempDrawInfo->fTempSurfaceDesc.fConfig = srcConfig;
        tempDrawInfo->fSwizzle = GrSwizzle::BGRA();
        tempDrawInfo->fReadConfig = srcConfig;
        ElevateDrawPreference(drawPreference, kGpuPrefersDraw_DrawPreference);
    } else if (!this->readPixelsSupported(srcSurface, readConfig)) {
        if (readConfig == kBGRA_8888_GrPixelConfig && this->glCaps().isConfigRenderable(kRGBA_8888_GrPixelConfig, false) && this->readPixelsSupported(kRGBA_8888_GrPixelConfig, kRGBA_8888_GrPixelConfig)) {
            // We're trying to read BGRA but it's not supported. If RGBA is renderable and
            // we can read it back, then do a swizzling draw to a RGBA and read it back (which
            // will effectively be BGRA).
            tempDrawInfo->fTempSurfaceDesc.fConfig = kRGBA_8888_GrPixelConfig;
            tempDrawInfo->fSwizzle = GrSwizzle::BGRA();
            tempDrawInfo->fReadConfig = kRGBA_8888_GrPixelConfig;
            ElevateDrawPreference(drawPreference, kRequireDraw_DrawPreference);
        } else if (readConfig == kSBGRA_8888_GrPixelConfig && this->glCaps().isConfigRenderable(kSRGBA_8888_GrPixelConfig, false) && this->readPixelsSupported(kSRGBA_8888_GrPixelConfig, kSRGBA_8888_GrPixelConfig)) {
            // We're trying to read sBGRA but it's not supported. If sRGBA is renderable and
            // we can read it back, then do a swizzling draw to a sRGBA and read it back (which
            // will effectively be sBGRA).
            tempDrawInfo->fTempSurfaceDesc.fConfig = kSRGBA_8888_GrPixelConfig;
            tempDrawInfo->fSwizzle = GrSwizzle::BGRA();
            tempDrawInfo->fReadConfig = kSRGBA_8888_GrPixelConfig;
            ElevateDrawPreference(drawPreference, kRequireDraw_DrawPreference);
        } else if (readConfig == kAlpha_8_GrPixelConfig) {
            // onReadPixels implements a fallback for cases where we are want to read kAlpha_8,
            // it's unsupported, but 32bit RGBA reads are supported.
            // Don't attempt to do any srgb conversions since we only care about alpha.
            GrPixelConfig cpuTempConfig = kRGBA_8888_GrPixelConfig;
            if (GrPixelConfigIsSRGB(srcSurface->config())) {
                cpuTempConfig = kSRGBA_8888_GrPixelConfig;
            }
            if (!this->readPixelsSupported(srcSurface, cpuTempConfig)) {
                // If we can't read RGBA from the src try to draw to a kRGBA_8888 (or kSRGBA_8888)
                // first and then onReadPixels will read that to a 32bit temporary buffer.
                if (this->caps()->isConfigRenderable(cpuTempConfig, false)) {
                    ElevateDrawPreference(drawPreference, kRequireDraw_DrawPreference);
                    tempDrawInfo->fTempSurfaceDesc.fConfig = cpuTempConfig;
                    tempDrawInfo->fReadConfig = kAlpha_8_GrPixelConfig;
                } else {
                    return false;
                }
            } else {
                SkASSERT(tempDrawInfo->fTempSurfaceDesc.fConfig == srcConfig);
                SkASSERT(tempDrawInfo->fReadConfig == kAlpha_8_GrPixelConfig);
            }
        } else if (this->caps()->isConfigRenderable(readConfig, false) && this->readPixelsSupported(readConfig, readConfig)) {
            // Do a draw to convert from the src config to the read config.
            ElevateDrawPreference(drawPreference, kRequireDraw_DrawPreference);
            tempDrawInfo->fTempSurfaceDesc.fConfig = readConfig;
            tempDrawInfo->fReadConfig = readConfig;
        } else {
            return false;
        }
    }

    if (srcAsRT && read_pixels_pays_for_y_flip(srcAsRT, this->glCaps(), width, height, readConfig, rowBytes)) {
        ElevateDrawPreference(drawPreference, kGpuPrefersDraw_DrawPreference);
    }

    return true;
}

bool GrGLGpu::onReadPixels(GrSurface* surface,
    int left, int top,
    int width, int height,
    GrPixelConfig config,
    void* buffer,
    size_t rowBytes)
{
    SkASSERT(surface);

    GrGLRenderTarget* renderTarget = static_cast<GrGLRenderTarget*>(surface->asRenderTarget());
    if (!renderTarget) {
        return false;
    }

    // OpenGL doesn't do sRGB <-> linear conversions when reading and writing pixels.
    if (requires_srgb_conversion(surface->config(), config)) {
        return false;
    }

    // We have a special case fallback for reading eight bit alpha. We will read back all four 8
    // bit channels as RGBA and then extract A.
    if (!this->readPixelsSupported(renderTarget, config)) {
        // Don't attempt to do any srgb conversions since we only care about alpha.
        GrPixelConfig tempConfig = kRGBA_8888_GrPixelConfig;
        if (GrPixelConfigIsSRGB(renderTarget->config())) {
            tempConfig = kSRGBA_8888_GrPixelConfig;
        }
        if (kAlpha_8_GrPixelConfig == config && this->readPixelsSupported(renderTarget, tempConfig)) {
            SkAutoTDeleteArray<uint32_t> temp(new uint32_t[width * height * 4]);
            if (this->onReadPixels(renderTarget, left, top, width, height, tempConfig, temp.get(),
                    width * 4)) {
                uint8_t* dst = reinterpret_cast<uint8_t*>(buffer);
                for (int j = 0; j < height; ++j) {
                    for (int i = 0; i < width; ++i) {
                        dst[j * rowBytes + i] = (0xFF000000U & temp[j * width + i]) >> 24;
                    }
                }
                return true;
            }
        }
        return false;
    }

    GrGLenum externalFormat;
    GrGLenum externalType;
    if (!this->glCaps().getReadPixelsFormat(renderTarget->config(), config, &externalFormat,
            &externalType)) {
        return false;
    }
    bool flipY = kBottomLeft_GrSurfaceOrigin == surface->origin();

    // resolve the render target if necessary
    switch (renderTarget->getResolveType()) {
    case GrGLRenderTarget::kCantResolve_ResolveType:
        return false;
    case GrGLRenderTarget::kAutoResolves_ResolveType:
        this->flushRenderTarget(renderTarget, &SkIRect::EmptyIRect());
        break;
    case GrGLRenderTarget::kCanResolve_ResolveType:
        this->onResolveRenderTarget(renderTarget);
        // we don't track the state of the READ FBO ID.
        fStats.incRenderTargetBinds();
        GL_CALL(BindFramebuffer(GR_GL_READ_FRAMEBUFFER, renderTarget->textureFBOID()));
        break;
    default:
        SkFAIL("Unknown resolve type");
    }

    const GrGLIRect& glvp = renderTarget->getViewport();

    // the read rect is viewport-relative
    GrGLIRect readRect;
    readRect.setRelativeTo(glvp, left, top, width, height, renderTarget->origin());

    size_t bytesPerPixel = GrBytesPerPixel(config);
    size_t tightRowBytes = bytesPerPixel * width;

=======
    if (this->glCaps().packRowLengthSupport()) {
        return true;
    }
    // If we have to do memcpys to handle rowBytes then y-flip is free
    // Note the rowBytes might be tight to the passed in data, but if data
    // gets clipped in x to the target the rowBytes will no longer be tight.
    if (left >= 0 && (left + width) < renderTarget->width()) {
           return 0 == rowBytes ||
                  GrBytesPerPixel(config) * width == rowBytes;
    } else {
        return false;
    }
}

bool GrGLGpu::onReadPixels(GrRenderTarget* target,
                           int left, int top,
                           int width, int height,
                           GrPixelConfig config,
                           void* buffer,
                           size_t rowBytes) {
    // We cannot read pixels into a compressed buffer
    if (GrPixelConfigIsCompressed(config)) {
        return false;
    }

    GrGLenum format = 0;
    GrGLenum type = 0;
    bool flipY = kBottomLeft_GrSurfaceOrigin == target->origin();
    if (!this->configToGLFormats(config, false, NULL, &format, &type)) {
        return false;
    }
    size_t bpp = GrBytesPerPixel(config);
    if (!adjust_pixel_ops_params(target->width(), target->height(), bpp,
                                 &left, &top, &width, &height,
                                 const_cast<const void**>(&buffer),
                                 &rowBytes)) {
        return false;
    }

    // resolve the render target if necessary
    GrGLRenderTarget* tgt = static_cast<GrGLRenderTarget*>(target);
    switch (tgt->getResolveType()) {
        case GrGLRenderTarget::kCantResolve_ResolveType:
            return false;
        case GrGLRenderTarget::kAutoResolves_ResolveType:
            this->flushRenderTarget(static_cast<GrGLRenderTarget*>(target), &SkIRect::EmptyIRect());
            break;
        case GrGLRenderTarget::kCanResolve_ResolveType:
            this->onResolveRenderTarget(tgt);
            // we don't track the state of the READ FBO ID.
            fStats.incRenderTargetBinds();
            GL_CALL(BindFramebuffer(GR_GL_READ_FRAMEBUFFER,
                                    tgt->textureFBOID()));
            break;
        default:
            SkFAIL("Unknown resolve type");
    }

    const GrGLIRect& glvp = tgt->getViewport();

    // the read rect is viewport-relative
    GrGLIRect readRect;
    readRect.setRelativeTo(glvp, left, top, width, height, target->origin());

    size_t tightRowBytes = bpp * width;
    if (0 == rowBytes) {
        rowBytes = tightRowBytes;
    }
>>>>>>> miniblink49
    size_t readDstRowBytes = tightRowBytes;
    void* readDst = buffer;

    // determine if GL can read using the passed rowBytes or if we need
    // a scratch buffer.
    SkAutoSMalloc<32 * sizeof(GrColor)> scratch;
    if (rowBytes != tightRowBytes) {
<<<<<<< HEAD
        if (this->glCaps().packRowLengthSupport() && !(rowBytes % bytesPerPixel)) {
            GL_CALL(PixelStorei(GR_GL_PACK_ROW_LENGTH,
                static_cast<GrGLint>(rowBytes / bytesPerPixel)));
=======
        if (this->glCaps().packRowLengthSupport()) {
            SkASSERT(!(rowBytes % sizeof(GrColor)));
            GL_CALL(PixelStorei(GR_GL_PACK_ROW_LENGTH,
                                static_cast<GrGLint>(rowBytes / sizeof(GrColor))));
>>>>>>> miniblink49
            readDstRowBytes = rowBytes;
        } else {
            scratch.reset(tightRowBytes * height);
            readDst = scratch.get();
        }
    }
    if (flipY && this->glCaps().packFlipYSupport()) {
        GL_CALL(PixelStorei(GR_GL_PACK_REVERSE_ROW_ORDER, 1));
    }
<<<<<<< HEAD
    GL_CALL(PixelStorei(GR_GL_PACK_ALIGNMENT, config_alignment(config)));

    GL_CALL(ReadPixels(readRect.fLeft, readRect.fBottom,
        readRect.fWidth, readRect.fHeight,
        externalFormat, externalType, readDst));
=======
    GL_CALL(ReadPixels(readRect.fLeft, readRect.fBottom,
                       readRect.fWidth, readRect.fHeight,
                       format, type, readDst));
>>>>>>> miniblink49
    if (readDstRowBytes != tightRowBytes) {
        SkASSERT(this->glCaps().packRowLengthSupport());
        GL_CALL(PixelStorei(GR_GL_PACK_ROW_LENGTH, 0));
    }
    if (flipY && this->glCaps().packFlipYSupport()) {
        GL_CALL(PixelStorei(GR_GL_PACK_REVERSE_ROW_ORDER, 0));
        flipY = false;
    }

    // now reverse the order of the rows, since GL's are bottom-to-top, but our
    // API presents top-to-bottom. We must preserve the padding contents. Note
    // that the above readPixels did not overwrite the padding.
    if (readDst == buffer) {
        SkASSERT(rowBytes == readDstRowBytes);
        if (flipY) {
            scratch.reset(tightRowBytes);
            void* tmpRow = scratch.get();
            // flip y in-place by rows
            const int halfY = height >> 1;
            char* top = reinterpret_cast<char*>(buffer);
            char* bottom = top + (height - 1) * rowBytes;
            for (int y = 0; y < halfY; y++) {
                memcpy(tmpRow, top, tightRowBytes);
                memcpy(top, bottom, tightRowBytes);
                memcpy(bottom, tmpRow, tightRowBytes);
                top += rowBytes;
                bottom -= rowBytes;
            }
        }
    } else {
<<<<<<< HEAD
        SkASSERT(readDst != buffer);
        SkASSERT(rowBytes != tightRowBytes);
=======
        SkASSERT(readDst != buffer);        SkASSERT(rowBytes != tightRowBytes);
>>>>>>> miniblink49
        // copy from readDst to buffer while flipping y
        // const int halfY = height >> 1;
        const char* src = reinterpret_cast<const char*>(readDst);
        char* dst = reinterpret_cast<char*>(buffer);
        if (flipY) {
<<<<<<< HEAD
            dst += (height - 1) * rowBytes;
=======
            dst += (height-1) * rowBytes;
>>>>>>> miniblink49
        }
        for (int y = 0; y < height; y++) {
            memcpy(dst, src, tightRowBytes);
            src += readDstRowBytes;
            if (!flipY) {
                dst += rowBytes;
            } else {
                dst -= rowBytes;
            }
        }
    }
    return true;
}

<<<<<<< HEAD
GrGpuCommandBuffer* GrGLGpu::createCommandBuffer(
    GrRenderTarget* target,
    const GrGpuCommandBuffer::LoadAndStoreInfo& colorInfo,
    const GrGpuCommandBuffer::LoadAndStoreInfo& stencilInfo)
{
    return new GrGLGpuCommandBuffer(this);
}

void GrGLGpu::finishDrawTarget()
{
    if (fPLSHasBeenUsed) {
        /* There is an ARM driver bug where if we use PLS, and then draw a frame which does not
         * use PLS, it leaves garbage all over the place. As a workaround, we use PLS in a
         * trivial way every frame. And since we use it every frame, there's never a point at which
         * it becomes safe to stop using this workaround once we start.
         */
        this->disableScissor();
        // using PLS in the presence of MSAA results in GL_INVALID_OPERATION
        this->flushHWAAState(nullptr, false, false);
        SkASSERT(!fHWPLSEnabled);
        SkASSERT(fMSAAEnabled != kYes_TriState);
        GL_CALL(Enable(GR_GL_SHADER_PIXEL_LOCAL_STORAGE));
        this->stampPLSSetupRect(SkRect::MakeXYWH(-100.0f, -100.0f, 0.01f, 0.01f));
        GL_CALL(Disable(GR_GL_SHADER_PIXEL_LOCAL_STORAGE));
    }
}

void GrGLGpu::flushRenderTarget(GrGLRenderTarget* target, const SkIRect* bounds, bool disableSRGB)
{
=======
void GrGLGpu::flushRenderTarget(GrGLRenderTarget* target, const SkIRect* bound) {

>>>>>>> miniblink49
    SkASSERT(target);

    uint32_t rtID = target->getUniqueID();
    if (fHWBoundRenderTargetUniqueID != rtID) {
        fStats.incRenderTargetBinds();
        GL_CALL(BindFramebuffer(GR_GL_FRAMEBUFFER, target->renderFBOID()));
#ifdef SK_DEBUG
        // don't do this check in Chromium -- this is causing
        // lots of repeated command buffer flushes when the compositor is
        // rendering with Ganesh, which is really slow; even too slow for
        // Debug mode.
        if (kChromium_GrGLDriver != this->glContext().driver()) {
            GrGLenum status;
            GL_CALL_RET(status, CheckFramebufferStatus(GR_GL_FRAMEBUFFER));
            if (status != GR_GL_FRAMEBUFFER_COMPLETE) {
                SkDebugf("GrGLGpu::flushRenderTarget glCheckFramebufferStatus %x\n", status);
            }
        }
#endif
        fHWBoundRenderTargetUniqueID = rtID;
<<<<<<< HEAD
        this->flushViewport(target->getViewport());
    }

    if (this->glCaps().srgbWriteControl()) {
        this->flushFramebufferSRGB(GrPixelConfigIsSRGB(target->config()) && !disableSRGB);
    }

    this->didWriteToSurface(target, bounds);
}

void GrGLGpu::flushFramebufferSRGB(bool enable)
{
    if (enable && kYes_TriState != fHWSRGBFramebuffer) {
        GL_CALL(Enable(GR_GL_FRAMEBUFFER_SRGB));
        fHWSRGBFramebuffer = kYes_TriState;
    } else if (!enable && kNo_TriState != fHWSRGBFramebuffer) {
        GL_CALL(Disable(GR_GL_FRAMEBUFFER_SRGB));
        fHWSRGBFramebuffer = kNo_TriState;
    }
}

void GrGLGpu::flushViewport(const GrGLIRect& viewport)
{
    if (fHWViewport != viewport) {
        viewport.pushToGLViewport(this->glInterface());
        fHWViewport = viewport;
=======
        const GrGLIRect& vp = target->getViewport();
        if (fHWViewport != vp) {
            vp.pushToGLViewport(this->glInterface());
            fHWViewport = vp;
        }
    }
    if (NULL == bound || !bound->isEmpty()) {
        target->flagAsNeedingResolve(bound);
    }

    GrTexture *texture = target->asTexture();
    if (texture) {
        texture->texturePriv().dirtyMipMaps(true);
>>>>>>> miniblink49
    }
}

GrGLenum gPrimitiveType2GLMode[] = {
    GR_GL_TRIANGLES,
    GR_GL_TRIANGLE_STRIP,
    GR_GL_TRIANGLE_FAN,
    GR_GL_POINTS,
    GR_GL_LINES,
    GR_GL_LINE_STRIP
};

#define SWAP_PER_DRAW 0

#if SWAP_PER_DRAW
<<<<<<< HEAD
#if defined(SK_BUILD_FOR_MAC)
#include <AGL/agl.h>
#elif defined(SK_BUILD_FOR_WIN32)
#include <gl/GL.h>
void SwapBuf()
{
    DWORD procID = GetCurrentProcessId();
    HWND hwnd = GetTopWindow(GetDesktopWindow());
    while (hwnd) {
        DWORD wndProcID = 0;
        GetWindowThreadProcessId(hwnd, &wndProcID);
        if (wndProcID == procID) {
            SwapBuffers(GetDC(hwnd));
        }
        hwnd = GetNextWindow(hwnd, GW_HWNDNEXT);
    }
}
#endif
#endif

void GrGLGpu::draw(const GrPipeline& pipeline,
    const GrPrimitiveProcessor& primProc,
    const GrMesh* meshes,
    int meshCount)
{
    this->handleDirtyContext();

    if (!this->flushGLState(pipeline, primProc)) {
        return;
    }
    GrPixelLocalStorageState plsState = primProc.getPixelLocalStorageState();
    if (!fHWPLSEnabled && plsState != GrPixelLocalStorageState::kDisabled_GrPixelLocalStorageState) {
        GL_CALL(Enable(GR_GL_SHADER_PIXEL_LOCAL_STORAGE));
        this->setupPixelLocalStorage(pipeline, primProc);
        fHWPLSEnabled = true;
    }
    if (plsState == GrPixelLocalStorageState::kFinish_GrPixelLocalStorageState) {
        GrStencilSettings stencil;
        stencil.setDisabled();
        this->flushStencil(stencil);
    }

    for (int i = 0; i < meshCount; ++i) {
        if (GrXferBarrierType barrierType = pipeline.xferBarrierType(*this->caps())) {
            this->xferBarrier(pipeline.getRenderTarget(), barrierType);
        }

        const GrMesh& mesh = meshes[i];
        GrMesh::Iterator iter;
        const GrNonInstancedMesh* nonIdxMesh = iter.init(mesh);
        do {
            size_t indexOffsetInBytes = 0;
            this->setupGeometry(primProc, *nonIdxMesh, &indexOffsetInBytes);
            if (nonIdxMesh->isIndexed()) {
                GrGLvoid* indices = reinterpret_cast<GrGLvoid*>(indexOffsetInBytes + sizeof(uint16_t) * nonIdxMesh->startIndex());
                // info.startVertex() was accounted for by setupGeometry.
                GL_CALL(DrawElements(gPrimitiveType2GLMode[nonIdxMesh->primitiveType()],
                    nonIdxMesh->indexCount(),
                    GR_GL_UNSIGNED_SHORT,
                    indices));
            } else {
                // Pass 0 for parameter first. We have to adjust glVertexAttribPointer() to account
                // for startVertex in the DrawElements case. So we always rely on setupGeometry to
                // have accounted for startVertex.
                GL_CALL(DrawArrays(gPrimitiveType2GLMode[nonIdxMesh->primitiveType()], 0,
                    nonIdxMesh->vertexCount()));
            }
            fStats.incNumDraws();
        } while ((nonIdxMesh = iter.next()));
    }

    if (fHWPLSEnabled && plsState == GrPixelLocalStorageState::kFinish_GrPixelLocalStorageState) {
        // PLS draws always involve multiple draws, finishing up with a non-PLS
        // draw that writes to the color buffer. That draw ends up here; we wait
        // until after it is complete to actually disable PLS.
        GL_CALL(Disable(GR_GL_SHADER_PIXEL_LOCAL_STORAGE));
        fHWPLSEnabled = false;
        this->disableScissor();
    }

#if SWAP_PER_DRAW
    glFlush();
#if defined(SK_BUILD_FOR_MAC)
    aglSwapBuffers(aglGetCurrentContext());
    int set_a_break_pt_here = 9;
    aglSwapBuffers(aglGetCurrentContext());
#elif defined(SK_BUILD_FOR_WIN32)
    SwapBuf();
    int set_a_break_pt_here = 9;
    SwapBuf();
#endif
#endif
}

void GrGLGpu::stampPLSSetupRect(const SkRect& bounds)
{
    SkASSERT(this->glCaps().glslCaps()->plsPathRenderingSupport())

        if (!fPLSSetupProgram.fProgram)
    {
        if (!this->createPLSSetupProgram()) {
            SkDebugf("Failed to create PLS setup program.\n");
            return;
        }
    }

    GL_CALL(UseProgram(fPLSSetupProgram.fProgram));
    this->fHWVertexArrayState.setVertexArrayID(this, 0);

    GrGLAttribArrayState* attribs = this->fHWVertexArrayState.bindInternalVertexArray(this);
    attribs->set(this, 0, fPLSSetupProgram.fArrayBuffer, kVec2f_GrVertexAttribType,
        2 * sizeof(GrGLfloat), 0);
    attribs->disableUnusedArrays(this, 0x1);

    GL_CALL(Uniform4f(fPLSSetupProgram.fPosXformUniform, bounds.width(), bounds.height(),
        bounds.left(), bounds.top()));

    GrXferProcessor::BlendInfo blendInfo;
    blendInfo.reset();
    this->flushBlend(blendInfo, GrSwizzle());
    this->flushColorWrite(true);
    this->flushDrawFace(GrPipelineBuilder::kBoth_DrawFace);
    if (!fHWStencilSettings.isDisabled()) {
        GL_CALL(Disable(GR_GL_STENCIL_TEST));
    }
    GL_CALL(DrawArrays(GR_GL_TRIANGLE_STRIP, 0, 4));
    GL_CALL(UseProgram(fHWProgramID));
    if (!fHWStencilSettings.isDisabled()) {
        GL_CALL(Enable(GR_GL_STENCIL_TEST));
    }
}

void GrGLGpu::setupPixelLocalStorage(const GrPipeline& pipeline,
    const GrPrimitiveProcessor& primProc)
{
    fPLSHasBeenUsed = true;
    const SkRect& bounds = static_cast<const GrPLSGeometryProcessor&>(primProc).getBounds();
    // setup pixel local storage -- this means capturing and storing the current framebuffer color
    // and initializing the winding counts to zero
    GrRenderTarget* rt = pipeline.getRenderTarget();
    SkScalar width = SkIntToScalar(rt->width());
    SkScalar height = SkIntToScalar(rt->height());
    // dst rect edges in NDC (-1 to 1)
    // having some issues with rounding, just expand the bounds by 1 and trust the scissor to keep
    // it contained properly
    GrGLfloat dx0 = 2.0f * (bounds.left() - 1) / width - 1.0f;
    GrGLfloat dx1 = 2.0f * (bounds.right() + 1) / width - 1.0f;
    GrGLfloat dy0 = -2.0f * (bounds.top() - 1) / height + 1.0f;
    GrGLfloat dy1 = -2.0f * (bounds.bottom() + 1) / height + 1.0f;
    SkRect deviceBounds = SkRect::MakeXYWH(dx0, dy0, dx1 - dx0, dy1 - dy0);

    GL_CALL(Enable(GR_GL_FETCH_PER_SAMPLE_ARM));
    this->stampPLSSetupRect(deviceBounds);
}

void GrGLGpu::onResolveRenderTarget(GrRenderTarget* target)
{
=======
    #if defined(SK_BUILD_FOR_MAC)
        #include <AGL/agl.h>
    #elif defined(SK_BUILD_FOR_WIN32)
        #include <gl/GL.h>
        void SwapBuf() {
            DWORD procID = GetCurrentProcessId();
            HWND hwnd = GetTopWindow(GetDesktopWindow());
            while(hwnd) {
                DWORD wndProcID = 0;
                GetWindowThreadProcessId(hwnd, &wndProcID);
                if(wndProcID == procID) {
                    SwapBuffers(GetDC(hwnd));
                }
                hwnd = GetNextWindow(hwnd, GW_HWNDNEXT);
            }
         }
    #endif
#endif

void GrGLGpu::onDraw(const DrawArgs& args, const GrNonInstancedVertices& vertices) {
    if (!this->flushGLState(args)) {
        return;
    }

    size_t indexOffsetInBytes = 0;
    this->setupGeometry(*args.fPrimitiveProcessor, vertices, &indexOffsetInBytes);

    SkASSERT((size_t)vertices.primitiveType() < SK_ARRAY_COUNT(gPrimitiveType2GLMode));

    if (vertices.isIndexed()) {
        GrGLvoid* indices =
            reinterpret_cast<GrGLvoid*>(indexOffsetInBytes + sizeof(uint16_t) *
                                        vertices.startIndex());
        // info.startVertex() was accounted for by setupGeometry.
        GL_CALL(DrawElements(gPrimitiveType2GLMode[vertices.primitiveType()],
                             vertices.indexCount(),
                             GR_GL_UNSIGNED_SHORT,
                             indices));
    } else {
        // Pass 0 for parameter first. We have to adjust glVertexAttribPointer() to account for
        // startVertex in the DrawElements case. So we always rely on setupGeometry to have
        // accounted for startVertex.
        GL_CALL(DrawArrays(gPrimitiveType2GLMode[vertices.primitiveType()], 0,
                           vertices.vertexCount()));
    }
#if SWAP_PER_DRAW
    glFlush();
    #if defined(SK_BUILD_FOR_MAC)
        aglSwapBuffers(aglGetCurrentContext());
        int set_a_break_pt_here = 9;
        aglSwapBuffers(aglGetCurrentContext());
    #elif defined(SK_BUILD_FOR_WIN32)
        SwapBuf();
        int set_a_break_pt_here = 9;
        SwapBuf();
    #endif
#endif
}

void GrGLGpu::onResolveRenderTarget(GrRenderTarget* target) {
>>>>>>> miniblink49
    GrGLRenderTarget* rt = static_cast<GrGLRenderTarget*>(target);
    if (rt->needsResolve()) {
        // Some extensions automatically resolves the texture when it is read.
        if (this->glCaps().usesMSAARenderBuffers()) {
            SkASSERT(rt->textureFBOID() != rt->renderFBOID());
            fStats.incRenderTargetBinds();
            fStats.incRenderTargetBinds();
            GL_CALL(BindFramebuffer(GR_GL_READ_FRAMEBUFFER, rt->renderFBOID()));
            GL_CALL(BindFramebuffer(GR_GL_DRAW_FRAMEBUFFER, rt->textureFBOID()));
            // make sure we go through flushRenderTarget() since we've modified
            // the bound DRAW FBO ID.
            fHWBoundRenderTargetUniqueID = SK_InvalidUniqueID;
            const GrGLIRect& vp = rt->getViewport();
            const SkIRect dirtyRect = rt->getResolveRect();

            if (GrGLCaps::kES_Apple_MSFBOType == this->glCaps().msFBOType()) {
                // Apple's extension uses the scissor as the blit bounds.
                GrScissorState scissorState;
                scissorState.set(dirtyRect);
                this->flushScissor(scissorState, vp, rt->origin());
                GL_CALL(ResolveMultisampleFramebuffer());
            } else {
                GrGLIRect r;
                r.setRelativeTo(vp, dirtyRect.fLeft, dirtyRect.fTop,
<<<<<<< HEAD
                    dirtyRect.width(), dirtyRect.height(), target->origin());
=======
                                dirtyRect.width(), dirtyRect.height(), target->origin());
>>>>>>> miniblink49

                int right = r.fLeft + r.fWidth;
                int top = r.fBottom + r.fHeight;

                // BlitFrameBuffer respects the scissor, so disable it.
                this->disableScissor();
                GL_CALL(BlitFramebuffer(r.fLeft, r.fBottom, right, top,
<<<<<<< HEAD
                    r.fLeft, r.fBottom, right, top,
                    GR_GL_COLOR_BUFFER_BIT, GR_GL_NEAREST));
=======
                                        r.fLeft, r.fBottom, right, top,
                                        GR_GL_COLOR_BUFFER_BIT, GR_GL_NEAREST));
>>>>>>> miniblink49
            }
        }
        rt->flagAsResolved();
    }
}

namespace {

<<<<<<< HEAD
GrGLenum gr_to_gl_stencil_op(GrStencilOp op)
{
    static const GrGLenum gTable[kGrStencilOpCount] = {
        GR_GL_KEEP, // kKeep
        GR_GL_ZERO, // kZero
        GR_GL_REPLACE, // kReplace
        GR_GL_INVERT, // kInvert
        GR_GL_INCR_WRAP, // kIncWrap
        GR_GL_DECR_WRAP, // kDecWrap
        GR_GL_INCR, // kIncClamp
        GR_GL_DECR, // kDecClamp
    };
    GR_STATIC_ASSERT(0 == (int)GrStencilOp::kKeep);
    GR_STATIC_ASSERT(1 == (int)GrStencilOp::kZero);
    GR_STATIC_ASSERT(2 == (int)GrStencilOp::kReplace);
    GR_STATIC_ASSERT(3 == (int)GrStencilOp::kInvert);
    GR_STATIC_ASSERT(4 == (int)GrStencilOp::kIncWrap);
    GR_STATIC_ASSERT(5 == (int)GrStencilOp::kDecWrap);
    GR_STATIC_ASSERT(6 == (int)GrStencilOp::kIncClamp);
    GR_STATIC_ASSERT(7 == (int)GrStencilOp::kDecClamp);
    SkASSERT(op < (GrStencilOp)kGrStencilOpCount);
    return gTable[(int)op];
}

void set_gl_stencil(const GrGLInterface* gl,
    const GrStencilSettings::Face& face,
    GrGLenum glFace)
{
    GrGLenum glFunc = GrToGLStencilFunc(face.fTest);
    GrGLenum glFailOp = gr_to_gl_stencil_op(face.fFailOp);
    GrGLenum glPassOp = gr_to_gl_stencil_op(face.fPassOp);

    GrGLint ref = face.fRef;
    GrGLint mask = face.fTestMask;
    GrGLint writeMask = face.fWriteMask;
=======

GrGLenum gr_to_gl_stencil_op(GrStencilOp op) {
    static const GrGLenum gTable[] = {
        GR_GL_KEEP,        // kKeep_StencilOp
        GR_GL_REPLACE,     // kReplace_StencilOp
        GR_GL_INCR_WRAP,   // kIncWrap_StencilOp
        GR_GL_INCR,        // kIncClamp_StencilOp
        GR_GL_DECR_WRAP,   // kDecWrap_StencilOp
        GR_GL_DECR,        // kDecClamp_StencilOp
        GR_GL_ZERO,        // kZero_StencilOp
        GR_GL_INVERT,      // kInvert_StencilOp
    };
    GR_STATIC_ASSERT(SK_ARRAY_COUNT(gTable) == kStencilOpCount);
    GR_STATIC_ASSERT(0 == kKeep_StencilOp);
    GR_STATIC_ASSERT(1 == kReplace_StencilOp);
    GR_STATIC_ASSERT(2 == kIncWrap_StencilOp);
    GR_STATIC_ASSERT(3 == kIncClamp_StencilOp);
    GR_STATIC_ASSERT(4 == kDecWrap_StencilOp);
    GR_STATIC_ASSERT(5 == kDecClamp_StencilOp);
    GR_STATIC_ASSERT(6 == kZero_StencilOp);
    GR_STATIC_ASSERT(7 == kInvert_StencilOp);
    SkASSERT((unsigned) op < kStencilOpCount);
    return gTable[op];
}

void set_gl_stencil(const GrGLInterface* gl,
                    const GrStencilSettings& settings,
                    GrGLenum glFace,
                    GrStencilSettings::Face grFace) {
    GrGLenum glFunc = GrToGLStencilFunc(settings.func(grFace));
    GrGLenum glFailOp = gr_to_gl_stencil_op(settings.failOp(grFace));
    GrGLenum glPassOp = gr_to_gl_stencil_op(settings.passOp(grFace));

    GrGLint ref = settings.funcRef(grFace);
    GrGLint mask = settings.funcMask(grFace);
    GrGLint writeMask = settings.writeMask(grFace);
>>>>>>> miniblink49

    if (GR_GL_FRONT_AND_BACK == glFace) {
        // we call the combined func just in case separate stencil is not
        // supported.
        GR_GL_CALL(gl, StencilFunc(glFunc, ref, mask));
        GR_GL_CALL(gl, StencilMask(writeMask));
<<<<<<< HEAD
        GR_GL_CALL(gl, StencilOp(glFailOp, GR_GL_KEEP, glPassOp));
    } else {
        GR_GL_CALL(gl, StencilFuncSeparate(glFace, glFunc, ref, mask));
        GR_GL_CALL(gl, StencilMaskSeparate(glFace, writeMask));
        GR_GL_CALL(gl, StencilOpSeparate(glFace, glFailOp, GR_GL_KEEP, glPassOp));
=======
        GR_GL_CALL(gl, StencilOp(glFailOp, glPassOp, glPassOp));
    } else {
        GR_GL_CALL(gl, StencilFuncSeparate(glFace, glFunc, ref, mask));
        GR_GL_CALL(gl, StencilMaskSeparate(glFace, writeMask));
        GR_GL_CALL(gl, StencilOpSeparate(glFace, glFailOp, glPassOp, glPassOp));
>>>>>>> miniblink49
    }
}
}

<<<<<<< HEAD
void GrGLGpu::flushStencil(const GrStencilSettings& stencilSettings)
{
=======
void GrGLGpu::flushStencil(const GrStencilSettings& stencilSettings) {
>>>>>>> miniblink49
    if (fHWStencilSettings != stencilSettings) {
        if (stencilSettings.isDisabled()) {
            if (kNo_TriState != fHWStencilTestEnabled) {
                GL_CALL(Disable(GR_GL_STENCIL_TEST));
                fHWStencilTestEnabled = kNo_TriState;
            }
        } else {
            if (kYes_TriState != fHWStencilTestEnabled) {
                GL_CALL(Enable(GR_GL_STENCIL_TEST));
                fHWStencilTestEnabled = kYes_TriState;
            }
        }
        if (!stencilSettings.isDisabled()) {
<<<<<<< HEAD
            if (stencilSettings.isTwoSided()) {
                SkASSERT(this->caps()->twoSidedStencilSupport());
                set_gl_stencil(this->glInterface(),
                    stencilSettings.front(),
                    GR_GL_FRONT);
                set_gl_stencil(this->glInterface(),
                    stencilSettings.back(),
                    GR_GL_BACK);
            } else {
                set_gl_stencil(this->glInterface(),
                    stencilSettings.front(),
                    GR_GL_FRONT_AND_BACK);
=======
            if (this->caps()->twoSidedStencilSupport()) {
                set_gl_stencil(this->glInterface(),
                               stencilSettings,
                               GR_GL_FRONT,
                               GrStencilSettings::kFront_Face);
                set_gl_stencil(this->glInterface(),
                               stencilSettings,
                               GR_GL_BACK,
                               GrStencilSettings::kBack_Face);
            } else {
                set_gl_stencil(this->glInterface(),
                               stencilSettings,
                               GR_GL_FRONT_AND_BACK,
                               GrStencilSettings::kFront_Face);
>>>>>>> miniblink49
            }
        }
        fHWStencilSettings = stencilSettings;
    }
}

<<<<<<< HEAD
void GrGLGpu::flushHWAAState(GrRenderTarget* rt, bool useHWAA, bool stencilEnabled)
{
    // rt is only optional if useHWAA is false.
    SkASSERT(rt || !useHWAA);
    SkASSERT(!useHWAA || rt->isStencilBufferMultisampled());

    if (this->caps()->multisampleDisableSupport()) {
=======
void GrGLGpu::flushHWAAState(GrRenderTarget* rt, bool useHWAA) {
    SkASSERT(!useHWAA || rt->isStencilBufferMultisampled());

    if (this->glCaps().multisampleDisableSupport()) {
>>>>>>> miniblink49
        if (useHWAA) {
            if (kYes_TriState != fMSAAEnabled) {
                GL_CALL(Enable(GR_GL_MULTISAMPLE));
                fMSAAEnabled = kYes_TriState;
            }
        } else {
            if (kNo_TriState != fMSAAEnabled) {
                GL_CALL(Disable(GR_GL_MULTISAMPLE));
                fMSAAEnabled = kNo_TriState;
            }
        }
    }
<<<<<<< HEAD

    if (0 != this->caps()->maxRasterSamples()) {
        if (useHWAA && rt->hasMixedSamples() && !stencilEnabled) {
            // Since stencil is disabled and we want more samples than are in the color buffer, we
            // need to tell the rasterizer explicitly how many to run.
            if (kYes_TriState != fHWRasterMultisampleEnabled) {
                GL_CALL(Enable(GR_GL_RASTER_MULTISAMPLE));
                fHWRasterMultisampleEnabled = kYes_TriState;
            }
            if (rt->numStencilSamples() != fHWNumRasterSamples) {
                SkASSERT(rt->numStencilSamples() <= this->caps()->maxRasterSamples());
                GL_CALL(RasterSamples(rt->numStencilSamples(), GR_GL_TRUE));
                fHWNumRasterSamples = rt->numStencilSamples();
            }
        } else {
            if (kNo_TriState != fHWRasterMultisampleEnabled) {
                GL_CALL(Disable(GR_GL_RASTER_MULTISAMPLE));
                fHWRasterMultisampleEnabled = kNo_TriState;
            }
        }
    } else {
        SkASSERT(!useHWAA || !rt->hasMixedSamples() || stencilEnabled);
    }
}

void GrGLGpu::flushBlend(const GrXferProcessor::BlendInfo& blendInfo, const GrSwizzle& swizzle)
{
=======
}

void GrGLGpu::flushBlend(const GrXferProcessor::BlendInfo& blendInfo) {
>>>>>>> miniblink49
    // Any optimization to disable blending should have already been applied and
    // tweaked the equation to "add" or "subtract", and the coeffs to (1, 0).

    GrBlendEquation equation = blendInfo.fEquation;
    GrBlendCoeff srcCoeff = blendInfo.fSrcBlend;
    GrBlendCoeff dstCoeff = blendInfo.fDstBlend;
<<<<<<< HEAD
    bool blendOff = (kAdd_GrBlendEquation == equation || kSubtract_GrBlendEquation == equation) && kOne_GrBlendCoeff == srcCoeff && kZero_GrBlendCoeff == dstCoeff;
    if (blendOff) {
        if (kNo_TriState != fHWBlendState.fEnabled) {
            GL_CALL(Disable(GR_GL_BLEND));

            // Workaround for the ARM KHR_blend_equation_advanced blacklist issue
            // https://code.google.com/p/skia/issues/detail?id=3943
            if (kARM_GrGLVendor == this->ctxInfo().vendor() && GrBlendEquationIsAdvanced(fHWBlendState.fEquation)) {
                SkASSERT(this->caps()->advancedBlendEquationSupport());
                // Set to any basic blending equation.
                GrBlendEquation blend_equation = kAdd_GrBlendEquation;
                GL_CALL(BlendEquation(gXfermodeEquation2Blend[blend_equation]));
                fHWBlendState.fEquation = blend_equation;
            }

=======
    bool blendOff = (kAdd_GrBlendEquation == equation || kSubtract_GrBlendEquation == equation) &&
                    kOne_GrBlendCoeff == srcCoeff && kZero_GrBlendCoeff == dstCoeff;
    if (blendOff) {
        if (kNo_TriState != fHWBlendState.fEnabled) {
            GL_CALL(Disable(GR_GL_BLEND));
>>>>>>> miniblink49
            fHWBlendState.fEnabled = kNo_TriState;
        }
        return;
    }

    if (kYes_TriState != fHWBlendState.fEnabled) {
        GL_CALL(Enable(GR_GL_BLEND));
        fHWBlendState.fEnabled = kYes_TriState;
    }

    if (fHWBlendState.fEquation != equation) {
        GL_CALL(BlendEquation(gXfermodeEquation2Blend[equation]));
        fHWBlendState.fEquation = equation;
    }

    if (GrBlendEquationIsAdvanced(equation)) {
        SkASSERT(this->caps()->advancedBlendEquationSupport());
        // Advanced equations have no other blend state.
        return;
    }

<<<<<<< HEAD
    if (fHWBlendState.fSrcCoeff != srcCoeff || fHWBlendState.fDstCoeff != dstCoeff) {
        GL_CALL(BlendFunc(gXfermodeCoeff2Blend[srcCoeff],
            gXfermodeCoeff2Blend[dstCoeff]));
=======
    if (fHWBlendState.fSrcCoeff != srcCoeff ||
        fHWBlendState.fDstCoeff != dstCoeff) {
        GL_CALL(BlendFunc(gXfermodeCoeff2Blend[srcCoeff],
                          gXfermodeCoeff2Blend[dstCoeff]));
>>>>>>> miniblink49
        fHWBlendState.fSrcCoeff = srcCoeff;
        fHWBlendState.fDstCoeff = dstCoeff;
    }

<<<<<<< HEAD
    if ((BlendCoeffReferencesConstant(srcCoeff) || BlendCoeffReferencesConstant(dstCoeff))) {
        GrColor blendConst = blendInfo.fBlendConstant;
        blendConst = swizzle.applyTo(blendConst);
        if (!fHWBlendState.fConstColorValid || fHWBlendState.fConstColor != blendConst) {
            GrGLfloat c[4];
            GrColorToRGBAFloat(blendConst, c);
            GL_CALL(BlendColor(c[0], c[1], c[2], c[3]));
            fHWBlendState.fConstColor = blendConst;
            fHWBlendState.fConstColorValid = true;
        }
    }
}

static inline GrGLenum tile_to_gl_wrap(SkShader::TileMode tm)
{
=======
    GrColor blendConst = blendInfo.fBlendConstant;
    if ((BlendCoeffReferencesConstant(srcCoeff) ||
         BlendCoeffReferencesConstant(dstCoeff)) &&
        (!fHWBlendState.fConstColorValid ||
         fHWBlendState.fConstColor != blendConst)) {
        GrGLfloat c[4];
        GrColorToRGBAFloat(blendConst, c);
        GL_CALL(BlendColor(c[0], c[1], c[2], c[3]));
        fHWBlendState.fConstColor = blendConst;
        fHWBlendState.fConstColorValid = true;
    }
}

static inline GrGLenum tile_to_gl_wrap(SkShader::TileMode tm) {
>>>>>>> miniblink49
    static const GrGLenum gWrapModes[] = {
        GR_GL_CLAMP_TO_EDGE,
        GR_GL_REPEAT,
        GR_GL_MIRRORED_REPEAT
    };
    GR_STATIC_ASSERT(SkShader::kTileModeCount == SK_ARRAY_COUNT(gWrapModes));
    GR_STATIC_ASSERT(0 == SkShader::kClamp_TileMode);
    GR_STATIC_ASSERT(1 == SkShader::kRepeat_TileMode);
    GR_STATIC_ASSERT(2 == SkShader::kMirror_TileMode);
    return gWrapModes[tm];
}

<<<<<<< HEAD
static GrGLenum get_component_enum_from_char(char component)
{
    switch (component) {
    case 'r':
        return GR_GL_RED;
    case 'g':
        return GR_GL_GREEN;
    case 'b':
        return GR_GL_BLUE;
    case 'a':
        return GR_GL_ALPHA;
    default:
        SkFAIL("Unsupported component");
        return 0;
    }
}

/** If texture swizzling is available using tex parameters then it is preferred over mangling
  the generated shader code. This potentially allows greater reuse of cached shaders. */
static void get_tex_param_swizzle(GrPixelConfig config,
    const GrGLCaps& caps,
    GrGLenum* glSwizzle)
{
    const GrSwizzle& swizzle = caps.configSwizzle(config);
    for (int i = 0; i < 4; ++i) {
        glSwizzle[i] = get_component_enum_from_char(swizzle.c_str()[i]);
    }
}

void GrGLGpu::bindTexture(int unitIdx, const GrTextureParams& params, bool allowSRGBInputs,
    GrGLTexture* texture)
{
    SkASSERT(texture);

#ifdef SK_DEBUG
    if (!this->caps()->npotTextureTileSupport()) {
        const bool tileX = SkShader::kClamp_TileMode != params.getTileModeX();
        const bool tileY = SkShader::kClamp_TileMode != params.getTileModeY();
        if (tileX || tileY) {
            const int w = texture->width();
            const int h = texture->height();
            SkASSERT(SkIsPow2(w) && SkIsPow2(h));
        }
    }
#endif

=======
void GrGLGpu::bindTexture(int unitIdx, const GrTextureParams& params, GrGLTexture* texture) {
    SkASSERT(texture);

>>>>>>> miniblink49
    // If we created a rt/tex and rendered to it without using a texture and now we're texturing
    // from the rt it will still be the last bound texture, but it needs resolving. So keep this
    // out of the "last != next" check.
    GrGLRenderTarget* texRT = static_cast<GrGLRenderTarget*>(texture->asRenderTarget());
    if (texRT) {
        this->onResolveRenderTarget(texRT);
    }

    uint32_t textureID = texture->getUniqueID();
<<<<<<< HEAD
    GrGLenum target = texture->target();
    if (fHWBoundTextureUniqueIDs[unitIdx] != textureID) {
        this->setTextureUnit(unitIdx);
        GL_CALL(BindTexture(target, texture->textureID()));
=======
    if (fHWBoundTextureUniqueIDs[unitIdx] != textureID) {
        this->setTextureUnit(unitIdx);
        GL_CALL(BindTexture(GR_GL_TEXTURE_2D, texture->textureID()));
>>>>>>> miniblink49
        fHWBoundTextureUniqueIDs[unitIdx] = textureID;
    }

    ResetTimestamp timestamp;
    const GrGLTexture::TexParams& oldTexParams = texture->getCachedTexParams(&timestamp);
    bool setAll = timestamp < this->getResetTimestamp();
    GrGLTexture::TexParams newTexParams;

    static GrGLenum glMinFilterModes[] = {
        GR_GL_NEAREST,
        GR_GL_LINEAR,
        GR_GL_LINEAR_MIPMAP_LINEAR
    };
    static GrGLenum glMagFilterModes[] = {
        GR_GL_NEAREST,
        GR_GL_LINEAR,
        GR_GL_LINEAR
    };
    GrTextureParams::FilterMode filterMode = params.filterMode();

    if (GrTextureParams::kMipMap_FilterMode == filterMode) {
        if (!this->caps()->mipMapSupport() || GrPixelConfigIsCompressed(texture->config())) {
            filterMode = GrTextureParams::kBilerp_FilterMode;
        }
    }

    newTexParams.fMinFilter = glMinFilterModes[filterMode];
    newTexParams.fMagFilter = glMagFilterModes[filterMode];

<<<<<<< HEAD
    if (GrPixelConfigIsSRGB(texture->config())) {
        newTexParams.fSRGBDecode = allowSRGBInputs ? GR_GL_DECODE_EXT : GR_GL_SKIP_DECODE_EXT;
        if (setAll || newTexParams.fSRGBDecode != oldTexParams.fSRGBDecode) {
            this->setTextureUnit(unitIdx);
            GL_CALL(TexParameteri(target, GR_GL_TEXTURE_SRGB_DECODE_EXT, newTexParams.fSRGBDecode));
        }
    }

#ifdef SK_DEBUG
    // We were supposed to ensure MipMaps were up-to-date and built correctly before getting here.
    if (GrTextureParams::kMipMap_FilterMode == filterMode) {
        SkASSERT(!texture->texturePriv().mipMapsAreDirty());
        if (GrPixelConfigIsSRGB(texture->config())) {
            SkSourceGammaTreatment gammaTreatment = allowSRGBInputs ? SkSourceGammaTreatment::kRespect : SkSourceGammaTreatment::kIgnore;
            SkASSERT(texture->texturePriv().gammaTreatment() == gammaTreatment);
        }
    }
#endif

    newTexParams.fMaxMipMapLevel = texture->texturePriv().maxMipMapLevel();

    newTexParams.fWrapS = tile_to_gl_wrap(params.getTileModeX());
    newTexParams.fWrapT = tile_to_gl_wrap(params.getTileModeY());
    get_tex_param_swizzle(texture->config(), this->glCaps(), newTexParams.fSwizzleRGBA);
    if (setAll || newTexParams.fMagFilter != oldTexParams.fMagFilter) {
        this->setTextureUnit(unitIdx);
        GL_CALL(TexParameteri(target, GR_GL_TEXTURE_MAG_FILTER, newTexParams.fMagFilter));
    }
    if (setAll || newTexParams.fMinFilter != oldTexParams.fMinFilter) {
        this->setTextureUnit(unitIdx);
        GL_CALL(TexParameteri(target, GR_GL_TEXTURE_MIN_FILTER, newTexParams.fMinFilter));
    }
    if (setAll || newTexParams.fMaxMipMapLevel != oldTexParams.fMaxMipMapLevel) {
        // These are not supported in ES2 contexts
        if (this->glCaps().mipMapLevelAndLodControlSupport()) {
            if (newTexParams.fMaxMipMapLevel != 0) {
                this->setTextureUnit(unitIdx);
                GL_CALL(TexParameteri(target, GR_GL_TEXTURE_MIN_LOD, 0));
                GL_CALL(TexParameteri(target, GR_GL_TEXTURE_BASE_LEVEL, 0));
                GL_CALL(TexParameteri(target, GR_GL_TEXTURE_MAX_LOD,
                    newTexParams.fMaxMipMapLevel));
                GL_CALL(TexParameteri(target, GR_GL_TEXTURE_MAX_LEVEL,
                    newTexParams.fMaxMipMapLevel));
            }
        }
    }
    if (setAll || newTexParams.fWrapS != oldTexParams.fWrapS) {
        this->setTextureUnit(unitIdx);
        GL_CALL(TexParameteri(target, GR_GL_TEXTURE_WRAP_S, newTexParams.fWrapS));
    }
    if (setAll || newTexParams.fWrapT != oldTexParams.fWrapT) {
        this->setTextureUnit(unitIdx);
        GL_CALL(TexParameteri(target, GR_GL_TEXTURE_WRAP_T, newTexParams.fWrapT));
    }
    if (this->glCaps().textureSwizzleSupport() && (setAll || memcmp(newTexParams.fSwizzleRGBA, oldTexParams.fSwizzleRGBA, sizeof(newTexParams.fSwizzleRGBA)))) {
        this->setTextureSwizzle(unitIdx, target, newTexParams.fSwizzleRGBA);
=======
    if (GrTextureParams::kMipMap_FilterMode == filterMode &&
        texture->texturePriv().mipMapsAreDirty()) {
        GL_CALL(GenerateMipmap(GR_GL_TEXTURE_2D));
        texture->texturePriv().dirtyMipMaps(false);
    }

    newTexParams.fWrapS = tile_to_gl_wrap(params.getTileModeX());
    newTexParams.fWrapT = tile_to_gl_wrap(params.getTileModeY());
    memcpy(newTexParams.fSwizzleRGBA,
           GrGLShaderBuilder::GetTexParamSwizzle(texture->config(), this->glCaps()),
           sizeof(newTexParams.fSwizzleRGBA));
    if (setAll || newTexParams.fMagFilter != oldTexParams.fMagFilter) {
        this->setTextureUnit(unitIdx);
        GL_CALL(TexParameteri(GR_GL_TEXTURE_2D,
                              GR_GL_TEXTURE_MAG_FILTER,
                              newTexParams.fMagFilter));
    }
    if (setAll || newTexParams.fMinFilter != oldTexParams.fMinFilter) {
        this->setTextureUnit(unitIdx);
        GL_CALL(TexParameteri(GR_GL_TEXTURE_2D,
                              GR_GL_TEXTURE_MIN_FILTER,
                              newTexParams.fMinFilter));
    }
    if (setAll || newTexParams.fWrapS != oldTexParams.fWrapS) {
        this->setTextureUnit(unitIdx);
        GL_CALL(TexParameteri(GR_GL_TEXTURE_2D,
                              GR_GL_TEXTURE_WRAP_S,
                              newTexParams.fWrapS));
    }
    if (setAll || newTexParams.fWrapT != oldTexParams.fWrapT) {
        this->setTextureUnit(unitIdx);
        GL_CALL(TexParameteri(GR_GL_TEXTURE_2D,
                              GR_GL_TEXTURE_WRAP_T,
                              newTexParams.fWrapT));
    }
    if (this->glCaps().textureSwizzleSupport() &&
        (setAll || memcmp(newTexParams.fSwizzleRGBA,
                          oldTexParams.fSwizzleRGBA,
                          sizeof(newTexParams.fSwizzleRGBA)))) {
        this->setTextureUnit(unitIdx);
        if (this->glStandard() == kGLES_GrGLStandard) {
            // ES3 added swizzle support but not GL_TEXTURE_SWIZZLE_RGBA.
            const GrGLenum* swizzle = newTexParams.fSwizzleRGBA;
            GL_CALL(TexParameteri(GR_GL_TEXTURE_2D, GR_GL_TEXTURE_SWIZZLE_R, swizzle[0]));
            GL_CALL(TexParameteri(GR_GL_TEXTURE_2D, GR_GL_TEXTURE_SWIZZLE_G, swizzle[1]));
            GL_CALL(TexParameteri(GR_GL_TEXTURE_2D, GR_GL_TEXTURE_SWIZZLE_B, swizzle[2]));
            GL_CALL(TexParameteri(GR_GL_TEXTURE_2D, GR_GL_TEXTURE_SWIZZLE_A, swizzle[3]));
        } else {
            GR_STATIC_ASSERT(sizeof(newTexParams.fSwizzleRGBA[0]) == sizeof(GrGLint));
            const GrGLint* swizzle = reinterpret_cast<const GrGLint*>(newTexParams.fSwizzleRGBA);
            GL_CALL(TexParameteriv(GR_GL_TEXTURE_2D, GR_GL_TEXTURE_SWIZZLE_RGBA, swizzle));
        }
>>>>>>> miniblink49
    }
    texture->setCachedTexParams(newTexParams, this->getResetTimestamp());
}

<<<<<<< HEAD
void GrGLGpu::bindTexelBuffer(int unitIdx, GrPixelConfig texelConfig, GrGLBuffer* buffer)
{
    SkASSERT(this->glCaps().canUseConfigWithTexelBuffer(texelConfig));
    SkASSERT(unitIdx >= 0 && unitIdx < fHWBufferTextures.count());

    BufferTexture& buffTex = fHWBufferTextures[unitIdx];

    if (!buffTex.fKnownBound) {
        if (!buffTex.fTextureID) {
            GL_CALL(GenTextures(1, &buffTex.fTextureID));
            if (!buffTex.fTextureID) {
                return;
            }
        }

        this->setTextureUnit(unitIdx);
        GL_CALL(BindTexture(GR_GL_TEXTURE_BUFFER, buffTex.fTextureID));

        buffTex.fKnownBound = true;
    }

    if (buffer->getUniqueID() != buffTex.fAttachedBufferUniqueID || buffTex.fTexelConfig != texelConfig) {

        this->setTextureUnit(unitIdx);
        GL_CALL(TexBuffer(GR_GL_TEXTURE_BUFFER,
            this->glCaps().configSizedInternalFormat(texelConfig),
            buffer->bufferID()));

        buffTex.fTexelConfig = texelConfig;
        buffTex.fAttachedBufferUniqueID = buffer->getUniqueID();

        if (this->glCaps().textureSwizzleSupport() && this->glCaps().configSwizzle(texelConfig) != buffTex.fSwizzle) {
            GrGLenum glSwizzle[4];
            get_tex_param_swizzle(texelConfig, this->glCaps(), glSwizzle);
            this->setTextureSwizzle(unitIdx, GR_GL_TEXTURE_BUFFER, glSwizzle);
            buffTex.fSwizzle = this->glCaps().configSwizzle(texelConfig);
        }

        buffer->setHasAttachedToTexture();
        fHWMaxUsedBufferTextureUnit = SkTMax(unitIdx, fHWMaxUsedBufferTextureUnit);
    }
}

void GrGLGpu::generateMipmaps(const GrTextureParams& params, bool allowSRGBInputs,
    GrGLTexture* texture)
{
    SkASSERT(texture);

    // First, figure out if we need mips for this texture at all:
    GrTextureParams::FilterMode filterMode = params.filterMode();

    if (GrTextureParams::kMipMap_FilterMode == filterMode) {
        if (!this->caps()->mipMapSupport() || GrPixelConfigIsCompressed(texture->config())) {
            filterMode = GrTextureParams::kBilerp_FilterMode;
        }
    }

    if (GrTextureParams::kMipMap_FilterMode != filterMode) {
        return;
    }

    // If this is an sRGB texture and the mips were previously built the "other" way
    // (gamma-correct vs. not), then we need to rebuild them. We don't need to check for
    // srgbSupport - we'll *never* get an sRGB pixel config if we don't support it.
    SkSourceGammaTreatment gammaTreatment = allowSRGBInputs
        ? SkSourceGammaTreatment::kRespect
        : SkSourceGammaTreatment::kIgnore;
    if (GrPixelConfigIsSRGB(texture->config()) && gammaTreatment != texture->texturePriv().gammaTreatment()) {
        texture->texturePriv().dirtyMipMaps(true);
    }

    // If the mips aren't dirty, we're done:
    if (!texture->texturePriv().mipMapsAreDirty()) {
        return;
    }

    // If we created a rt/tex and rendered to it without using a texture and now we're texturing
    // from the rt it will still be the last bound texture, but it needs resolving.
    GrGLRenderTarget* texRT = static_cast<GrGLRenderTarget*>(texture->asRenderTarget());
    if (texRT) {
        this->onResolveRenderTarget(texRT);
    }

    GrGLenum target = texture->target();
    this->setScratchTextureUnit();
    GL_CALL(BindTexture(target, texture->textureID()));

    // Configure sRGB decode, if necessary. This state is the only thing needed for the driver
    // call (glGenerateMipmap) to work correctly. Our manual method dirties other state, too.
    if (GrPixelConfigIsSRGB(texture->config())) {
        GL_CALL(TexParameteri(target, GR_GL_TEXTURE_SRGB_DECODE_EXT,
            allowSRGBInputs ? GR_GL_DECODE_EXT : GR_GL_SKIP_DECODE_EXT));
    }

    // Either do manual mipmap generation or (if that fails), just rely on the driver:
    if (!this->generateMipmap(texture, allowSRGBInputs)) {
        GL_CALL(GenerateMipmap(target));
    }

    texture->texturePriv().dirtyMipMaps(false);
    texture->texturePriv().setMaxMipMapLevel(SkMipMap::ComputeLevelCount(
        texture->width(), texture->height()));
    texture->texturePriv().setGammaTreatment(gammaTreatment);

    // We have potentially set lots of state on the texture. Easiest to dirty it all:
    texture->textureParamsModified();
}

void GrGLGpu::setTextureSwizzle(int unitIdx, GrGLenum target, const GrGLenum swizzle[])
{
    this->setTextureUnit(unitIdx);
    if (this->glStandard() == kGLES_GrGLStandard) {
        // ES3 added swizzle support but not GL_TEXTURE_SWIZZLE_RGBA.
        GL_CALL(TexParameteri(target, GR_GL_TEXTURE_SWIZZLE_R, swizzle[0]));
        GL_CALL(TexParameteri(target, GR_GL_TEXTURE_SWIZZLE_G, swizzle[1]));
        GL_CALL(TexParameteri(target, GR_GL_TEXTURE_SWIZZLE_B, swizzle[2]));
        GL_CALL(TexParameteri(target, GR_GL_TEXTURE_SWIZZLE_A, swizzle[3]));
    } else {
        GR_STATIC_ASSERT(sizeof(swizzle[0]) == sizeof(GrGLint));
        GL_CALL(TexParameteriv(target, GR_GL_TEXTURE_SWIZZLE_RGBA,
            reinterpret_cast<const GrGLint*>(swizzle)));
    }
}

void GrGLGpu::flushColorWrite(bool writeColor)
{
    if (!writeColor) {
        if (kNo_TriState != fHWWriteToColor) {
            GL_CALL(ColorMask(GR_GL_FALSE, GR_GL_FALSE,
                GR_GL_FALSE, GR_GL_FALSE));
=======
void GrGLGpu::flushDither(bool dither) {
    if (dither) {
        if (kYes_TriState != fHWDitherEnabled) {
            GL_CALL(Enable(GR_GL_DITHER));
            fHWDitherEnabled = kYes_TriState;
        }
    } else {
        if (kNo_TriState != fHWDitherEnabled) {
            GL_CALL(Disable(GR_GL_DITHER));
            fHWDitherEnabled = kNo_TriState;
        }
    }
}

void GrGLGpu::flushColorWrite(bool writeColor) {
    if (!writeColor) {
        if (kNo_TriState != fHWWriteToColor) {
            GL_CALL(ColorMask(GR_GL_FALSE, GR_GL_FALSE,
                              GR_GL_FALSE, GR_GL_FALSE));
>>>>>>> miniblink49
            fHWWriteToColor = kNo_TriState;
        }
    } else {
        if (kYes_TriState != fHWWriteToColor) {
            GL_CALL(ColorMask(GR_GL_TRUE, GR_GL_TRUE, GR_GL_TRUE, GR_GL_TRUE));
            fHWWriteToColor = kYes_TriState;
        }
    }
}

<<<<<<< HEAD
void GrGLGpu::flushDrawFace(GrPipelineBuilder::DrawFace face)
{
    if (fHWDrawFace != face) {
        switch (face) {
        case GrPipelineBuilder::kCCW_DrawFace:
            GL_CALL(Enable(GR_GL_CULL_FACE));
            GL_CALL(CullFace(GR_GL_BACK));
            break;
        case GrPipelineBuilder::kCW_DrawFace:
            GL_CALL(Enable(GR_GL_CULL_FACE));
            GL_CALL(CullFace(GR_GL_FRONT));
            break;
        case GrPipelineBuilder::kBoth_DrawFace:
            GL_CALL(Disable(GR_GL_CULL_FACE));
            break;
        default:
            SkFAIL("Unknown draw face.");
=======
void GrGLGpu::flushDrawFace(GrPipelineBuilder::DrawFace face) {
    if (fHWDrawFace != face) {
        switch (face) {
            case GrPipelineBuilder::kCCW_DrawFace:
                GL_CALL(Enable(GR_GL_CULL_FACE));
                GL_CALL(CullFace(GR_GL_BACK));
                break;
            case GrPipelineBuilder::kCW_DrawFace:
                GL_CALL(Enable(GR_GL_CULL_FACE));
                GL_CALL(CullFace(GR_GL_FRONT));
                break;
            case GrPipelineBuilder::kBoth_DrawFace:
                GL_CALL(Disable(GR_GL_CULL_FACE));
                break;
            default:
                SkFAIL("Unknown draw face.");
>>>>>>> miniblink49
        }
        fHWDrawFace = face;
    }
}

<<<<<<< HEAD
void GrGLGpu::setTextureUnit(int unit)
{
=======
bool GrGLGpu::configToGLFormats(GrPixelConfig config,
                                bool getSizedInternalFormat,
                                GrGLenum* internalFormat,
                                GrGLenum* externalFormat,
                                GrGLenum* externalType) {
    GrGLenum dontCare;
    if (NULL == internalFormat) {
        internalFormat = &dontCare;
    }
    if (NULL == externalFormat) {
        externalFormat = &dontCare;
    }
    if (NULL == externalType) {
        externalType = &dontCare;
    }

    if(!this->glCaps().isConfigTexturable(config)) {
        return false;
    }

    switch (config) {
        case kRGBA_8888_GrPixelConfig:
            *internalFormat = GR_GL_RGBA;
            *externalFormat = GR_GL_RGBA;
            if (getSizedInternalFormat) {
                *internalFormat = GR_GL_RGBA8;
            } else {
                *internalFormat = GR_GL_RGBA;
            }
            *externalType = GR_GL_UNSIGNED_BYTE;
            break;
        case kBGRA_8888_GrPixelConfig:
            if (this->glCaps().bgraIsInternalFormat()) {
                if (getSizedInternalFormat) {
                    *internalFormat = GR_GL_BGRA8;
                } else {
                    *internalFormat = GR_GL_BGRA;
                }
            } else {
                if (getSizedInternalFormat) {
                    *internalFormat = GR_GL_RGBA8;
                } else {
                    *internalFormat = GR_GL_RGBA;
                }
            }
            *externalFormat = GR_GL_BGRA;
            *externalType = GR_GL_UNSIGNED_BYTE;
            break;
        case kSRGBA_8888_GrPixelConfig:
            *internalFormat = GR_GL_SRGB_ALPHA;
            *externalFormat = GR_GL_SRGB_ALPHA;
            if (getSizedInternalFormat || kGL_GrGLStandard == this->glStandard()) {
                // desktop or ES 3.0
                SkASSERT(this->glVersion() >= GR_GL_VER(3, 0));
                *internalFormat = GR_GL_SRGB8_ALPHA8;
                *externalFormat = GR_GL_RGBA;
            } else {
                // ES 2.0 with EXT_sRGB
                SkASSERT(kGL_GrGLStandard != this->glStandard() && 
                         this->glVersion() < GR_GL_VER(3, 0));
                *internalFormat = GR_GL_SRGB_ALPHA;
                *externalFormat = GR_GL_SRGB_ALPHA;
            }
            *externalType = GR_GL_UNSIGNED_BYTE;
            break;
        case kRGB_565_GrPixelConfig:
            *internalFormat = GR_GL_RGB;
            *externalFormat = GR_GL_RGB;
            if (getSizedInternalFormat) {
                if (!this->glCaps().ES2CompatibilitySupport()) {
                    *internalFormat = GR_GL_RGB5;
                } else {
                    *internalFormat = GR_GL_RGB565;
                }
            } else {
                *internalFormat = GR_GL_RGB;
            }
            *externalType = GR_GL_UNSIGNED_SHORT_5_6_5;
            break;
        case kRGBA_4444_GrPixelConfig:
            *internalFormat = GR_GL_RGBA;
            *externalFormat = GR_GL_RGBA;
            if (getSizedInternalFormat) {
                *internalFormat = GR_GL_RGBA4;
            } else {
                *internalFormat = GR_GL_RGBA;
            }
            *externalType = GR_GL_UNSIGNED_SHORT_4_4_4_4;
            break;
        case kIndex_8_GrPixelConfig:
            // no sized/unsized internal format distinction here
            *internalFormat = GR_GL_PALETTE8_RGBA8;
            break;
        case kAlpha_8_GrPixelConfig:
            if (this->glCaps().textureRedSupport()) {
                *internalFormat = GR_GL_RED;
                *externalFormat = GR_GL_RED;
                if (getSizedInternalFormat) {
                    *internalFormat = GR_GL_R8;
                } else {
                    *internalFormat = GR_GL_RED;
                }
                *externalType = GR_GL_UNSIGNED_BYTE;
            } else {
                *internalFormat = GR_GL_ALPHA;
                *externalFormat = GR_GL_ALPHA;
                if (getSizedInternalFormat) {
                    *internalFormat = GR_GL_ALPHA8;
                } else {
                    *internalFormat = GR_GL_ALPHA;
                }
                *externalType = GR_GL_UNSIGNED_BYTE;
            }
            break;
        case kETC1_GrPixelConfig:
            *internalFormat = GR_GL_COMPRESSED_ETC1_RGB8;
            break;
        case kLATC_GrPixelConfig:
            switch(this->glCaps().latcAlias()) {
                case GrGLCaps::kLATC_LATCAlias:
                    *internalFormat = GR_GL_COMPRESSED_LUMINANCE_LATC1;
                    break;
                case GrGLCaps::kRGTC_LATCAlias:
                    *internalFormat = GR_GL_COMPRESSED_RED_RGTC1;
                    break;
                case GrGLCaps::k3DC_LATCAlias:
                    *internalFormat = GR_GL_COMPRESSED_3DC_X;
                    break;
            }
            break;
        case kR11_EAC_GrPixelConfig:
            *internalFormat = GR_GL_COMPRESSED_R11_EAC;
            break;

        case kASTC_12x12_GrPixelConfig:
            *internalFormat = GR_GL_COMPRESSED_RGBA_ASTC_12x12_KHR;
            break;

        case kRGBA_float_GrPixelConfig:
            *internalFormat = GR_GL_RGBA32F;
            *externalFormat = GR_GL_RGBA;
            *externalType = GR_GL_FLOAT;
            break;

        case kAlpha_half_GrPixelConfig:
            if (this->glCaps().textureRedSupport()) {
                if (getSizedInternalFormat) {
                    *internalFormat = GR_GL_R16F;
                } else {
                    *internalFormat = GR_GL_RED;
                }
                *externalFormat = GR_GL_RED;
            } else {
                if (getSizedInternalFormat) {
                    *internalFormat = GR_GL_ALPHA16F;
                } else {
                    *internalFormat = GR_GL_ALPHA;
                }
                *externalFormat = GR_GL_ALPHA;
            }
            if (kGL_GrGLStandard == this->glStandard() || this->glVersion() >= GR_GL_VER(3, 0)) {
                *externalType = GR_GL_HALF_FLOAT;
            } else {
                *externalType = GR_GL_HALF_FLOAT_OES;
            }
            break;
            
        case kRGBA_half_GrPixelConfig:
            *internalFormat = GR_GL_RGBA16F;
            *externalFormat = GR_GL_RGBA;
            if (kGL_GrGLStandard == this->glStandard() || this->glVersion() >= GR_GL_VER(3, 0)) {
                *externalType = GR_GL_HALF_FLOAT;
            } else {
                *externalType = GR_GL_HALF_FLOAT_OES;
            }
            break;

        default:
            return false;
    }
    return true;
}

void GrGLGpu::setTextureUnit(int unit) {
>>>>>>> miniblink49
    SkASSERT(unit >= 0 && unit < fHWBoundTextureUniqueIDs.count());
    if (unit != fHWActiveTextureUnitIdx) {
        GL_CALL(ActiveTexture(GR_GL_TEXTURE0 + unit));
        fHWActiveTextureUnitIdx = unit;
    }
}

<<<<<<< HEAD
void GrGLGpu::setScratchTextureUnit()
{
=======
void GrGLGpu::setScratchTextureUnit() {
>>>>>>> miniblink49
    // Bind the last texture unit since it is the least likely to be used by GrGLProgram.
    int lastUnitIdx = fHWBoundTextureUniqueIDs.count() - 1;
    if (lastUnitIdx != fHWActiveTextureUnitIdx) {
        GL_CALL(ActiveTexture(GR_GL_TEXTURE0 + lastUnitIdx));
        fHWActiveTextureUnitIdx = lastUnitIdx;
    }
    // clear out the this field so that if a program does use this unit it will rebind the correct
    // texture.
    fHWBoundTextureUniqueIDs[lastUnitIdx] = SK_InvalidUniqueID;
}

<<<<<<< HEAD
// Determines whether glBlitFramebuffer could be used between src and dst.
static inline bool can_blit_framebuffer(const GrSurface* dst,
    const GrSurface* src,
    const GrGLGpu* gpu)
{
    if (gpu->glCaps().isConfigRenderable(dst->config(), dst->desc().fSampleCnt > 0) && gpu->glCaps().isConfigRenderable(src->config(), src->desc().fSampleCnt > 0)) {
        switch (gpu->glCaps().blitFramebufferSupport()) {
        case GrGLCaps::kNone_BlitFramebufferSupport:
            return false;
        case GrGLCaps::kNoScalingNoMirroring_BlitFramebufferSupport:
            // Our copy surface doesn't support scaling so just check for mirroring.
            if (dst->origin() != src->origin()) {
                return false;
            }
            break;
        case GrGLCaps::kFull_BlitFramebufferSupport:
            break;
        }
        // ES3 doesn't allow framebuffer blits when the src has MSAA and the configs don't match
        // or the rects are not the same (not just the same size but have the same edges).
        if (GrGLCaps::kES_3_0_MSFBOType == gpu->glCaps().msFBOType() && (src->desc().fSampleCnt > 0 || src->config() != dst->config())) {
            return false;
        }
        const GrGLTexture* dstTex = static_cast<const GrGLTexture*>(dst->asTexture());
        if (dstTex && dstTex->target() != GR_GL_TEXTURE_2D) {
            return false;
        }
        const GrGLTexture* srcTex = static_cast<const GrGLTexture*>(dst->asTexture());
        if (srcTex && srcTex->target() != GR_GL_TEXTURE_2D) {
            return false;
=======
namespace {
// Determines whether glBlitFramebuffer could be used between src and dst.
inline bool can_blit_framebuffer(const GrSurface* dst,
                                 const GrSurface* src,
                                 const GrGLGpu* gpu) {
    if (gpu->glCaps().isConfigRenderable(dst->config(), dst->desc().fSampleCnt > 0) &&
        gpu->glCaps().isConfigRenderable(src->config(), src->desc().fSampleCnt > 0) &&
        gpu->glCaps().usesMSAARenderBuffers()) {
        // ES3 doesn't allow framebuffer blits when the src has MSAA and the configs don't match
        // or the rects are not the same (not just the same size but have the same edges).
        if (GrGLCaps::kES_3_0_MSFBOType == gpu->glCaps().msFBOType() &&
            (src->desc().fSampleCnt > 0 || src->config() != dst->config())) {
           return false;
>>>>>>> miniblink49
        }
        return true;
    } else {
        return false;
    }
}

<<<<<<< HEAD
static inline bool can_copy_texsubimage(const GrSurface* dst,
    const GrSurface* src,
    const GrGLGpu* gpu)
{
    // Table 3.9 of the ES2 spec indicates the supported formats with CopyTexSubImage
    // and BGRA isn't in the spec. There doesn't appear to be any extension that adds it. Perhaps
    // many drivers would allow it to work, but ANGLE does not.
    if (kGLES_GrGLStandard == gpu->glStandard() && gpu->glCaps().bgraIsInternalFormat() && (kBGRA_8888_GrPixelConfig == dst->config() || kBGRA_8888_GrPixelConfig == src->config())) {
=======
inline bool can_copy_texsubimage(const GrSurface* dst,
                                 const GrSurface* src,
                                 const GrGLGpu* gpu) {
    // Table 3.9 of the ES2 spec indicates the supported formats with CopyTexSubImage
    // and BGRA isn't in the spec. There doesn't appear to be any extension that adds it. Perhaps
    // many drivers would allow it to work, but ANGLE does not.
    if (kGLES_GrGLStandard == gpu->glStandard() && gpu->glCaps().bgraIsInternalFormat() &&
        (kBGRA_8888_GrPixelConfig == dst->config() || kBGRA_8888_GrPixelConfig == src->config())) {
>>>>>>> miniblink49
        return false;
    }
    const GrGLRenderTarget* dstRT = static_cast<const GrGLRenderTarget*>(dst->asRenderTarget());
    // If dst is multisampled (and uses an extension where there is a separate MSAA renderbuffer)
    // then we don't want to copy to the texture but to the MSAA buffer.
    if (dstRT && dstRT->renderFBOID() != dstRT->textureFBOID()) {
        return false;
    }
    const GrGLRenderTarget* srcRT = static_cast<const GrGLRenderTarget*>(src->asRenderTarget());
    // If the src is multisampled (and uses an extension where there is a separate MSAA
    // renderbuffer) then it is an invalid operation to call CopyTexSubImage
    if (srcRT && srcRT->renderFBOID() != srcRT->textureFBOID()) {
        return false;
    }
<<<<<<< HEAD

    const GrGLTexture* dstTex = static_cast<const GrGLTexture*>(dst->asTexture());
    // CopyTex(Sub)Image writes to a texture and we have no way of dynamically wrapping a RT in a
    // texture.
    if (!dstTex) {
        return false;
    }

    const GrGLTexture* srcTex = static_cast<const GrGLTexture*>(src->asTexture());

    // Check that we could wrap the source in an FBO, that the dst is TEXTURE_2D, that no mirroring
    // is required.
    if (gpu->glCaps().isConfigRenderable(src->config(), src->desc().fSampleCnt > 0) && !GrPixelConfigIsCompressed(src->config()) && (!srcTex || srcTex->target() == GR_GL_TEXTURE_2D) && dstTex->target() == GR_GL_TEXTURE_2D && dst->origin() == src->origin()) {
=======
    if (gpu->glCaps().isConfigRenderable(src->config(), src->desc().fSampleCnt > 0) &&
        dst->asTexture() &&
        dst->origin() == src->origin() &&
        !GrPixelConfigIsCompressed(src->config())) {
>>>>>>> miniblink49
        return true;
    } else {
        return false;
    }
}

<<<<<<< HEAD
// If a temporary FBO was created, its non-zero ID is returned. The viewport that the copy rect is
// relative to is output.
void GrGLGpu::bindSurfaceFBOForCopy(GrSurface* surface, GrGLenum fboTarget, GrGLIRect* viewport,
    TempFBOTarget tempFBOTarget)
{
    GrGLRenderTarget* rt = static_cast<GrGLRenderTarget*>(surface->asRenderTarget());
    if (!rt) {
        SkASSERT(surface->asTexture());
        GrGLuint texID = static_cast<GrGLTexture*>(surface->asTexture())->textureID();
        GrGLenum target = static_cast<GrGLTexture*>(surface->asTexture())->target();
=======
}

// If a temporary FBO was created, its non-zero ID is returned. The viewport that the copy rect is
// relative to is output.
GrGLuint GrGLGpu::bindSurfaceAsFBO(GrSurface* surface, GrGLenum fboTarget, GrGLIRect* viewport,
                                   TempFBOTarget tempFBOTarget) {
    GrGLRenderTarget* rt = static_cast<GrGLRenderTarget*>(surface->asRenderTarget());
    if (NULL == rt) {
        SkASSERT(surface->asTexture());
        GrGLuint texID = static_cast<GrGLTexture*>(surface->asTexture())->textureID();
>>>>>>> miniblink49
        GrGLuint* tempFBOID;
        tempFBOID = kSrc_TempFBOTarget == tempFBOTarget ? &fTempSrcFBOID : &fTempDstFBOID;

        if (0 == *tempFBOID) {
            GR_GL_CALL(this->glInterface(), GenFramebuffers(1, tempFBOID));
        }

        fStats.incRenderTargetBinds();
        GR_GL_CALL(this->glInterface(), BindFramebuffer(fboTarget, *tempFBOID));
<<<<<<< HEAD
        GR_GL_CALL(this->glInterface(), FramebufferTexture2D(fboTarget, GR_GL_COLOR_ATTACHMENT0, target, texID, 0));
=======
        GR_GL_CALL(this->glInterface(), FramebufferTexture2D(fboTarget,
                                                             GR_GL_COLOR_ATTACHMENT0,
                                                             GR_GL_TEXTURE_2D,
                                                             texID,
                                                             0));
>>>>>>> miniblink49
        viewport->fLeft = 0;
        viewport->fBottom = 0;
        viewport->fWidth = surface->width();
        viewport->fHeight = surface->height();
<<<<<<< HEAD
    } else {
        fStats.incRenderTargetBinds();
        GR_GL_CALL(this->glInterface(), BindFramebuffer(fboTarget, rt->renderFBOID()));
        *viewport = rt->getViewport();
    }
}

void GrGLGpu::unbindTextureFBOForCopy(GrGLenum fboTarget, GrSurface* surface)
{
    // bindSurfaceFBOForCopy temporarily binds textures that are not render targets to
    if (!surface->asRenderTarget()) {
        SkASSERT(surface->asTexture());
        GrGLenum textureTarget = static_cast<GrGLTexture*>(surface->asTexture())->target();
        GR_GL_CALL(this->glInterface(), FramebufferTexture2D(fboTarget, GR_GL_COLOR_ATTACHMENT0, textureTarget, 0, 0));
    }
}

bool GrGLGpu::initCopySurfaceDstDesc(const GrSurface* src, GrSurfaceDesc* desc) const
{
=======
        return *tempFBOID;
    } else {
        GrGLuint tempFBOID = 0;
        fStats.incRenderTargetBinds();
        GR_GL_CALL(this->glInterface(), BindFramebuffer(fboTarget, rt->renderFBOID()));
        *viewport = rt->getViewport();
        return tempFBOID;
    }
}

void GrGLGpu::unbindTextureFromFBO(GrGLenum fboTarget) {
    GR_GL_CALL(this->glInterface(), FramebufferTexture2D(fboTarget,
                                                         GR_GL_COLOR_ATTACHMENT0,
                                                         GR_GL_TEXTURE_2D,
                                                         0,
                                                         0));
}

bool GrGLGpu::initCopySurfaceDstDesc(const GrSurface* src, GrSurfaceDesc* desc) {
>>>>>>> miniblink49
    // If the src is a texture, we can implement the blit as a draw assuming the config is
    // renderable.
    if (src->asTexture() && this->caps()->isConfigRenderable(src->config(), false)) {
        desc->fOrigin = kDefault_GrSurfaceOrigin;
        desc->fFlags = kRenderTarget_GrSurfaceFlag;
        desc->fConfig = src->config();
        return true;
    }

<<<<<<< HEAD
    const GrGLTexture* srcTexture = static_cast<const GrGLTexture*>(src->asTexture());
    if (srcTexture && srcTexture->target() != GR_GL_TEXTURE_2D) {
        // Not supported for FBO blit or CopyTexSubImage
        return false;
    }

=======
>>>>>>> miniblink49
    // We look for opportunities to use CopyTexSubImage, or fbo blit. If neither are
    // possible and we return false to fallback to creating a render target dst for render-to-
    // texture. This code prefers CopyTexSubImage to fbo blit and avoids triggering temporary fbo
    // creation. It isn't clear that avoiding temporary fbo creation is actually optimal.

<<<<<<< HEAD
    GrSurfaceOrigin originForBlitFramebuffer = kDefault_GrSurfaceOrigin;
    if (this->glCaps().blitFramebufferSupport() == GrGLCaps::kNoScalingNoMirroring_BlitFramebufferSupport) {
        originForBlitFramebuffer = src->origin();
    }

    // Check for format issues with glCopyTexSubImage2D
    if (kGLES_GrGLStandard == this->glStandard() && this->glCaps().bgraIsInternalFormat() && kBGRA_8888_GrPixelConfig == src->config()) {
        // glCopyTexSubImage2D doesn't work with this config. If the bgra can be used with fbo blit
        // then we set up for that, otherwise fail.
        if (this->caps()->isConfigRenderable(kBGRA_8888_GrPixelConfig, false)) {
            desc->fOrigin = originForBlitFramebuffer;
=======
    // Check for format issues with glCopyTexSubImage2D
    if (kGLES_GrGLStandard == this->glStandard() && this->glCaps().bgraIsInternalFormat() &&
        kBGRA_8888_GrPixelConfig == src->config()) {
        // glCopyTexSubImage2D doesn't work with this config. If the bgra can be used with fbo blit
        // then we set up for that, otherwise fail.
        if (this->caps()->isConfigRenderable(kBGRA_8888_GrPixelConfig, false)) {
            desc->fOrigin = kDefault_GrSurfaceOrigin;
>>>>>>> miniblink49
            desc->fFlags = kRenderTarget_GrSurfaceFlag;
            desc->fConfig = kBGRA_8888_GrPixelConfig;
            return true;
        }
        return false;
<<<<<<< HEAD
    } else if (nullptr == src->asRenderTarget()) {
=======
    } else if (NULL == src->asRenderTarget()) {
>>>>>>> miniblink49
        // CopyTexSubImage2D or fbo blit would require creating a temp fbo for the src.
        return false;
    }

    const GrGLRenderTarget* srcRT = static_cast<const GrGLRenderTarget*>(src->asRenderTarget());
    if (srcRT && srcRT->renderFBOID() != srcRT->textureFBOID()) {
        // It's illegal to call CopyTexSubImage2D on a MSAA renderbuffer. Set up for FBO blit or
        // fail.
        if (this->caps()->isConfigRenderable(src->config(), false)) {
<<<<<<< HEAD
            desc->fOrigin = originForBlitFramebuffer;
=======
            desc->fOrigin = kDefault_GrSurfaceOrigin;
>>>>>>> miniblink49
            desc->fFlags = kRenderTarget_GrSurfaceFlag;
            desc->fConfig = src->config();
            return true;
        }
        return false;
    }

    // We'll do a CopyTexSubImage. Make the dst a plain old texture.
    desc->fConfig = src->config();
    desc->fOrigin = src->origin();
    desc->fFlags = kNone_GrSurfaceFlags;
    return true;
}

bool GrGLGpu::onCopySurface(GrSurface* dst,
<<<<<<< HEAD
    GrSurface* src,
    const SkIRect& srcRect,
    const SkIPoint& dstPoint)
{
    // None of our copy methods can handle a swizzle. TODO: Make copySurfaceAsDraw handle the
    // swizzle.
    if (this->glCaps().glslCaps()->configOutputSwizzle(src->config()) != this->glCaps().glslCaps()->configOutputSwizzle(dst->config())) {
        return false;
    }
    // Don't prefer copying as a draw if the dst doesn't already have a FBO object.
    bool preferCopy = SkToBool(dst->asRenderTarget());
    if (preferCopy && src->asTexture()) {
        if (this->copySurfaceAsDraw(dst, src, srcRect, dstPoint)) {
            return true;
        }
    }

=======
                            GrSurface* src,
                            const SkIRect& srcRect,
                            const SkIPoint& dstPoint) {
    if (src->asTexture() && dst->asRenderTarget()) {
        this->copySurfaceAsDraw(dst, src, srcRect, dstPoint);
        return true;
    }
    
>>>>>>> miniblink49
    if (can_copy_texsubimage(dst, src, this)) {
        this->copySurfaceAsCopyTexSubImage(dst, src, srcRect, dstPoint);
        return true;
    }

    if (can_blit_framebuffer(dst, src, this)) {
        return this->copySurfaceAsBlitFramebuffer(dst, src, srcRect, dstPoint);
    }

<<<<<<< HEAD
    if (!preferCopy && src->asTexture()) {
        if (this->copySurfaceAsDraw(dst, src, srcRect, dstPoint)) {
            return true;
        }
    }

    return false;
}

bool GrGLGpu::createCopyProgram(int progIdx)
{
    const GrGLSLCaps* glslCaps = this->glCaps().glslCaps();
    static const GrSLType kSamplerTypes[3] = { kSampler2D_GrSLType, kSamplerExternal_GrSLType,
        kSampler2DRect_GrSLType };
    if (kSamplerExternal_GrSLType == kSamplerTypes[progIdx] && !this->glCaps().glslCaps()->externalTextureSupport()) {
        return false;
    }
    if (kSampler2DRect_GrSLType == kSamplerTypes[progIdx] && !this->glCaps().rectangleTextureSupport()) {
        return false;
    }

    if (!fCopyProgramArrayBuffer) {
        static const GrGLfloat vdata[] = {
            0, 0,
            0, 1,
            1, 0,
            1, 1
        };
        fCopyProgramArrayBuffer.reset(GrGLBuffer::Create(this, sizeof(vdata), kVertex_GrBufferType,
            kStatic_GrAccessPattern, vdata));
    }
    if (!fCopyProgramArrayBuffer) {
        return false;
    }

    SkASSERT(!fCopyPrograms[progIdx].fProgram);
    GL_CALL_RET(fCopyPrograms[progIdx].fProgram, CreateProgram());
    if (!fCopyPrograms[progIdx].fProgram) {
        return false;
    }

    const char* version = glslCaps->versionDeclString();
    GrGLSLShaderVar aVertex("a_vertex", kVec2f_GrSLType, GrShaderVar::kAttribute_TypeModifier);
    GrGLSLShaderVar uTexCoordXform("u_texCoordXform", kVec4f_GrSLType,
        GrShaderVar::kUniform_TypeModifier);
    GrGLSLShaderVar uPosXform("u_posXform", kVec4f_GrSLType,
        GrShaderVar::kUniform_TypeModifier);
    GrGLSLShaderVar uTexture("u_texture", kSamplerTypes[progIdx],
        GrShaderVar::kUniform_TypeModifier);
    GrGLSLShaderVar vTexCoord("v_texCoord", kVec2f_GrSLType,
        GrShaderVar::kVaryingOut_TypeModifier);
    GrGLSLShaderVar oFragColor("o_FragColor", kVec4f_GrSLType,
        GrShaderVar::kOut_TypeModifier);

    SkString vshaderTxt(version);
    if (glslCaps->noperspectiveInterpolationSupport()) {
        if (const char* extension = glslCaps->noperspectiveInterpolationExtensionString()) {
            vshaderTxt.appendf("#extension %s : require\n", extension);
        }
        vTexCoord.addModifier("noperspective");
    }

    aVertex.appendDecl(glslCaps, &vshaderTxt);
    vshaderTxt.append(";");
    uTexCoordXform.appendDecl(glslCaps, &vshaderTxt);
    vshaderTxt.append(";");
    uPosXform.appendDecl(glslCaps, &vshaderTxt);
    vshaderTxt.append(";");
    vTexCoord.appendDecl(glslCaps, &vshaderTxt);
    vshaderTxt.append(";");

=======
    return false;
}


void GrGLGpu::createCopyProgram() {
    const char* version = GrGLGetGLSLVersionDecl(this->ctxInfo());

    GrGLShaderVar aVertex("a_vertex", kVec2f_GrSLType, GrShaderVar::kAttribute_TypeModifier);
    GrGLShaderVar uTexCoordXform("u_texCoordXform", kVec4f_GrSLType,
                                 GrShaderVar::kUniform_TypeModifier);
    GrGLShaderVar uPosXform("u_posXform", kVec4f_GrSLType, GrShaderVar::kUniform_TypeModifier);
    GrGLShaderVar uTexture("u_texture", kSampler2D_GrSLType, GrShaderVar::kUniform_TypeModifier);
    GrGLShaderVar vTexCoord("v_texCoord", kVec2f_GrSLType, GrShaderVar::kVaryingOut_TypeModifier);
    GrGLShaderVar oFragColor("o_FragColor", kVec4f_GrSLType, GrShaderVar::kOut_TypeModifier);
    
    SkString vshaderTxt(version);
    aVertex.appendDecl(this->ctxInfo(), &vshaderTxt);
    vshaderTxt.append(";");
    uTexCoordXform.appendDecl(this->ctxInfo(), &vshaderTxt);
    vshaderTxt.append(";");
    uPosXform.appendDecl(this->ctxInfo(), &vshaderTxt);
    vshaderTxt.append(";");
    vTexCoord.appendDecl(this->ctxInfo(), &vshaderTxt);
    vshaderTxt.append(";");
    
>>>>>>> miniblink49
    vshaderTxt.append(
        "// Copy Program VS\n"
        "void main() {"
        "  v_texCoord = a_vertex.xy * u_texCoordXform.xy + u_texCoordXform.zw;"
        "  gl_Position.xy = a_vertex * u_posXform.xy + u_posXform.zw;"
        "  gl_Position.zw = vec2(0, 1);"
<<<<<<< HEAD
        "}");

    SkString fshaderTxt(version);
    if (glslCaps->noperspectiveInterpolationSupport()) {
        if (const char* extension = glslCaps->noperspectiveInterpolationExtensionString()) {
            fshaderTxt.appendf("#extension %s : require\n", extension);
        }
    }
    if (kSamplerTypes[progIdx] == kSamplerExternal_GrSLType) {
        fshaderTxt.appendf("#extension %s : require\n",
            glslCaps->externalTextureExtensionString());
    }
    GrGLSLAppendDefaultFloatPrecisionDeclaration(kDefault_GrSLPrecision, *glslCaps,
        &fshaderTxt);
    vTexCoord.setTypeModifier(GrShaderVar::kVaryingIn_TypeModifier);
    vTexCoord.appendDecl(glslCaps, &fshaderTxt);
    fshaderTxt.append(";");
    uTexture.appendDecl(glslCaps, &fshaderTxt);
    fshaderTxt.append(";");
    const char* fsOutName;
    if (glslCaps->mustDeclareFragmentShaderOutput()) {
        oFragColor.appendDecl(glslCaps, &fshaderTxt);
=======
        "}"
    );

    SkString fshaderTxt(version);
    GrGLAppendGLSLDefaultFloatPrecisionDeclaration(kDefault_GrSLPrecision, this->glStandard(),
                                                   &fshaderTxt);
    vTexCoord.setTypeModifier(GrShaderVar::kVaryingIn_TypeModifier);
    vTexCoord.appendDecl(this->ctxInfo(), &fshaderTxt);
    fshaderTxt.append(";");
    uTexture.appendDecl(this->ctxInfo(), &fshaderTxt);
    fshaderTxt.append(";");
    const char* fsOutName;
    if (this->glCaps().glslCaps()->mustDeclareFragmentShaderOutput()) {
        oFragColor.appendDecl(this->ctxInfo(), &fshaderTxt);
>>>>>>> miniblink49
        fshaderTxt.append(";");
        fsOutName = oFragColor.c_str();
    } else {
        fsOutName = "gl_FragColor";
    }
    fshaderTxt.appendf(
        "// Copy Program FS\n"
        "void main() {"
        "  %s = %s(u_texture, v_texCoord);"
        "}",
        fsOutName,
<<<<<<< HEAD
        GrGLSLTexture2DFunctionName(kVec2f_GrSLType, kSamplerTypes[progIdx], this->glslGeneration()));

=======
        GrGLSLTexture2DFunctionName(kVec2f_GrSLType, this->glslGeneration())
    );
    
    GL_CALL_RET(fCopyProgram.fProgram, CreateProgram());
>>>>>>> miniblink49
    const char* str;
    GrGLint length;

    str = vshaderTxt.c_str();
    length = SkToInt(vshaderTxt.size());
<<<<<<< HEAD
    GrGLuint vshader = GrGLCompileAndAttachShader(*fGLContext, fCopyPrograms[progIdx].fProgram,
        GR_GL_VERTEX_SHADER, &str, &length, 1,
        &fStats);

    str = fshaderTxt.c_str();
    length = SkToInt(fshaderTxt.size());
    GrGLuint fshader = GrGLCompileAndAttachShader(*fGLContext, fCopyPrograms[progIdx].fProgram,
        GR_GL_FRAGMENT_SHADER, &str, &length, 1,
        &fStats);

    GL_CALL(LinkProgram(fCopyPrograms[progIdx].fProgram));

    GL_CALL_RET(fCopyPrograms[progIdx].fTextureUniform,
        GetUniformLocation(fCopyPrograms[progIdx].fProgram, "u_texture"));
    GL_CALL_RET(fCopyPrograms[progIdx].fPosXformUniform,
        GetUniformLocation(fCopyPrograms[progIdx].fProgram, "u_posXform"));
    GL_CALL_RET(fCopyPrograms[progIdx].fTexCoordXformUniform,
        GetUniformLocation(fCopyPrograms[progIdx].fProgram, "u_texCoordXform"));

    GL_CALL(BindAttribLocation(fCopyPrograms[progIdx].fProgram, 0, "a_vertex"));
=======
    GrGLuint vshader = GrGLCompileAndAttachShader(*fGLContext, fCopyProgram.fProgram,
                                                  GR_GL_VERTEX_SHADER, &str, &length, 1, &fStats);

    str = fshaderTxt.c_str();
    length = SkToInt(fshaderTxt.size());
    GrGLuint fshader = GrGLCompileAndAttachShader(*fGLContext, fCopyProgram.fProgram,
                                                  GR_GL_FRAGMENT_SHADER, &str, &length, 1, &fStats);

    GL_CALL(LinkProgram(fCopyProgram.fProgram));

    GL_CALL_RET(fCopyProgram.fTextureUniform, GetUniformLocation(fCopyProgram.fProgram,
                                                                 "u_texture"));
    GL_CALL_RET(fCopyProgram.fPosXformUniform, GetUniformLocation(fCopyProgram.fProgram,
                                                                  "u_posXform"));
    GL_CALL_RET(fCopyProgram.fTexCoordXformUniform, GetUniformLocation(fCopyProgram.fProgram,
                                                                       "u_texCoordXform"));

    GL_CALL(BindAttribLocation(fCopyProgram.fProgram, 0, "a_vertex"));
>>>>>>> miniblink49

    GL_CALL(DeleteShader(vshader));
    GL_CALL(DeleteShader(fshader));

<<<<<<< HEAD
    return true;
}

bool GrGLGpu::createMipmapProgram(int progIdx)
{
    const bool oddWidth = SkToBool(progIdx & 0x2);
    const bool oddHeight = SkToBool(progIdx & 0x1);
    const int numTaps = (oddWidth ? 2 : 1) * (oddHeight ? 2 : 1);

    const GrGLSLCaps* glslCaps = this->glCaps().glslCaps();

    SkASSERT(!fMipmapPrograms[progIdx].fProgram);
    GL_CALL_RET(fMipmapPrograms[progIdx].fProgram, CreateProgram());
    if (!fMipmapPrograms[progIdx].fProgram) {
        return false;
    }

    const char* version = glslCaps->versionDeclString();
    GrGLSLShaderVar aVertex("a_vertex", kVec2f_GrSLType, GrShaderVar::kAttribute_TypeModifier);
    GrGLSLShaderVar uTexCoordXform("u_texCoordXform", kVec4f_GrSLType,
        GrShaderVar::kUniform_TypeModifier);
    GrGLSLShaderVar uTexture("u_texture", kSampler2D_GrSLType, GrShaderVar::kUniform_TypeModifier);
    // We need 1, 2, or 4 texture coordinates (depending on parity of each dimension):
    GrGLSLShaderVar vTexCoords[] = {
        GrGLSLShaderVar("v_texCoord0", kVec2f_GrSLType, GrShaderVar::kVaryingOut_TypeModifier),
        GrGLSLShaderVar("v_texCoord1", kVec2f_GrSLType, GrShaderVar::kVaryingOut_TypeModifier),
        GrGLSLShaderVar("v_texCoord2", kVec2f_GrSLType, GrShaderVar::kVaryingOut_TypeModifier),
        GrGLSLShaderVar("v_texCoord3", kVec2f_GrSLType, GrShaderVar::kVaryingOut_TypeModifier),
    };
    GrGLSLShaderVar oFragColor("o_FragColor", kVec4f_GrSLType,
        GrShaderVar::kOut_TypeModifier);

    SkString vshaderTxt(version);
    if (glslCaps->noperspectiveInterpolationSupport()) {
        if (const char* extension = glslCaps->noperspectiveInterpolationExtensionString()) {
            vshaderTxt.appendf("#extension %s : require\n", extension);
        }
        vTexCoords[0].addModifier("noperspective");
        vTexCoords[1].addModifier("noperspective");
        vTexCoords[2].addModifier("noperspective");
        vTexCoords[3].addModifier("noperspective");
    }

    aVertex.appendDecl(glslCaps, &vshaderTxt);
    vshaderTxt.append(";");
    uTexCoordXform.appendDecl(glslCaps, &vshaderTxt);
    vshaderTxt.append(";");
    for (int i = 0; i < numTaps; ++i) {
        vTexCoords[i].appendDecl(glslCaps, &vshaderTxt);
        vshaderTxt.append(";");
    }

    vshaderTxt.append(
        "// Mipmap Program VS\n"
        "void main() {"
        "  gl_Position.xy = a_vertex * vec2(2, 2) - vec2(1, 1);"
        "  gl_Position.zw = vec2(0, 1);");

    // Insert texture coordinate computation:
    if (oddWidth && oddHeight) {
        vshaderTxt.append(
            "  v_texCoord0 = a_vertex.xy * u_texCoordXform.yw;"
            "  v_texCoord1 = a_vertex.xy * u_texCoordXform.yw + vec2(u_texCoordXform.x, 0);"
            "  v_texCoord2 = a_vertex.xy * u_texCoordXform.yw + vec2(0, u_texCoordXform.z);"
            "  v_texCoord3 = a_vertex.xy * u_texCoordXform.yw + u_texCoordXform.xz;");
    } else if (oddWidth) {
        vshaderTxt.append(
            "  v_texCoord0 = a_vertex.xy * vec2(u_texCoordXform.y, 1);"
            "  v_texCoord1 = a_vertex.xy * vec2(u_texCoordXform.y, 1) + vec2(u_texCoordXform.x, 0);");
    } else if (oddHeight) {
        vshaderTxt.append(
            "  v_texCoord0 = a_vertex.xy * vec2(1, u_texCoordXform.w);"
            "  v_texCoord1 = a_vertex.xy * vec2(1, u_texCoordXform.w) + vec2(0, u_texCoordXform.z);");
    } else {
        vshaderTxt.append(
            "  v_texCoord0 = a_vertex.xy;");
    }

    vshaderTxt.append("}");

    SkString fshaderTxt(version);
    if (glslCaps->noperspectiveInterpolationSupport()) {
        if (const char* extension = glslCaps->noperspectiveInterpolationExtensionString()) {
            fshaderTxt.appendf("#extension %s : require\n", extension);
        }
    }
    GrGLSLAppendDefaultFloatPrecisionDeclaration(kDefault_GrSLPrecision, *glslCaps,
        &fshaderTxt);
    for (int i = 0; i < numTaps; ++i) {
        vTexCoords[i].setTypeModifier(GrShaderVar::kVaryingIn_TypeModifier);
        vTexCoords[i].appendDecl(glslCaps, &fshaderTxt);
        fshaderTxt.append(";");
    }
    uTexture.appendDecl(glslCaps, &fshaderTxt);
    fshaderTxt.append(";");
    const char* fsOutName;
    if (glslCaps->mustDeclareFragmentShaderOutput()) {
        oFragColor.appendDecl(glslCaps, &fshaderTxt);
        fshaderTxt.append(";");
        fsOutName = oFragColor.c_str();
    } else {
        fsOutName = "gl_FragColor";
    }
    const char* sampleFunction = GrGLSLTexture2DFunctionName(kVec2f_GrSLType, kSampler2D_GrSLType,
        this->glslGeneration());
    fshaderTxt.append(
        "// Mipmap Program FS\n"
        "void main() {");

    if (oddWidth && oddHeight) {
        fshaderTxt.appendf(
            "  %s = (%s(u_texture, v_texCoord0) + %s(u_texture, v_texCoord1) + "
            "        %s(u_texture, v_texCoord2) + %s(u_texture, v_texCoord3)) * 0.25;",
            fsOutName, sampleFunction, sampleFunction, sampleFunction, sampleFunction);
    } else if (oddWidth || oddHeight) {
        fshaderTxt.appendf(
            "  %s = (%s(u_texture, v_texCoord0) + %s(u_texture, v_texCoord1)) * 0.5;",
            fsOutName, sampleFunction, sampleFunction);
    } else {
        fshaderTxt.appendf(
            "  %s = %s(u_texture, v_texCoord0);",
            fsOutName, sampleFunction);
    }

    fshaderTxt.append("}");

    const char* str;
    GrGLint length;

    str = vshaderTxt.c_str();
    length = SkToInt(vshaderTxt.size());
    GrGLuint vshader = GrGLCompileAndAttachShader(*fGLContext, fMipmapPrograms[progIdx].fProgram,
        GR_GL_VERTEX_SHADER, &str, &length, 1,
        &fStats);

    str = fshaderTxt.c_str();
    length = SkToInt(fshaderTxt.size());
    GrGLuint fshader = GrGLCompileAndAttachShader(*fGLContext, fMipmapPrograms[progIdx].fProgram,
        GR_GL_FRAGMENT_SHADER, &str, &length, 1,
        &fStats);

    GL_CALL(LinkProgram(fMipmapPrograms[progIdx].fProgram));

    GL_CALL_RET(fMipmapPrograms[progIdx].fTextureUniform,
        GetUniformLocation(fMipmapPrograms[progIdx].fProgram, "u_texture"));
    GL_CALL_RET(fMipmapPrograms[progIdx].fTexCoordXformUniform,
        GetUniformLocation(fMipmapPrograms[progIdx].fProgram, "u_texCoordXform"));

    GL_CALL(BindAttribLocation(fMipmapPrograms[progIdx].fProgram, 0, "a_vertex"));

    GL_CALL(DeleteShader(vshader));
    GL_CALL(DeleteShader(fshader));

    return true;
}

bool GrGLGpu::createWireRectProgram()
{
    if (!fWireRectArrayBuffer) {
        static const GrGLfloat vdata[] = {
            0, 0,
            0, 1,
            1, 1,
            1, 0
        };
        fWireRectArrayBuffer.reset(GrGLBuffer::Create(this, sizeof(vdata), kVertex_GrBufferType,
            kStatic_GrAccessPattern, vdata));
        if (!fWireRectArrayBuffer) {
            return false;
        }
    }

    SkASSERT(!fWireRectProgram.fProgram);
    GL_CALL_RET(fWireRectProgram.fProgram, CreateProgram());
    if (!fWireRectProgram.fProgram) {
        return false;
    }

    GrGLSLShaderVar uColor("u_color", kVec4f_GrSLType, GrShaderVar::kUniform_TypeModifier);
    GrGLSLShaderVar uRect("u_rect", kVec4f_GrSLType, GrShaderVar::kUniform_TypeModifier);
    GrGLSLShaderVar aVertex("a_vertex", kVec2f_GrSLType, GrShaderVar::kAttribute_TypeModifier);
    const char* version = this->glCaps().glslCaps()->versionDeclString();

    // The rect uniform specifies the rectangle in NDC space as a vec4 (left,top,right,bottom). The
    // program is used with a vbo containing the unit square. Vertices are computed from the rect
    // uniform using the 4 vbo vertices.
    SkString vshaderTxt(version);
    aVertex.appendDecl(this->glCaps().glslCaps(), &vshaderTxt);
    vshaderTxt.append(";");
    uRect.appendDecl(this->glCaps().glslCaps(), &vshaderTxt);
    vshaderTxt.append(";");
    vshaderTxt.append(
        "// Wire Rect Program VS\n"
        "void main() {"
        "  gl_Position.x = u_rect.x + a_vertex.x * (u_rect.z - u_rect.x);"
        "  gl_Position.y = u_rect.y + a_vertex.y * (u_rect.w - u_rect.y);"
        "  gl_Position.zw = vec2(0, 1);"
        "}");

    GrGLSLShaderVar oFragColor("o_FragColor", kVec4f_GrSLType, GrShaderVar::kOut_TypeModifier);

    SkString fshaderTxt(version);
    GrGLSLAppendDefaultFloatPrecisionDeclaration(kDefault_GrSLPrecision,
        *this->glCaps().glslCaps(),
        &fshaderTxt);
    uColor.appendDecl(this->glCaps().glslCaps(), &fshaderTxt);
    fshaderTxt.append(";");
    const char* fsOutName;
    if (this->glCaps().glslCaps()->mustDeclareFragmentShaderOutput()) {
        oFragColor.appendDecl(this->glCaps().glslCaps(), &fshaderTxt);
        fshaderTxt.append(";");
        fsOutName = oFragColor.c_str();
    } else {
        fsOutName = "gl_FragColor";
    }
    fshaderTxt.appendf(
        "// Write Rect Program FS\n"
        "void main() {"
        "  %s = %s;"
        "}",
        fsOutName,
        uColor.c_str());

    const char* str;
    GrGLint length;

    str = vshaderTxt.c_str();
    length = SkToInt(vshaderTxt.size());
    GrGLuint vshader = GrGLCompileAndAttachShader(*fGLContext, fWireRectProgram.fProgram,
        GR_GL_VERTEX_SHADER, &str, &length, 1,
        &fStats);

    str = fshaderTxt.c_str();
    length = SkToInt(fshaderTxt.size());
    GrGLuint fshader = GrGLCompileAndAttachShader(*fGLContext, fWireRectProgram.fProgram,
        GR_GL_FRAGMENT_SHADER, &str, &length, 1,
        &fStats);

    GL_CALL(LinkProgram(fWireRectProgram.fProgram));

    GL_CALL_RET(fWireRectProgram.fColorUniform,
        GetUniformLocation(fWireRectProgram.fProgram, "u_color"));
    GL_CALL_RET(fWireRectProgram.fRectUniform,
        GetUniformLocation(fWireRectProgram.fProgram, "u_rect"));
    GL_CALL(BindAttribLocation(fWireRectProgram.fProgram, 0, "a_vertex"));

    GL_CALL(DeleteShader(vshader));
    GL_CALL(DeleteShader(fshader));

    return true;
}

void GrGLGpu::drawDebugWireRect(GrRenderTarget* rt, const SkIRect& rect, GrColor color)
{
    // TODO: This should swizzle the output to match dst's config, though it is a debugging
    // visualization.

    this->handleDirtyContext();
    if (!fWireRectProgram.fProgram) {
        if (!this->createWireRectProgram()) {
            SkDebugf("Failed to create wire rect program.\n");
            return;
        }
    }

    int w = rt->width();
    int h = rt->height();

    // Compute the edges of the rectangle (top,left,right,bottom) in NDC space. Must consider
    // whether the render target is flipped or not.
    GrGLfloat edges[4];
    edges[0] = SkIntToScalar(rect.fLeft) + 0.5f;
    edges[2] = SkIntToScalar(rect.fRight) - 0.5f;
    if (kBottomLeft_GrSurfaceOrigin == rt->origin()) {
        edges[1] = h - (SkIntToScalar(rect.fTop) + 0.5f);
        edges[3] = h - (SkIntToScalar(rect.fBottom) - 0.5f);
    } else {
        edges[1] = SkIntToScalar(rect.fTop) + 0.5f;
        edges[3] = SkIntToScalar(rect.fBottom) - 0.5f;
    }
    edges[0] = 2 * edges[0] / w - 1.0f;
    edges[1] = 2 * edges[1] / h - 1.0f;
    edges[2] = 2 * edges[2] / w - 1.0f;
    edges[3] = 2 * edges[3] / h - 1.0f;

    GrGLfloat channels[4];
    static const GrGLfloat scale255 = 1.f / 255.f;
    channels[0] = GrColorUnpackR(color) * scale255;
    channels[1] = GrColorUnpackG(color) * scale255;
    channels[2] = GrColorUnpackB(color) * scale255;
    channels[3] = GrColorUnpackA(color) * scale255;

    GrGLRenderTarget* glRT = static_cast<GrGLRenderTarget*>(rt->asRenderTarget());
    this->flushRenderTarget(glRT, &rect);

    GL_CALL(UseProgram(fWireRectProgram.fProgram));
    fHWProgramID = fWireRectProgram.fProgram;

    fHWVertexArrayState.setVertexArrayID(this, 0);

    GrGLAttribArrayState* attribs = fHWVertexArrayState.bindInternalVertexArray(this);
    attribs->set(this, 0, fWireRectArrayBuffer, kVec2f_GrVertexAttribType, 2 * sizeof(GrGLfloat),
        0);
    attribs->disableUnusedArrays(this, 0x1);

    GL_CALL(Uniform4fv(fWireRectProgram.fRectUniform, 1, edges));
    GL_CALL(Uniform4fv(fWireRectProgram.fColorUniform, 1, channels));

    GrXferProcessor::BlendInfo blendInfo;
    blendInfo.reset();
    this->flushBlend(blendInfo, GrSwizzle::RGBA());
    this->flushColorWrite(true);
    this->flushDrawFace(GrPipelineBuilder::kBoth_DrawFace);
    this->flushHWAAState(glRT, false, false);
    this->disableScissor();
    GrStencilSettings stencil;
    stencil.setDisabled();
    this->flushStencil(stencil);

    GL_CALL(DrawArrays(GR_GL_LINE_LOOP, 0, 4));
}

bool GrGLGpu::copySurfaceAsDraw(GrSurface* dst,
    GrSurface* src,
    const SkIRect& srcRect,
    const SkIPoint& dstPoint)
{
    GrGLTexture* srcTex = static_cast<GrGLTexture*>(src->asTexture());
    int progIdx = TextureTargetToCopyProgramIdx(srcTex->target());

    if (!fCopyPrograms[progIdx].fProgram) {
        if (!this->createCopyProgram(progIdx)) {
            SkDebugf("Failed to create copy program.\n");
            return false;
        }
    }

    int w = srcRect.width();
    int h = srcRect.height();

    GrTextureParams params(SkShader::kClamp_TileMode, GrTextureParams::kNone_FilterMode);
    this->bindTexture(0, params, true, srcTex);

    GrGLIRect dstVP;
    this->bindSurfaceFBOForCopy(dst, GR_GL_FRAMEBUFFER, &dstVP, kDst_TempFBOTarget);
    this->flushViewport(dstVP);
    fHWBoundRenderTargetUniqueID = SK_InvalidUniqueID;

    SkIRect dstRect = SkIRect::MakeXYWH(dstPoint.fX, dstPoint.fY, w, h);

    GL_CALL(UseProgram(fCopyPrograms[progIdx].fProgram));
    fHWProgramID = fCopyPrograms[progIdx].fProgram;

    fHWVertexArrayState.setVertexArrayID(this, 0);

    GrGLAttribArrayState* attribs = fHWVertexArrayState.bindInternalVertexArray(this);
    attribs->set(this, 0, fCopyProgramArrayBuffer, kVec2f_GrVertexAttribType, 2 * sizeof(GrGLfloat),
        0);
=======
    GL_CALL(GenBuffers(1, &fCopyProgram.fArrayBuffer));
    fHWGeometryState.setVertexBufferID(this, fCopyProgram.fArrayBuffer);
    static const GrGLfloat vdata[] = {
        0, 0,
        0, 1,
        1, 0,
        1, 1
    };
    GL_ALLOC_CALL(this->glInterface(),
                  BufferData(GR_GL_ARRAY_BUFFER,
                             (GrGLsizeiptr) sizeof(vdata),
                             vdata,  // data ptr
                             GR_GL_STATIC_DRAW));
}

void GrGLGpu::copySurfaceAsDraw(GrSurface* dst,
                                GrSurface* src,
                                const SkIRect& srcRect,
                                const SkIPoint& dstPoint) {
    int w = srcRect.width();
    int h = srcRect.height();

    GrGLTexture* srcTex = static_cast<GrGLTexture*>(src->asTexture());
    GrTextureParams params(SkShader::kClamp_TileMode, GrTextureParams::kNone_FilterMode);
    this->bindTexture(0, params, srcTex);

    GrGLRenderTarget* dstRT = static_cast<GrGLRenderTarget*>(dst->asRenderTarget());
    SkIRect dstRect = SkIRect::MakeXYWH(dstPoint.fX, dstPoint.fY, w, h);
    this->flushRenderTarget(dstRT, &dstRect);

    GL_CALL(UseProgram(fCopyProgram.fProgram));
    fHWProgramID = fCopyProgram.fProgram;

    fHWGeometryState.setVertexArrayID(this, 0);

    GrGLAttribArrayState* attribs =
        fHWGeometryState.bindArrayAndBufferToDraw(this, fCopyProgram.fArrayBuffer);
    attribs->set(this, 0, fCopyProgram.fArrayBuffer, 2, GR_GL_FLOAT, false,
                    2 * sizeof(GrGLfloat), 0);
>>>>>>> miniblink49
    attribs->disableUnusedArrays(this, 0x1);

    // dst rect edges in NDC (-1 to 1)
    int dw = dst->width();
    int dh = dst->height();
    GrGLfloat dx0 = 2.f * dstPoint.fX / dw - 1.f;
    GrGLfloat dx1 = 2.f * (dstPoint.fX + w) / dw - 1.f;
    GrGLfloat dy0 = 2.f * dstPoint.fY / dh - 1.f;
    GrGLfloat dy1 = 2.f * (dstPoint.fY + h) / dh - 1.f;
    if (kBottomLeft_GrSurfaceOrigin == dst->origin()) {
        dy0 = -dy0;
        dy1 = -dy1;
    }

<<<<<<< HEAD
    GrGLfloat sx0 = (GrGLfloat)srcRect.fLeft;
    GrGLfloat sx1 = (GrGLfloat)(srcRect.fLeft + w);
    GrGLfloat sy0 = (GrGLfloat)srcRect.fTop;
    GrGLfloat sy1 = (GrGLfloat)(srcRect.fTop + h);
    int sh = src->height();
    if (kBottomLeft_GrSurfaceOrigin == src->origin()) {
        sy0 = sh - sy0;
        sy1 = sh - sy1;
    }
    // src rect edges in normalized texture space (0 to 1) unless we're using a RECTANGLE texture.
    GrGLenum srcTarget = srcTex->target();
    if (GR_GL_TEXTURE_RECTANGLE != srcTarget) {
        int sw = src->width();
        sx0 /= sw;
        sx1 /= sw;
        sy0 /= sh;
        sy1 /= sh;
    }

    GL_CALL(Uniform4f(fCopyPrograms[progIdx].fPosXformUniform, dx1 - dx0, dy1 - dy0, dx0, dy0));
    GL_CALL(Uniform4f(fCopyPrograms[progIdx].fTexCoordXformUniform,
        sx1 - sx0, sy1 - sy0, sx0, sy0));
    GL_CALL(Uniform1i(fCopyPrograms[progIdx].fTextureUniform, 0));

    GrXferProcessor::BlendInfo blendInfo;
    blendInfo.reset();
    this->flushBlend(blendInfo, GrSwizzle::RGBA());
    this->flushColorWrite(true);
    this->flushDrawFace(GrPipelineBuilder::kBoth_DrawFace);
    this->flushHWAAState(nullptr, false, false);
=======
    // src rect edges in normalized texture space (0 to 1)
    int sw = src->width();
    int sh = src->height();
    GrGLfloat sx0 = (GrGLfloat)srcRect.fLeft / sw;
    GrGLfloat sx1 = (GrGLfloat)(srcRect.fLeft + w) / sw;
    GrGLfloat sy0 = (GrGLfloat)srcRect.fTop / sh;
    GrGLfloat sy1 = (GrGLfloat)(srcRect.fTop + h) / sh;
    if (kBottomLeft_GrSurfaceOrigin == src->origin()) {
        sy0 = 1.f - sy0;
        sy1 = 1.f - sy1;
    }

    GL_CALL(Uniform4f(fCopyProgram.fPosXformUniform, dx1 - dx0, dy1 - dy0, dx0, dy0));
    GL_CALL(Uniform4f(fCopyProgram.fTexCoordXformUniform, sx1 - sx0, sy1 - sy0, sx0, sy0));
    GL_CALL(Uniform1i(fCopyProgram.fTextureUniform, 0));

    GrXferProcessor::BlendInfo blendInfo;
    blendInfo.reset();
    this->flushBlend(blendInfo);
    this->flushColorWrite(true);
    this->flushDither(false);
    this->flushDrawFace(GrPipelineBuilder::kBoth_DrawFace);
    this->flushHWAAState(dstRT, false);
>>>>>>> miniblink49
    this->disableScissor();
    GrStencilSettings stencil;
    stencil.setDisabled();
    this->flushStencil(stencil);

    GL_CALL(DrawArrays(GR_GL_TRIANGLE_STRIP, 0, 4));
<<<<<<< HEAD
    this->unbindTextureFBOForCopy(GR_GL_FRAMEBUFFER, dst);
    this->didWriteToSurface(dst, &dstRect);

    return true;
}

void GrGLGpu::copySurfaceAsCopyTexSubImage(GrSurface* dst,
    GrSurface* src,
    const SkIRect& srcRect,
    const SkIPoint& dstPoint)
{
    SkASSERT(can_copy_texsubimage(dst, src, this));
    GrGLIRect srcVP;
    this->bindSurfaceFBOForCopy(src, GR_GL_FRAMEBUFFER, &srcVP, kSrc_TempFBOTarget);
=======
}

void GrGLGpu::copySurfaceAsCopyTexSubImage(GrSurface* dst,
                                           GrSurface* src,
                                           const SkIRect& srcRect,
                                           const SkIPoint& dstPoint) {
    SkASSERT(can_copy_texsubimage(dst, src, this));
    GrGLuint srcFBO;
    GrGLIRect srcVP;
    srcFBO = this->bindSurfaceAsFBO(src, GR_GL_FRAMEBUFFER, &srcVP, kSrc_TempFBOTarget);
>>>>>>> miniblink49
    GrGLTexture* dstTex = static_cast<GrGLTexture*>(dst->asTexture());
    SkASSERT(dstTex);
    // We modified the bound FBO
    fHWBoundRenderTargetUniqueID = SK_InvalidUniqueID;
    GrGLIRect srcGLRect;
    srcGLRect.setRelativeTo(srcVP,
<<<<<<< HEAD
        srcRect.fLeft,
        srcRect.fTop,
        srcRect.width(),
        srcRect.height(),
        src->origin());

    this->setScratchTextureUnit();
    GL_CALL(BindTexture(dstTex->target(), dstTex->textureID()));
=======
                            srcRect.fLeft,
                            srcRect.fTop,
                            srcRect.width(),
                            srcRect.height(),
                            src->origin());

    this->setScratchTextureUnit();
    GL_CALL(BindTexture(GR_GL_TEXTURE_2D, dstTex->textureID()));
>>>>>>> miniblink49
    GrGLint dstY;
    if (kBottomLeft_GrSurfaceOrigin == dst->origin()) {
        dstY = dst->height() - (dstPoint.fY + srcGLRect.fHeight);
    } else {
        dstY = dstPoint.fY;
    }
<<<<<<< HEAD
    GL_CALL(CopyTexSubImage2D(dstTex->target(), 0,
        dstPoint.fX, dstY,
        srcGLRect.fLeft, srcGLRect.fBottom,
        srcGLRect.fWidth, srcGLRect.fHeight));
    this->unbindTextureFBOForCopy(GR_GL_FRAMEBUFFER, src);
    SkIRect dstRect = SkIRect::MakeXYWH(dstPoint.fX, dstPoint.fY,
        srcRect.width(), srcRect.height());
    this->didWriteToSurface(dst, &dstRect);
}

bool GrGLGpu::copySurfaceAsBlitFramebuffer(GrSurface* dst,
    GrSurface* src,
    const SkIRect& srcRect,
    const SkIPoint& dstPoint)
{
    SkASSERT(can_blit_framebuffer(dst, src, this));
    SkIRect dstRect = SkIRect::MakeXYWH(dstPoint.fX, dstPoint.fY,
        srcRect.width(), srcRect.height());
=======
    GL_CALL(CopyTexSubImage2D(GR_GL_TEXTURE_2D, 0,
                                dstPoint.fX, dstY,
                                srcGLRect.fLeft, srcGLRect.fBottom,
                                srcGLRect.fWidth, srcGLRect.fHeight));
    if (srcFBO) {
        this->unbindTextureFromFBO(GR_GL_FRAMEBUFFER);
    }
}

bool GrGLGpu::copySurfaceAsBlitFramebuffer(GrSurface* dst,
                                           GrSurface* src,
                                           const SkIRect& srcRect,
                                           const SkIPoint& dstPoint) {
    SkASSERT(can_blit_framebuffer(dst, src, this));
    SkIRect dstRect = SkIRect::MakeXYWH(dstPoint.fX, dstPoint.fY,
                                        srcRect.width(), srcRect.height());
>>>>>>> miniblink49
    if (dst == src) {
        if (SkIRect::IntersectsNoEmptyCheck(dstRect, srcRect)) {
            return false;
        }
    }

<<<<<<< HEAD
    GrGLIRect dstVP;
    GrGLIRect srcVP;
    this->bindSurfaceFBOForCopy(dst, GR_GL_DRAW_FRAMEBUFFER, &dstVP, kDst_TempFBOTarget);
    this->bindSurfaceFBOForCopy(src, GR_GL_READ_FRAMEBUFFER, &srcVP, kSrc_TempFBOTarget);
=======
    GrGLuint dstFBO;
    GrGLuint srcFBO;
    GrGLIRect dstVP;
    GrGLIRect srcVP;
    dstFBO = this->bindSurfaceAsFBO(dst, GR_GL_DRAW_FRAMEBUFFER, &dstVP,
                                    kDst_TempFBOTarget);
    srcFBO = this->bindSurfaceAsFBO(src, GR_GL_READ_FRAMEBUFFER, &srcVP,
                                    kSrc_TempFBOTarget);
>>>>>>> miniblink49
    // We modified the bound FBO
    fHWBoundRenderTargetUniqueID = SK_InvalidUniqueID;
    GrGLIRect srcGLRect;
    GrGLIRect dstGLRect;
    srcGLRect.setRelativeTo(srcVP,
<<<<<<< HEAD
        srcRect.fLeft,
        srcRect.fTop,
        srcRect.width(),
        srcRect.height(),
        src->origin());
    dstGLRect.setRelativeTo(dstVP,
        dstRect.fLeft,
        dstRect.fTop,
        dstRect.width(),
        dstRect.height(),
        dst->origin());
=======
                            srcRect.fLeft,
                            srcRect.fTop,
                            srcRect.width(),
                            srcRect.height(),
                            src->origin());
    dstGLRect.setRelativeTo(dstVP,
                            dstRect.fLeft,
                            dstRect.fTop,
                            dstRect.width(),
                            dstRect.height(),
                            dst->origin());
>>>>>>> miniblink49

    // BlitFrameBuffer respects the scissor, so disable it.
    this->disableScissor();

    GrGLint srcY0;
    GrGLint srcY1;
    // Does the blit need to y-mirror or not?
    if (src->origin() == dst->origin()) {
        srcY0 = srcGLRect.fBottom;
        srcY1 = srcGLRect.fBottom + srcGLRect.fHeight;
    } else {
        srcY0 = srcGLRect.fBottom + srcGLRect.fHeight;
        srcY1 = srcGLRect.fBottom;
    }
    GL_CALL(BlitFramebuffer(srcGLRect.fLeft,
<<<<<<< HEAD
        srcY0,
        srcGLRect.fLeft + srcGLRect.fWidth,
        srcY1,
        dstGLRect.fLeft,
        dstGLRect.fBottom,
        dstGLRect.fLeft + dstGLRect.fWidth,
        dstGLRect.fBottom + dstGLRect.fHeight,
        GR_GL_COLOR_BUFFER_BIT, GR_GL_NEAREST));
    this->unbindTextureFBOForCopy(GR_GL_DRAW_FRAMEBUFFER, dst);
    this->unbindTextureFBOForCopy(GR_GL_READ_FRAMEBUFFER, src);
    this->didWriteToSurface(dst, &dstRect);
    return true;
}

// Manual implementation of mipmap generation, to work around driver bugs w/sRGB.
// Uses draw calls to do a series of downsample operations to successive mips.
// If this returns false, then the calling code falls back to using glGenerateMipmap.
bool GrGLGpu::generateMipmap(GrGLTexture* texture, bool gammaCorrect)
{
    // Our iterative downsample requires the ability to limit which level we're sampling:
    if (!this->glCaps().doManualMipmapping()) {
        return false;
    }

    // Mipmaps are only supported on 2D textures:
    if (GR_GL_TEXTURE_2D != texture->target()) {
        return false;
    }

    // We need to be able to render to the texture for this to work:
    if (!this->caps()->isConfigRenderable(texture->config(), false)) {
        return false;
    }

    // If we're mipping an sRGB texture, we need to ensure FB sRGB is correct:
    if (GrPixelConfigIsSRGB(texture->config())) {
        // If we have write-control, just set the state that we want:
        if (this->glCaps().srgbWriteControl()) {
            this->flushFramebufferSRGB(gammaCorrect);
        } else if (!gammaCorrect) {
            // If we don't have write-control we can't do non-gamma-correct mipmapping:
            return false;
        }
    }

    int width = texture->width();
    int height = texture->height();
    int levelCount = SkMipMap::ComputeLevelCount(width, height) + 1;

    // Define all mips, if we haven't previously done so:
    if (0 == texture->texturePriv().maxMipMapLevel()) {
        GrGLenum internalFormat;
        GrGLenum externalFormat;
        GrGLenum externalType;
        if (!this->glCaps().getTexImageFormats(texture->config(), texture->config(),
                &internalFormat, &externalFormat, &externalType)) {
            return false;
        }

        for (GrGLint level = 1; level < levelCount; ++level) {
            // Define the next mip:
            width = SkTMax(1, width / 2);
            height = SkTMax(1, height / 2);
            GL_ALLOC_CALL(this->glInterface(), TexImage2D(GR_GL_TEXTURE_2D, level, internalFormat, width, height, 0, externalFormat, externalType, nullptr));
        }
    }

    // Create (if necessary), then bind temporary FBO:
    if (0 == fTempDstFBOID) {
        GL_CALL(GenFramebuffers(1, &fTempDstFBOID));
    }
    GL_CALL(BindFramebuffer(GR_GL_FRAMEBUFFER, fTempDstFBOID));
    fHWBoundRenderTargetUniqueID = SK_InvalidUniqueID;

    // Bind the texture, to get things configured for filtering.
    // We'll be changing our base level further below:
    this->setTextureUnit(0);
    GrTextureParams params(SkShader::kClamp_TileMode, GrTextureParams::kBilerp_FilterMode);
    this->bindTexture(0, params, gammaCorrect, texture);

    // Vertex data:
    if (!fMipmapProgramArrayBuffer) {
        static const GrGLfloat vdata[] = {
            0, 0,
            0, 1,
            1, 0,
            1, 1
        };
        fMipmapProgramArrayBuffer.reset(GrGLBuffer::Create(this, sizeof(vdata),
            kVertex_GrBufferType,
            kStatic_GrAccessPattern, vdata));
    }
    if (!fMipmapProgramArrayBuffer) {
        return false;
    }

    fHWVertexArrayState.setVertexArrayID(this, 0);

    GrGLAttribArrayState* attribs = fHWVertexArrayState.bindInternalVertexArray(this);
    attribs->set(this, 0, fMipmapProgramArrayBuffer, kVec2f_GrVertexAttribType,
        2 * sizeof(GrGLfloat), 0);
    attribs->disableUnusedArrays(this, 0x1);

    // Set "simple" state once:
    GrXferProcessor::BlendInfo blendInfo;
    blendInfo.reset();
    this->flushBlend(blendInfo, GrSwizzle::RGBA());
    this->flushColorWrite(true);
    this->flushDrawFace(GrPipelineBuilder::kBoth_DrawFace);
    this->flushHWAAState(nullptr, false, false);
    this->disableScissor();
    GrStencilSettings stencil;
    stencil.setDisabled();
    this->flushStencil(stencil);

    // Do all the blits:
    width = texture->width();
    height = texture->height();
    GrGLIRect viewport;
    viewport.fLeft = 0;
    viewport.fBottom = 0;
    for (GrGLint level = 1; level < levelCount; ++level) {
        // Get and bind the program for this particular downsample (filter shape can vary):
        int progIdx = TextureSizeToMipmapProgramIdx(width, height);
        if (!fMipmapPrograms[progIdx].fProgram) {
            if (!this->createMipmapProgram(progIdx)) {
                SkDebugf("Failed to create mipmap program.\n");
                return false;
            }
        }
        GL_CALL(UseProgram(fMipmapPrograms[progIdx].fProgram));
        fHWProgramID = fMipmapPrograms[progIdx].fProgram;

        // Texcoord uniform is expected to contain (1/w, (w-1)/w, 1/h, (h-1)/h)
        const float invWidth = 1.0f / width;
        const float invHeight = 1.0f / height;
        GL_CALL(Uniform4f(fMipmapPrograms[progIdx].fTexCoordXformUniform,
            invWidth, (width - 1) * invWidth, invHeight, (height - 1) * invHeight));
        GL_CALL(Uniform1i(fMipmapPrograms[progIdx].fTextureUniform, 0));

        // Only sample from previous mip
        GL_CALL(TexParameteri(GR_GL_TEXTURE_2D, GR_GL_TEXTURE_BASE_LEVEL, level - 1));

        GL_CALL(FramebufferTexture2D(GR_GL_FRAMEBUFFER, GR_GL_COLOR_ATTACHMENT0,
            GR_GL_TEXTURE_2D, texture->textureID(), level));

        width = SkTMax(1, width / 2);
        height = SkTMax(1, height / 2);
        viewport.fWidth = width;
        viewport.fHeight = height;
        this->flushViewport(viewport);

        GL_CALL(DrawArrays(GR_GL_TRIANGLE_STRIP, 0, 4));
    }

    // Unbind:
    GL_CALL(FramebufferTexture2D(GR_GL_FRAMEBUFFER, GR_GL_COLOR_ATTACHMENT0,
        GR_GL_TEXTURE_2D, 0, 0));

    return true;
}

void GrGLGpu::onGetMultisampleSpecs(GrRenderTarget* rt,
    const GrStencilSettings& stencil,
    int* effectiveSampleCnt,
    SkAutoTDeleteArray<SkPoint>* sampleLocations)
{
    SkASSERT(!rt->hasMixedSamples() || rt->renderTargetPriv().getStencilAttachment() || stencil.isDisabled());

    this->flushStencil(stencil);
    this->flushHWAAState(rt, true, !stencil.isDisabled());
    this->flushRenderTarget(static_cast<GrGLRenderTarget*>(rt), &SkIRect::EmptyIRect());

    if (0 != this->caps()->maxRasterSamples()) {
        GR_GL_GetIntegerv(this->glInterface(), GR_GL_EFFECTIVE_RASTER_SAMPLES, effectiveSampleCnt);
    } else {
        GR_GL_GetIntegerv(this->glInterface(), GR_GL_SAMPLES, effectiveSampleCnt);
    }

    SkASSERT(*effectiveSampleCnt >= rt->desc().fSampleCnt);

    if (this->caps()->sampleLocationsSupport()) {
        sampleLocations->reset(new SkPoint[*effectiveSampleCnt]);
        for (int i = 0; i < *effectiveSampleCnt; ++i) {
            GrGLfloat pos[2];
            GL_CALL(GetMultisamplefv(GR_GL_SAMPLE_POSITION, i, pos));
            if (kTopLeft_GrSurfaceOrigin == rt->origin()) {
                (*sampleLocations)[i].set(pos[0], pos[1]);
            } else {
                (*sampleLocations)[i].set(pos[0], 1 - pos[1]);
            }
        }
    }
}

void GrGLGpu::xferBarrier(GrRenderTarget* rt, GrXferBarrierType type)
{
    SkASSERT(type);
    switch (type) {
    case kTexture_GrXferBarrierType: {
        GrGLRenderTarget* glrt = static_cast<GrGLRenderTarget*>(rt);
        if (glrt->textureFBOID() != glrt->renderFBOID()) {
            // The render target uses separate storage so no need for glTextureBarrier.
            // FIXME: The render target will resolve automatically when its texture is bound,
            // but we could resolve only the bounds that will be read if we do it here instead.
            return;
        }
        SkASSERT(this->caps()->textureBarrierSupport());
        GL_CALL(TextureBarrier());
        return;
    }
    case kBlend_GrXferBarrierType:
        SkASSERT(GrCaps::kAdvanced_BlendEquationSupport == this->caps()->blendEquationSupport());
        GL_CALL(BlendBarrier());
        return;
    default:
        break; // placate compiler warnings that kNone not handled
    }
}

GrBackendObject GrGLGpu::createTestingOnlyBackendTexture(void* pixels, int w, int h,
    GrPixelConfig config, bool /*isRT*/)
{
    if (!this->caps()->isConfigTexturable(config)) {
        return false;
    }
    GrGLTextureInfo* info = new GrGLTextureInfo;
    info->fTarget = GR_GL_TEXTURE_2D;
    info->fID = 0;
    GL_CALL(GenTextures(1, &info->fID));
    GL_CALL(ActiveTexture(GR_GL_TEXTURE0));
    GL_CALL(PixelStorei(GR_GL_UNPACK_ALIGNMENT, 1));
    GL_CALL(BindTexture(info->fTarget, info->fID));
    fHWBoundTextureUniqueIDs[0] = 0;
    GL_CALL(TexParameteri(info->fTarget, GR_GL_TEXTURE_MAG_FILTER, GR_GL_NEAREST));
    GL_CALL(TexParameteri(info->fTarget, GR_GL_TEXTURE_MIN_FILTER, GR_GL_NEAREST));
    GL_CALL(TexParameteri(info->fTarget, GR_GL_TEXTURE_WRAP_S, GR_GL_CLAMP_TO_EDGE));
    GL_CALL(TexParameteri(info->fTarget, GR_GL_TEXTURE_WRAP_T, GR_GL_CLAMP_TO_EDGE));

    GrGLenum internalFormat;
    GrGLenum externalFormat;
    GrGLenum externalType;

    if (!this->glCaps().getTexImageFormats(config, config, &internalFormat, &externalFormat,
            &externalType)) {
        delete info;
#ifdef SK_IGNORE_GL_TEXTURE_TARGET
        return 0;
#else
        return reinterpret_cast<GrBackendObject>(nullptr);
#endif
    }

    GL_CALL(TexImage2D(info->fTarget, 0, internalFormat, w, h, 0, externalFormat,
        externalType, pixels));

#ifdef SK_IGNORE_GL_TEXTURE_TARGET
    GrGLuint id = info->fID;
    delete info;
    return id;
#else
    return reinterpret_cast<GrBackendObject>(info);
#endif
}

bool GrGLGpu::isTestingOnlyBackendTexture(GrBackendObject id) const
{
#ifdef SK_IGNORE_GL_TEXTURE_TARGET
    GrGLuint texID = (GrGLuint)id;
#else
    GrGLuint texID = reinterpret_cast<const GrGLTextureInfo*>(id)->fID;
#endif

    GrGLboolean result;
    GL_CALL_RET(result, IsTexture(texID));

    return (GR_GL_TRUE == result);
}

void GrGLGpu::deleteTestingOnlyBackendTexture(GrBackendObject id, bool abandonTexture)
{
#ifdef SK_IGNORE_GL_TEXTURE_TARGET
    GrGLuint texID = (GrGLuint)id;
#else
    const GrGLTextureInfo* info = reinterpret_cast<const GrGLTextureInfo*>(id);
    GrGLuint texID = info->fID;
#endif

    if (!abandonTexture) {
        GL_CALL(DeleteTextures(1, &texID));
    }

#ifndef SK_IGNORE_GL_TEXTURE_TARGET
    delete info;
#endif
}

void GrGLGpu::resetShaderCacheForTesting() const
{
    fProgramCache->abandon();
}

///////////////////////////////////////////////////////////////////////////////

GrGLAttribArrayState* GrGLGpu::HWVertexArrayState::bindInternalVertexArray(GrGLGpu* gpu,
    const GrGLBuffer* ibuf)
{
    GrGLAttribArrayState* attribState;

    if (gpu->glCaps().isCoreProfile()) {
        if (!fCoreProfileVertexArray) {
            GrGLuint arrayID;
            GR_GL_CALL(gpu->glInterface(), GenVertexArrays(1, &arrayID));
            int attrCount = gpu->glCaps().maxVertexAttributes();
            fCoreProfileVertexArray = new GrGLVertexArray(arrayID, attrCount);
        }
        if (ibuf) {
            attribState = fCoreProfileVertexArray->bindWithIndexBuffer(gpu, ibuf);
        } else {
            attribState = fCoreProfileVertexArray->bind(gpu);
        }
    } else {
        if (ibuf) {
            // bindBuffer implicitly binds VAO 0 when binding an index buffer.
            gpu->bindBuffer(kIndex_GrBufferType, ibuf);
=======
                            srcY0,
                            srcGLRect.fLeft + srcGLRect.fWidth,
                            srcY1,
                            dstGLRect.fLeft,
                            dstGLRect.fBottom,
                            dstGLRect.fLeft + dstGLRect.fWidth,
                            dstGLRect.fBottom + dstGLRect.fHeight,
                            GR_GL_COLOR_BUFFER_BIT, GR_GL_NEAREST));
    if (dstFBO) {
        this->unbindTextureFromFBO(GR_GL_DRAW_FRAMEBUFFER);
    }
    if (srcFBO) {
        this->unbindTextureFromFBO(GR_GL_READ_FRAMEBUFFER);
    }
    return true;
}

void GrGLGpu::xferBarrier(GrRenderTarget* rt, GrXferBarrierType type) {
    switch (type) {
        case kTexture_GrXferBarrierType: {
            GrGLRenderTarget* glrt = static_cast<GrGLRenderTarget*>(rt);
            if (glrt->textureFBOID() != glrt->renderFBOID()) {
                // The render target uses separate storage so no need for glTextureBarrier.
                // FIXME: The render target will resolve automatically when its texture is bound,
                // but we could resolve only the bounds that will be read if we do it here instead.
                return;
            }
            SkASSERT(this->caps()->textureBarrierSupport());
            GL_CALL(TextureBarrier());
            return;
        }
        case kBlend_GrXferBarrierType:
            SkASSERT(GrCaps::kAdvanced_BlendEquationSupport ==
                     this->caps()->blendEquationSupport());
            GL_CALL(BlendBarrier());
            return;
    }
}

void GrGLGpu::didAddGpuTraceMarker() {
    if (this->caps()->gpuTracingSupport()) {
        const GrTraceMarkerSet& markerArray = this->getActiveTraceMarkers();
        SkString markerString = markerArray.toStringLast();
#if GR_FORCE_GPU_TRACE_DEBUGGING
        SkDebugf("%s\n", markerString.c_str());
#else
        GL_CALL(PushGroupMarker(0, markerString.c_str()));
#endif
    }
}

void GrGLGpu::didRemoveGpuTraceMarker() {
    if (this->caps()->gpuTracingSupport()) {
#if GR_FORCE_GPU_TRACE_DEBUGGING
        SkDebugf("Pop trace marker.\n");
#else
        GL_CALL(PopGroupMarker());
#endif
    }
}

///////////////////////////////////////////////////////////////////////////////
GrGLAttribArrayState* GrGLGpu::HWGeometryState::bindArrayAndBuffersToDraw(
                                                GrGLGpu* gpu,
                                                const GrGLVertexBuffer* vbuffer,
                                                const GrGLIndexBuffer* ibuffer) {
    SkASSERT(vbuffer);
    GrGLuint vbufferID = vbuffer->bufferID();
    GrGLuint* ibufferIDPtr = NULL;
    GrGLuint ibufferID;
    if (ibuffer) {
        ibufferID = ibuffer->bufferID();
        ibufferIDPtr = &ibufferID;
    }
    return this->internalBind(gpu, vbufferID, ibufferIDPtr);
}

GrGLAttribArrayState* GrGLGpu::HWGeometryState::bindArrayAndBufferToDraw(GrGLGpu* gpu,
                                                                         GrGLuint vbufferID) {
    return this->internalBind(gpu, vbufferID, NULL);
}

GrGLAttribArrayState* GrGLGpu::HWGeometryState::bindArrayAndBuffersToDraw(GrGLGpu* gpu,
                                                                          GrGLuint vbufferID,
                                                                          GrGLuint ibufferID) {
    return this->internalBind(gpu, vbufferID, &ibufferID);
}

GrGLAttribArrayState* GrGLGpu::HWGeometryState::internalBind(GrGLGpu* gpu,
                                                             GrGLuint vbufferID,
                                                             GrGLuint* ibufferID) {
    GrGLAttribArrayState* attribState;

    if (gpu->glCaps().isCoreProfile() && 0 != vbufferID) {
        if (!fVBOVertexArray) {
            GrGLuint arrayID;
            GR_GL_CALL(gpu->glInterface(), GenVertexArrays(1, &arrayID));
            int attrCount = gpu->glCaps().maxVertexAttributes();
            fVBOVertexArray = SkNEW_ARGS(GrGLVertexArray, (arrayID, attrCount));
        }
        if (ibufferID) {
            attribState = fVBOVertexArray->bindWithIndexBuffer(gpu, *ibufferID);
        } else {
            attribState = fVBOVertexArray->bind(gpu);
        }
    } else {
        if (ibufferID) {
            this->setIndexBufferIDOnDefaultVertexArray(gpu, *ibufferID);
>>>>>>> miniblink49
        } else {
            this->setVertexArrayID(gpu, 0);
        }
        int attrCount = gpu->glCaps().maxVertexAttributes();
        if (fDefaultVertexArrayAttribState.count() != attrCount) {
            fDefaultVertexArrayAttribState.resize(attrCount);
        }
        attribState = &fDefaultVertexArrayAttribState;
    }
    return attribState;
}
<<<<<<< HEAD

bool GrGLGpu::onMakeCopyForTextureParams(GrTexture* texture, const GrTextureParams& textureParams,
    GrTextureProducer::CopyParams* copyParams) const
{
    if (textureParams.isTiled() || GrTextureParams::kMipMap_FilterMode == textureParams.filterMode()) {
        GrGLTexture* glTexture = static_cast<GrGLTexture*>(texture);
        if (GR_GL_TEXTURE_EXTERNAL == glTexture->target() || GR_GL_TEXTURE_RECTANGLE == glTexture->target()) {
            copyParams->fFilter = GrTextureParams::kNone_FilterMode;
            copyParams->fWidth = texture->width();
            copyParams->fHeight = texture->height();
            return true;
        }
    }
    return false;
}
=======
>>>>>>> miniblink49
