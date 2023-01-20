/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#ifndef GrGLCaps_DEFINED
#define GrGLCaps_DEFINED

#include <functional>

#include "GrCaps.h"
#include "GrGLStencilAttachment.h"
#include "GrSwizzle.h"
#include "SkChecksum.h"
#include "SkTArray.h"
#include "SkTHash.h"
#include "glsl/GrGLSL.h"

class GrGLContextInfo;
class GrGLSLCaps;
class GrGLRenderTarget;
=======

#ifndef GrGLCaps_DEFINED
#define GrGLCaps_DEFINED

#include "GrCaps.h"
#include "glsl/GrGLSL.h"
#include "GrGLStencilAttachment.h"
#include "SkChecksum.h"
#include "SkTHash.h"
#include "SkTArray.h"

class GrGLContextInfo;
class GrGLSLCaps;
>>>>>>> miniblink49

/**
 * Stores some capabilities of a GL context. Most are determined by the GL
 * version and the extensions string. It also tracks formats that have passed
 * the FBO completeness test.
 */
class GrGLCaps : public GrCaps {
public:
<<<<<<< HEAD
=======
    

>>>>>>> miniblink49
    typedef GrGLStencilAttachment::Format StencilFormat;

    /**
     * The type of MSAA for FBOs supported. Different extensions have different
     * semantics of how / when a resolve is performed.
     */
    enum MSFBOType {
        /**
         * no support for MSAA FBOs
         */
        kNone_MSFBOType = 0,
        /**
         * GL3.0-style MSAA FBO (GL_ARB_framebuffer_object).
         */
        kDesktop_ARB_MSFBOType,
        /**
         * earlier GL_EXT_framebuffer* extensions
         */
        kDesktop_EXT_MSFBOType,
        /**
         * Similar to kDesktop_ARB but with additional restrictions on glBlitFramebuffer.
         */
        kES_3_0_MSFBOType,
        /**
         * GL_APPLE_framebuffer_multisample ES extension
         */
        kES_Apple_MSFBOType,
        /**
         * GL_IMG_multisampled_render_to_texture. This variation does not have MSAA renderbuffers.
         * Instead the texture is multisampled when bound to the FBO and then resolved automatically
         * when read. It also defines an alternate value for GL_MAX_SAMPLES (which we call
         * GR_GL_MAX_SAMPLES_IMG).
         */
        kES_IMG_MsToTexture_MSFBOType,
        /**
         * GL_EXT_multisampled_render_to_texture. Same as the IMG one above but uses the standard
         * GL_MAX_SAMPLES value.
         */
        kES_EXT_MsToTexture_MSFBOType,
        /**
         * GL_NV_framebuffer_mixed_samples.
         */
        kMixedSamples_MSFBOType,

        kLast_MSFBOType = kMixedSamples_MSFBOType
    };

<<<<<<< HEAD
    enum BlitFramebufferSupport {
        kNone_BlitFramebufferSupport,
        /**
         * ANGLE exposes a limited blit framebuffer extension that does not allow for stretching
         * or mirroring.
         */
        kNoScalingNoMirroring_BlitFramebufferSupport,
        kFull_BlitFramebufferSupport
    };

    enum InvalidateFBType {
        kNone_InvalidateFBType,
        kDiscard_InvalidateFBType, //<! glDiscardFramebuffer()
        kInvalidate_InvalidateFBType, //<! glInvalidateFramebuffer()
=======
    enum InvalidateFBType {
        kNone_InvalidateFBType,
        kDiscard_InvalidateFBType,       //<! glDiscardFramebuffer()
        kInvalidate_InvalidateFBType,     //<! glInvalidateFramebuffer()
>>>>>>> miniblink49

        kLast_InvalidateFBType = kInvalidate_InvalidateFBType
    };

    enum MapBufferType {
        kNone_MapBufferType,
<<<<<<< HEAD
        kMapBuffer_MapBufferType, // glMapBuffer()
        kMapBufferRange_MapBufferType, // glMapBufferRange()
        kChromium_MapBufferType, // GL_CHROMIUM_map_sub
=======
        kMapBuffer_MapBufferType,         // glMapBuffer()
        kMapBufferRange_MapBufferType,    // glMapBufferRange()
        kChromium_MapBufferType,          // GL_CHROMIUM_map_sub
>>>>>>> miniblink49

        kLast_MapBufferType = kChromium_MapBufferType,
    };

<<<<<<< HEAD
    enum TransferBufferType {
        kNone_TransferBufferType,
        kPBO_TransferBufferType, // ARB_pixel_buffer_object
        kChromium_TransferBufferType, // CHROMIUM_pixel_transfer_buffer_object

        kLast_TransferBufferType = kChromium_TransferBufferType,
    };

=======
>>>>>>> miniblink49
    /**
     * Initializes the GrGLCaps to the set of features supported in the current
     * OpenGL context accessible via ctxInfo.
     */
    GrGLCaps(const GrContextOptions& contextOptions, const GrGLContextInfo& ctxInfo,
<<<<<<< HEAD
        const GrGLInterface* glInterface);

    bool isConfigTexturable(GrPixelConfig config) const override
    {
        return SkToBool(fConfigTable[config].fFlags & ConfigInfo::kTextureable_Flag);
    }

    bool isConfigRenderable(GrPixelConfig config, bool withMSAA) const override
    {
        if (withMSAA) {
            return SkToBool(fConfigTable[config].fFlags & ConfigInfo::kRenderableWithMSAA_Flag);
        } else {
            return SkToBool(fConfigTable[config].fFlags & ConfigInfo::kRenderable_Flag);
        }
    }

    bool isConfigTexSupportEnabled(GrPixelConfig config) const
    {
        return SkToBool(fConfigTable[config].fFlags & ConfigInfo::kCanUseTexStorage_Flag);
    }

    bool canUseConfigWithTexelBuffer(GrPixelConfig config) const
    {
        return SkToBool(fConfigTable[config].fFlags & ConfigInfo::kCanUseWithTexelBuffer_Flag);
    }

    /** Returns the mapping between GrPixelConfig components and GL internal format components. */
    const GrSwizzle& configSwizzle(GrPixelConfig config) const
    {
        return fConfigTable[config].fSwizzle;
    }

    GrGLenum configSizedInternalFormat(GrPixelConfig config) const
    {
        return fConfigTable[config].fFormats.fSizedInternalFormat;
    }

    bool getTexImageFormats(GrPixelConfig surfaceConfig, GrPixelConfig externalConfig,
        GrGLenum* internalFormat, GrGLenum* externalFormat,
        GrGLenum* externalType) const;

    bool getCompressedTexImageFormats(GrPixelConfig surfaceConfig, GrGLenum* internalFormat) const;

    bool getReadPixelsFormat(GrPixelConfig surfaceConfig, GrPixelConfig externalConfig,
        GrGLenum* externalFormat, GrGLenum* externalType) const;

    bool getRenderbufferFormat(GrPixelConfig config, GrGLenum* internalFormat) const;

    /**
    * Gets an array of legal stencil formats. These formats are not guaranteed
    * to be supported by the driver but are legal GLenum names given the GL
    * version and extensions supported.
    */
    const SkTArray<StencilFormat, true>& stencilFormats() const
    {
        return fStencilFormats;
    }

    /**
     * Has a stencil format index been found for the config (or we've found that no format works).
     */
    bool hasStencilFormatBeenDeterminedForConfig(GrPixelConfig config) const
    {
        return fConfigTable[config].fStencilFormatIndex != ConfigInfo::kUnknown_StencilIndex;
    }

    /**
     * Gets the stencil format index for the config. This assumes
     * hasStencilFormatBeenDeterminedForConfig has already been checked. Returns a value < 0 if
     * no stencil format is supported with the config. Otherwise, returned index refers to the array
     * returned by stencilFormats().
     */
    int getStencilFormatIndexForConfig(GrPixelConfig config) const
    {
        SkASSERT(this->hasStencilFormatBeenDeterminedForConfig(config));
        return fConfigTable[config].fStencilFormatIndex;
    }

    /**
     * If index is >= 0 this records an index into stencilFormats() as the best stencil format for
     * the config. If < 0 it records that the config has no supported stencil format index.
     */
    void setStencilFormatIndexForConfig(GrPixelConfig config, int index)
    {
        SkASSERT(!this->hasStencilFormatBeenDeterminedForConfig(config));
        if (index < 0) {
            fConfigTable[config].fStencilFormatIndex = ConfigInfo::kUnsupported_StencilFormatIndex;
        } else {
            fConfigTable[config].fStencilFormatIndex = index;
        }
    }
=======
             const GrGLInterface* glInterface);
>>>>>>> miniblink49

    /**
     * Call to note that a color config has been verified as a valid color
     * attachment. This may save future calls to glCheckFramebufferStatus
     * using isConfigVerifiedColorAttachment().
     */
<<<<<<< HEAD
    void markConfigAsValidColorAttachment(GrPixelConfig config)
    {
        fConfigTable[config].fFlags |= ConfigInfo::kVerifiedColorAttachment_Flag;
=======
    void markConfigAsValidColorAttachment(GrPixelConfig config) {
        fVerifiedColorConfigs.markVerified(config);
>>>>>>> miniblink49
    }

    /**
     * Call to check whether a config has been verified as a valid color
     * attachment.
     */
<<<<<<< HEAD
    bool isConfigVerifiedColorAttachment(GrPixelConfig config) const
    {
        return SkToBool(fConfigTable[config].fFlags & ConfigInfo::kVerifiedColorAttachment_Flag);
    }

    /**
=======
    bool isConfigVerifiedColorAttachment(GrPixelConfig config) const {
        return fVerifiedColorConfigs.isVerified(config);
    }

    /**
     * Call to note that a color config / stencil format pair passed
     * FBO status check. We may skip calling glCheckFramebufferStatus for
     * this combination in the future using
     * isColorConfigAndStencilFormatVerified().
     */
    void markColorConfigAndStencilFormatAsVerified(
                    GrPixelConfig config,
                    const GrGLStencilAttachment::Format& format);

    /**
     * Call to check whether color config / stencil format pair has already
     * passed FBO status check.
     */
    bool isColorConfigAndStencilFormatVerified(
                    GrPixelConfig config,
                    const GrGLStencilAttachment::Format& format) const;

    /**
>>>>>>> miniblink49
     * Reports the type of MSAA FBO support.
     */
    MSFBOType msFBOType() const { return fMSFBOType; }

    /**
<<<<<<< HEAD
     * Does the preferred MSAA FBO extension have MSAA renderbuffers?
     */
    bool usesMSAARenderBuffers() const
    {
        return kNone_MSFBOType != fMSFBOType && kES_IMG_MsToTexture_MSFBOType != fMSFBOType && kES_EXT_MsToTexture_MSFBOType != fMSFBOType && kMixedSamples_MSFBOType != fMSFBOType;
    }

    /**
     * What functionality is supported by glBlitFramebuffer.
     */
    BlitFramebufferSupport blitFramebufferSupport() const { return fBlitFramebufferSupport; }

    /**
     * Is the MSAA FBO extension one where the texture is multisampled when bound to an FBO and
     * then implicitly resolved when read.
     */
    bool usesImplicitMSAAResolve() const
    {
        return kES_IMG_MsToTexture_MSFBOType == fMSFBOType || kES_EXT_MsToTexture_MSFBOType == fMSFBOType;
=======
     * Does the supported MSAA FBO extension have MSAA renderbuffers?
     */
    bool usesMSAARenderBuffers() const {
        return kNone_MSFBOType != fMSFBOType &&
               kES_IMG_MsToTexture_MSFBOType != fMSFBOType &&
               kES_EXT_MsToTexture_MSFBOType != fMSFBOType &&
               kMixedSamples_MSFBOType != fMSFBOType;
    }

    /**
     * Is the MSAA FBO extension one where the texture is multisampled when bound to an FBO and
     * then implicitly resolved when read.
     */
    bool usesImplicitMSAAResolve() const {
        return kES_IMG_MsToTexture_MSFBOType == fMSFBOType ||
               kES_EXT_MsToTexture_MSFBOType == fMSFBOType;
>>>>>>> miniblink49
    }

    InvalidateFBType invalidateFBType() const { return fInvalidateFBType; }

    /// What type of buffer mapping is supported?
    MapBufferType mapBufferType() const { return fMapBufferType; }

<<<<<<< HEAD
    /// What type of transfer buffer is supported?
    TransferBufferType transferBufferType() const { return fTransferBufferType; }
=======
    /**
     * Gets an array of legal stencil formats. These formats are not guaranteed
     * to be supported by the driver but are legal GLenum names given the GL
     * version and extensions supported.
     */
    const SkTArray<StencilFormat, true>& stencilFormats() const {
        return fStencilFormats;
    }
>>>>>>> miniblink49

    /// The maximum number of fragment uniform vectors (GLES has min. 16).
    int maxFragmentUniformVectors() const { return fMaxFragmentUniformVectors; }

<<<<<<< HEAD
    /**
     * Depending on the ES extensions present the BGRA external format may
     * correspond to either a BGRA or RGBA internalFormat. On desktop GL it is
     * RGBA.
     */
    bool bgraIsInternalFormat() const;
=======
    /// maximum number of attribute values per vertex
    int maxVertexAttributes() const { return fMaxVertexAttributes; }

    /// maximum number of texture units accessible in the fragment shader.
    int maxFragmentTextureUnits() const { return fMaxFragmentTextureUnits; }

    /// ES requires an extension to support RGBA8 in RenderBufferStorage
    bool rgba8RenderbufferSupport() const { return fRGBA8RenderbufferSupport; }

    /**
     * Depending on the ES extensions present the BGRA external format may
     * correspond either a BGRA or RGBA internalFormat. On desktop GL it is
     * RGBA.
     */
    bool bgraIsInternalFormat() const { return fBGRAIsInternalFormat; }

    /// GL_ARB_texture_swizzle support
    bool textureSwizzleSupport() const { return fTextureSwizzleSupport; }
>>>>>>> miniblink49

    /// Is there support for GL_UNPACK_ROW_LENGTH
    bool unpackRowLengthSupport() const { return fUnpackRowLengthSupport; }

    /// Is there support for GL_UNPACK_FLIP_Y
    bool unpackFlipYSupport() const { return fUnpackFlipYSupport; }

    /// Is there support for GL_PACK_ROW_LENGTH
    bool packRowLengthSupport() const { return fPackRowLengthSupport; }

    /// Is there support for GL_PACK_REVERSE_ROW_ORDER
    bool packFlipYSupport() const { return fPackFlipYSupport; }

    /// Is there support for texture parameter GL_TEXTURE_USAGE
    bool textureUsageSupport() const { return fTextureUsageSupport; }

<<<<<<< HEAD
=======
    /// Is there support for glTexStorage
    bool texStorageSupport() const { return fTexStorageSupport; }

>>>>>>> miniblink49
    /// Is there support for GL_RED and GL_R8
    bool textureRedSupport() const { return fTextureRedSupport; }

    /// Is GL_ARB_IMAGING supported
    bool imagingSupport() const { return fImagingSupport; }

<<<<<<< HEAD
    /// Is there support for Vertex Array Objects?
    bool vertexArrayObjectSupport() const { return fVertexArrayObjectSupport; }

=======
    /// Is GL_ARB_fragment_coord_conventions supported?
    bool fragCoordConventionsSupport() const { return fFragCoordsConventionSupport; }

    /// Is there support for Vertex Array Objects?
    bool vertexArrayObjectSupport() const { return fVertexArrayObjectSupport; }

    /// Is there support for glDraw*Instanced and glVertexAttribDivisor?
    bool instancedDrawingSupport() const { return fInstancedDrawingSupport; }

>>>>>>> miniblink49
    /// Is there support for GL_EXT_direct_state_access?
    bool directStateAccessSupport() const { return fDirectStateAccessSupport; }

    /// Is there support for GL_KHR_debug?
    bool debugSupport() const { return fDebugSupport; }

    /// Is there support for ES2 compatability?
    bool ES2CompatibilitySupport() const { return fES2CompatibilitySupport; }

<<<<<<< HEAD
    /// Is there support for glDraw*Indirect? Note that the baseInstance fields of indirect draw
    /// commands cannot be used unless we have base instance support.
    bool drawIndirectSupport() const { return fDrawIndirectSupport; }

    /// Is there support for glMultiDraw*Indirect? Note that the baseInstance fields of indirect
    /// draw commands cannot be used unless we have base instance support.
    bool multiDrawIndirectSupport() const { return fMultiDrawIndirectSupport; }

    /// Are the baseInstance fields supported in indirect draw commands?
    bool baseInstanceSupport() const { return fBaseInstanceSupport; }

    /// Does the platform have known issuses rendering to floating point when using glDraw*Indirect?
    bool canDrawIndirectToFloat() const { return fCanDrawIndirectToFloat; }

    /// Use indices or vertices in CPU arrays rather than VBOs for dynamic content.
    bool useNonVBOVertexAndIndexDynamicData() const { return fUseNonVBOVertexAndIndexDynamicData; }

    /// Does ReadPixels support reading readConfig pixels from a FBO that is renderTargetConfig?
    bool readPixelsSupported(GrPixelConfig renderTargetConfig,
        GrPixelConfig readConfig,
        std::function<void(GrGLenum, GrGLint*)> getIntegerv,
        std::function<bool()> bindRenderTarget) const;

    bool isCoreProfile() const { return fIsCoreProfile; }

    bool bindFragDataLocationSupport() const { return fBindFragDataLocationSupport; }

    bool bindUniformLocationSupport() const { return fBindUniformLocationSupport; }

    /// Are textures with GL_TEXTURE_RECTANGLE type supported.
    bool rectangleTextureSupport() const { return fRectangleTextureSupport; }

    /// GL_ARB_texture_swizzle
    bool textureSwizzleSupport() const { return fTextureSwizzleSupport; }

    bool mipMapLevelAndLodControlSupport() const { return fMipMapLevelAndLodControlSupport; }

    bool doManualMipmapping() const { return fDoManualMipmapping; }

=======
    /// Can we call glDisable(GL_MULTISAMPLE)?
    bool multisampleDisableSupport() const {
        return fMultisampleDisableSupport;
    }

    /// Use indices or vertices in CPU arrays rather than VBOs for dynamic content.
    bool useNonVBOVertexAndIndexDynamicData() const {
        return fUseNonVBOVertexAndIndexDynamicData;
    }

    /// Does ReadPixels support the provided format/type combo?
    bool readPixelsSupported(const GrGLInterface* intf,
                             GrGLenum format,
                             GrGLenum type,
                             GrGLenum currFboFormat) const;

    bool isCoreProfile() const { return fIsCoreProfile; }


    bool fullClearIsFree() const { return fFullClearIsFree; }

    bool bindFragDataLocationSupport() const { return fBindFragDataLocationSupport; }

>>>>>>> miniblink49
    /**
     * Returns a string containing the caps info.
     */
    SkString dump() const override;

<<<<<<< HEAD
    bool rgba8888PixelsOpsAreSlow() const { return fRGBA8888PixelsOpsAreSlow; }
    bool partialFBOReadIsSlow() const { return fPartialFBOReadIsSlow; }
    bool rgbaToBgraReadbackConversionsAreSlow() const
    {
        return fRGBAToBGRAReadbackConversionsAreSlow;
    }

    const GrGLSLCaps* glslCaps() const { return reinterpret_cast<GrGLSLCaps*>(fShaderCaps.get()); }

private:
    enum ExternalFormatUsage {
        kTexImage_ExternalFormatUsage,
        kOther_ExternalFormatUsage,

        kLast_ExternalFormatUsage = kOther_ExternalFormatUsage
    };
    static const int kExternalFormatUsageCnt = kLast_ExternalFormatUsage + 1;
    bool getExternalFormat(GrPixelConfig surfaceConfig, GrPixelConfig memoryConfig,
        ExternalFormatUsage usage, GrGLenum* externalFormat,
        GrGLenum* externalType) const;

    void init(const GrContextOptions&, const GrGLContextInfo&, const GrGLInterface*);
    void initGLSL(const GrGLContextInfo&);
    bool hasPathRenderingSupport(const GrGLContextInfo&, const GrGLInterface*);

    void onApplyOptionsOverrides(const GrContextOptions& options) override;
=======
    /**
     * LATC can appear under one of three possible names. In order to know
     * which GL internal format to use, we need to keep track of which name
     * we found LATC under. The default is LATC.
     */
    enum LATCAlias {
        kLATC_LATCAlias,
        kRGTC_LATCAlias,
        k3DC_LATCAlias
    };

    LATCAlias latcAlias() const { return fLATCAlias; }

    GrGLSLCaps* glslCaps() const { return reinterpret_cast<GrGLSLCaps*>(fShaderCaps.get()); }

private:
    void init(const GrContextOptions&, const GrGLContextInfo&, const GrGLInterface*);
    bool hasPathRenderingSupport(const GrGLContextInfo&, const GrGLInterface*);

    /**
     * Maintains a bit per GrPixelConfig. It is used to avoid redundantly
     * performing glCheckFrameBufferStatus for the same config.
     */
    struct VerifiedColorConfigs {
        VerifiedColorConfigs() {
            this->reset();
        }

        void reset() {
            for (int i = 0; i < kNumUints; ++i) {
                fVerifiedColorConfigs[i] = 0;
            }
        }

        static const int kNumUints = (kGrPixelConfigCnt  + 31) / 32;
        uint32_t fVerifiedColorConfigs[kNumUints];

        void markVerified(GrPixelConfig config) {
#if !GR_GL_CHECK_FBO_STATUS_ONCE_PER_FORMAT
                return;
#endif
            int u32Idx = config / 32;
            int bitIdx = config % 32;
            fVerifiedColorConfigs[u32Idx] |= 1 << bitIdx;
        }

        bool isVerified(GrPixelConfig config) const {
#if !GR_GL_CHECK_FBO_STATUS_ONCE_PER_FORMAT
            return false;
#endif
            int u32Idx = config / 32;
            int bitIdx = config % 32;
            return SkToBool(fVerifiedColorConfigs[u32Idx] & (1 << bitIdx));
        }
    };
>>>>>>> miniblink49

    void initFSAASupport(const GrGLContextInfo&, const GrGLInterface*);
    void initBlendEqationSupport(const GrGLContextInfo&);
    void initStencilFormats(const GrGLContextInfo&);
    // This must be called after initFSAASupport().
<<<<<<< HEAD
    void initConfigTable(const GrGLContextInfo&, const GrGLInterface* gli, GrGLSLCaps* glslCaps);

    void initShaderPrecisionTable(const GrGLContextInfo& ctxInfo,
        const GrGLInterface* intf,
        GrGLSLCaps* glslCaps);

    GrGLStandard fStandard;

    SkTArray<StencilFormat, true> fStencilFormats;

    int fMaxFragmentUniformVectors;

    MSFBOType fMSFBOType;
    InvalidateFBType fInvalidateFBType;
    MapBufferType fMapBufferType;
    TransferBufferType fTransferBufferType;

=======
    void initConfigRenderableTable(const GrGLContextInfo&);
    void initConfigTexturableTable(const GrGLContextInfo&, const GrGLInterface*);

    bool doReadPixelsSupported(const GrGLInterface* intf, GrGLenum format, GrGLenum type) const;

    void initShaderPrecisionTable(const GrGLContextInfo& ctxInfo,
                                  const GrGLInterface* intf,
                                  GrGLSLCaps* glslCaps);

    // tracks configs that have been verified to pass the FBO completeness when
    // used as a color attachment
    VerifiedColorConfigs fVerifiedColorConfigs;

    SkTArray<StencilFormat, true> fStencilFormats;
    // tracks configs that have been verified to pass the FBO completeness when
    // used as a color attachment when a particular stencil format is used
    // as a stencil attachment.
    SkTArray<VerifiedColorConfigs, true> fStencilVerifiedColorConfigs;

    int fMaxFragmentUniformVectors;
    int fMaxVertexAttributes;
    int fMaxFragmentTextureUnits;

    MSFBOType           fMSFBOType;
    InvalidateFBType    fInvalidateFBType;
    MapBufferType       fMapBufferType;
    LATCAlias           fLATCAlias;

    bool fRGBA8RenderbufferSupport : 1;
    bool fBGRAIsInternalFormat : 1;
    bool fTextureSwizzleSupport : 1;
>>>>>>> miniblink49
    bool fUnpackRowLengthSupport : 1;
    bool fUnpackFlipYSupport : 1;
    bool fPackRowLengthSupport : 1;
    bool fPackFlipYSupport : 1;
    bool fTextureUsageSupport : 1;
<<<<<<< HEAD
    bool fTextureRedSupport : 1;
    bool fImagingSupport : 1;
    bool fVertexArrayObjectSupport : 1;
    bool fDirectStateAccessSupport : 1;
    bool fDebugSupport : 1;
    bool fES2CompatibilitySupport : 1;
    bool fDrawIndirectSupport : 1;
    bool fMultiDrawIndirectSupport : 1;
    bool fBaseInstanceSupport : 1;
    bool fCanDrawIndirectToFloat : 1;
    bool fUseNonVBOVertexAndIndexDynamicData : 1;
    bool fIsCoreProfile : 1;
    bool fBindFragDataLocationSupport : 1;
    bool fRGBA8888PixelsOpsAreSlow : 1;
    bool fPartialFBOReadIsSlow : 1;
    bool fBindUniformLocationSupport : 1;
    bool fRectangleTextureSupport : 1;
    bool fTextureSwizzleSupport : 1;
    bool fMipMapLevelAndLodControlSupport : 1;
    bool fRGBAToBGRAReadbackConversionsAreSlow : 1;
    bool fDoManualMipmapping : 1;

    BlitFramebufferSupport fBlitFramebufferSupport;

    /** Number type of the components (with out considering number of bits.) */
    enum FormatType {
        kNormalizedFixedPoint_FormatType,
        kFloat_FormatType,
    };

    struct ReadPixelsFormat {
        ReadPixelsFormat()
            : fFormat(0)
            , fType(0)
        {
        }
        GrGLenum fFormat;
        GrGLenum fType;
    };

    struct ConfigFormats {
        ConfigFormats()
        {
            // Inits to known bad GL enum values.
            memset(this, 0xAB, sizeof(ConfigFormats));
        }
        GrGLenum fBaseInternalFormat;
        GrGLenum fSizedInternalFormat;

        /** The external format and type are to be used when uploading/downloading data using this
            config where both the CPU data and GrSurface are the same config. To get the external
            format and type when converting between configs while copying to/from memory use
            getExternalFormat().
            The kTexImage external format is usually the same as kOther except for kSRGBA on some
            GL contexts. */
        GrGLenum fExternalFormat[kExternalFormatUsageCnt];
        GrGLenum fExternalType;

        // Either the base or sized internal format depending on the GL and config.
        GrGLenum fInternalFormatTexImage;
        GrGLenum fInternalFormatRenderbuffer;
    };

    struct ConfigInfo {
        ConfigInfo()
            : fStencilFormatIndex(kUnknown_StencilIndex)
            , fFlags(0)
        {
        }

        ConfigFormats fFormats;

        FormatType fFormatType;

        // On ES contexts there are restrictions on type type/format that may be used for
        // ReadPixels. One is implicitly specified by the current FBO's format. The other is
        // queryable. This stores the queried option (lazily).
        ReadPixelsFormat fSecondReadPixelsFormat;

        enum {
            // This indicates that a stencil format has not yet been determined for the config.
            kUnknown_StencilIndex = -1,
            // This indicates that there is no supported stencil format for the config.
            kUnsupported_StencilFormatIndex = -2
        };

        // Index fStencilFormats.
        int fStencilFormatIndex;

        enum {
            kVerifiedColorAttachment_Flag = 0x1,
            kTextureable_Flag = 0x2,
            kRenderable_Flag = 0x4,
            kRenderableWithMSAA_Flag = 0x8,
            kCanUseTexStorage_Flag = 0x10,
            kCanUseWithTexelBuffer_Flag = 0x20,
        };
        uint32_t fFlags;

        GrSwizzle fSwizzle;
    };

    ConfigInfo fConfigTable[kGrPixelConfigCnt];
=======
    bool fTexStorageSupport : 1;
    bool fTextureRedSupport : 1;
    bool fImagingSupport  : 1;
    bool fTwoFormatLimit : 1;
    bool fFragCoordsConventionSupport : 1;
    bool fVertexArrayObjectSupport : 1;
    bool fInstancedDrawingSupport : 1;
    bool fDirectStateAccessSupport : 1;
    bool fDebugSupport : 1;
    bool fES2CompatibilitySupport : 1;
    bool fMultisampleDisableSupport : 1;
    bool fUseNonVBOVertexAndIndexDynamicData : 1;
    bool fIsCoreProfile : 1;
    bool fFullClearIsFree : 1;
    bool fBindFragDataLocationSupport : 1;

    struct ReadPixelsSupportedFormat {
        GrGLenum fFormat;
        GrGLenum fType;
        GrGLenum fFboFormat;

        bool operator==(const ReadPixelsSupportedFormat& rhs) const {
            return fFormat    == rhs.fFormat
                && fType      == rhs.fType
                && fFboFormat == rhs.fFboFormat;
        }
    };
    mutable SkTHashMap<ReadPixelsSupportedFormat, bool> fReadPixelsSupportedCache;
>>>>>>> miniblink49

    typedef GrCaps INHERITED;
};

#endif
