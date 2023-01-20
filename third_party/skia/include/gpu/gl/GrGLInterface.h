/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrGLInterface_DEFINED
#define GrGLInterface_DEFINED

<<<<<<< HEAD
#include "GrGLExtensions.h"
#include "GrGLFunctions.h"
=======
#include "GrGLFunctions.h"
#include "GrGLExtensions.h"
>>>>>>> miniblink49
#include "SkRefCnt.h"

////////////////////////////////////////////////////////////////////////////////

/**
 * Rather than depend on platform-specific GL headers and libraries, we require
 * the client to provide a struct of GL function pointers. This struct can be
 * specified per-GrContext as a parameter to GrContext::Create. If NULL is
 * passed to Create then a "default" GL interface is created. If the default is
 * also NULL GrContext creation will fail.
 *
 * The default interface is returned by GrGLDefaultInterface. This function's
 * implementation is platform-specific. Several have been provided, along with
 * an implementation that simply returns NULL.
 *
 * By defining GR_GL_PER_GL_CALL_IFACE_CALLBACK to 1 the client can specify a
 * callback function that will be called prior to each GL function call. See
 * comments in GrGLConfig.h
 */

<<<<<<< HEAD
typedef void (*GrGLFuncPtr)();
=======
typedef void(*GrGLFuncPtr)();
>>>>>>> miniblink49

struct GrGLInterface;

const GrGLInterface* GrGLDefaultInterface();

/**
 * Creates a GrGLInterface for a "native" GL context (e.g. WGL on windows,
 * GLX on linux, AGL on Mac). The interface is only valid for the GL context
 * that is current when the interface is created.
 */
<<<<<<< HEAD
SK_API const GrGLInterface* GrGLCreateNativeInterface();
=======
const GrGLInterface* GrGLCreateNativeInterface();

#if SK_MESA
/**
 * Creates a GrGLInterface for an OSMesa context.
 */
const GrGLInterface* GrGLCreateMesaInterface();
#endif

#if SK_ANGLE
/**
 * Creates a GrGLInterface for an ANGLE context.
 */
const GrGLInterface* GrGLCreateANGLEInterface();
#endif

/**
 * Creates a null GrGLInterface that doesn't draw anything. Used for measuring
 * CPU overhead.
 */
const SK_API GrGLInterface* GrGLCreateNullInterface();

/**
 * Creates a debugging GrGLInterface that doesn't draw anything. Used for
 * finding memory leaks and invalid memory accesses.
 */
const GrGLInterface* GrGLCreateDebugInterface();
>>>>>>> miniblink49

#if GR_GL_PER_GL_FUNC_CALLBACK
typedef void (*GrGLInterfaceCallbackProc)(const GrGLInterface*);
typedef intptr_t GrGLInterfaceCallbackData;
#endif

<<<<<<< HEAD
/**
 * Creates a null GrGLInterface that doesn't draw anything. Used for measuring
 * CPU overhead. TODO: We would like to move this to tools/gpu/gl/null but currently
 * Chromium is using it in its unit tests.
 */
const SK_API GrGLInterface* GrGLCreateNullInterface(bool enableNVPR = false);

=======
>>>>>>> miniblink49
/** Function that returns a new interface identical to "interface" but without support for
    GL_NV_path_rendering. */
const GrGLInterface* GrGLInterfaceRemoveNVPR(const GrGLInterface*);

/** Function that returns a new interface identical to "interface" but with support for
    test version of GL_EXT_debug_marker. */
const GrGLInterface* GrGLInterfaceAddTestDebugMarker(const GrGLInterface*,
<<<<<<< HEAD
    GrGLInsertEventMarkerProc insertEventMarkerFn,
    GrGLPushGroupMarkerProc pushGroupMarkerFn,
    GrGLPopGroupMarkerProc popGroupMarkerFn);
=======
                                                     GrGLInsertEventMarkerProc insertEventMarkerFn,
                                                     GrGLPushGroupMarkerProc pushGroupMarkerFn,
                                                     GrGLPopGroupMarkerProc popGroupMarkerFn);
>>>>>>> miniblink49

/**
 * GrContext uses the following interface to make all calls into OpenGL. When a
 * GrContext is created it is given a GrGLInterface. The interface's function
 * pointers must be valid for the OpenGL context associated with the GrContext.
 * On some platforms, such as Windows, function pointers for OpenGL extensions
 * may vary between OpenGL contexts. So the caller must be careful to use a
 * GrGLInterface initialized for the correct context. All functions that should
 * be available based on the OpenGL's version and extension string must be
 * non-NULL or GrContext creation will fail. This can be tested with the
 * validate() method when the OpenGL context has been made current.
 */
struct SK_API GrGLInterface : public SkRefCnt {
private:
<<<<<<< HEAD
    typedef SkRefCnt INHERITED;

public:
=======
    // simple wrapper class that exists only to initialize a pointer to NULL
    template <typename FNPTR_TYPE> class GLPtr {
    public:
        GLPtr() : fPtr(NULL) {}
        GLPtr operator=(FNPTR_TYPE ptr) { fPtr = ptr; return *this; }
        operator FNPTR_TYPE() const { return fPtr; }
    private:
        FNPTR_TYPE fPtr;
    };

    // This is a temporary workaround to keep Chromium's GrGLInterface factories compiling until
    // they're updated to use the Functions struct.
    template <typename FNPTR_TYPE> class GLPtrAlias {
    public:
        GLPtrAlias(GLPtr<FNPTR_TYPE>* base) : fBase(base) {}
        void operator=(FNPTR_TYPE ptr) { *fBase = ptr; }
    private:
        GLPtr<FNPTR_TYPE>* fBase;
    };

    typedef SkRefCnt INHERITED;

public:
    

>>>>>>> miniblink49
    GrGLInterface();

    static GrGLInterface* NewClone(const GrGLInterface*);

    // Validates that the GrGLInterface supports its advertised standard. This means the necessary
    // function pointers have been initialized for both the GL version and any advertised
    // extensions.
    bool validate() const;

    // Indicates the type of GL implementation
    union {
        GrGLStandard fStandard;
        GrGLStandard fBindingsExported; // Legacy name, will be remove when Chromium is updated.
    };

    GrGLExtensions fExtensions;

    bool hasExtension(const char ext[]) const { return fExtensions.has(ext); }

    /**
     * The function pointers are in a struct so that we can have a compiler generated assignment
     * operator.
     */
    struct Functions {
<<<<<<< HEAD
        GrGLFunction<GrGLActiveTextureProc> fActiveTexture;
        GrGLFunction<GrGLAttachShaderProc> fAttachShader;
        GrGLFunction<GrGLBeginQueryProc> fBeginQuery;
        GrGLFunction<GrGLBindAttribLocationProc> fBindAttribLocation;
        GrGLFunction<GrGLBindBufferProc> fBindBuffer;
        GrGLFunction<GrGLBindFragDataLocationProc> fBindFragDataLocation;
        GrGLFunction<GrGLBindFragDataLocationIndexedProc> fBindFragDataLocationIndexed;
        GrGLFunction<GrGLBindFramebufferProc> fBindFramebuffer;
        GrGLFunction<GrGLBindRenderbufferProc> fBindRenderbuffer;
        GrGLFunction<GrGLBindTextureProc> fBindTexture;
        GrGLFunction<GrGLBindVertexArrayProc> fBindVertexArray;
        GrGLFunction<GrGLBlendBarrierProc> fBlendBarrier;
        GrGLFunction<GrGLBlendColorProc> fBlendColor;
        GrGLFunction<GrGLBlendEquationProc> fBlendEquation;
        GrGLFunction<GrGLBlendFuncProc> fBlendFunc;
        GrGLFunction<GrGLBlitFramebufferProc> fBlitFramebuffer;
        GrGLFunction<GrGLBufferDataProc> fBufferData;
        GrGLFunction<GrGLBufferSubDataProc> fBufferSubData;
        GrGLFunction<GrGLCheckFramebufferStatusProc> fCheckFramebufferStatus;
        GrGLFunction<GrGLClearProc> fClear;
        GrGLFunction<GrGLClearColorProc> fClearColor;
        GrGLFunction<GrGLClearStencilProc> fClearStencil;
        GrGLFunction<GrGLColorMaskProc> fColorMask;
        GrGLFunction<GrGLCompileShaderProc> fCompileShader;
        GrGLFunction<GrGLCompressedTexImage2DProc> fCompressedTexImage2D;
        GrGLFunction<GrGLCompressedTexSubImage2DProc> fCompressedTexSubImage2D;
        GrGLFunction<GrGLCopyTexSubImage2DProc> fCopyTexSubImage2D;
        GrGLFunction<GrGLCreateProgramProc> fCreateProgram;
        GrGLFunction<GrGLCreateShaderProc> fCreateShader;
        GrGLFunction<GrGLCullFaceProc> fCullFace;
        GrGLFunction<GrGLDeleteBuffersProc> fDeleteBuffers;
        GrGLFunction<GrGLDeleteFramebuffersProc> fDeleteFramebuffers;
        GrGLFunction<GrGLDeleteProgramProc> fDeleteProgram;
        GrGLFunction<GrGLDeleteQueriesProc> fDeleteQueries;
        GrGLFunction<GrGLDeleteRenderbuffersProc> fDeleteRenderbuffers;
        GrGLFunction<GrGLDeleteShaderProc> fDeleteShader;
        GrGLFunction<GrGLDeleteTexturesProc> fDeleteTextures;
        GrGLFunction<GrGLDeleteVertexArraysProc> fDeleteVertexArrays;
        GrGLFunction<GrGLDepthMaskProc> fDepthMask;
        GrGLFunction<GrGLDisableProc> fDisable;
        GrGLFunction<GrGLDisableVertexAttribArrayProc> fDisableVertexAttribArray;
        GrGLFunction<GrGLDrawArraysProc> fDrawArrays;
        GrGLFunction<GrGLDrawArraysIndirectProc> fDrawArraysIndirect;
        GrGLFunction<GrGLDrawArraysInstancedProc> fDrawArraysInstanced;
        GrGLFunction<GrGLDrawBufferProc> fDrawBuffer;
        GrGLFunction<GrGLDrawBuffersProc> fDrawBuffers;
        GrGLFunction<GrGLDrawElementsProc> fDrawElements;
        GrGLFunction<GrGLDrawElementsIndirectProc> fDrawElementsIndirect;
        GrGLFunction<GrGLDrawElementsInstancedProc> fDrawElementsInstanced;
        GrGLFunction<GrGLEnableProc> fEnable;
        GrGLFunction<GrGLEnableVertexAttribArrayProc> fEnableVertexAttribArray;
        GrGLFunction<GrGLEndQueryProc> fEndQuery;
        GrGLFunction<GrGLFinishProc> fFinish;
        GrGLFunction<GrGLFlushProc> fFlush;
        GrGLFunction<GrGLFlushMappedBufferRangeProc> fFlushMappedBufferRange;
        GrGLFunction<GrGLFramebufferRenderbufferProc> fFramebufferRenderbuffer;
        GrGLFunction<GrGLFramebufferTexture2DProc> fFramebufferTexture2D;
        GrGLFunction<GrGLFramebufferTexture2DMultisampleProc> fFramebufferTexture2DMultisample;
        GrGLFunction<GrGLFrontFaceProc> fFrontFace;
        GrGLFunction<GrGLGenBuffersProc> fGenBuffers;
        GrGLFunction<GrGLGenFramebuffersProc> fGenFramebuffers;
        GrGLFunction<GrGLGenerateMipmapProc> fGenerateMipmap;
        GrGLFunction<GrGLGenQueriesProc> fGenQueries;
        GrGLFunction<GrGLGenRenderbuffersProc> fGenRenderbuffers;
        GrGLFunction<GrGLGenTexturesProc> fGenTextures;
        GrGLFunction<GrGLGenVertexArraysProc> fGenVertexArrays;
        GrGLFunction<GrGLGetBufferParameterivProc> fGetBufferParameteriv;
        GrGLFunction<GrGLGetErrorProc> fGetError;
        GrGLFunction<GrGLGetFramebufferAttachmentParameterivProc> fGetFramebufferAttachmentParameteriv;
        GrGLFunction<GrGLGetIntegervProc> fGetIntegerv;
        GrGLFunction<GrGLGetMultisamplefvProc> fGetMultisamplefv;
        GrGLFunction<GrGLGetQueryObjecti64vProc> fGetQueryObjecti64v;
        GrGLFunction<GrGLGetQueryObjectivProc> fGetQueryObjectiv;
        GrGLFunction<GrGLGetQueryObjectui64vProc> fGetQueryObjectui64v;
        GrGLFunction<GrGLGetQueryObjectuivProc> fGetQueryObjectuiv;
        GrGLFunction<GrGLGetQueryivProc> fGetQueryiv;
        GrGLFunction<GrGLGetProgramInfoLogProc> fGetProgramInfoLog;
        GrGLFunction<GrGLGetProgramivProc> fGetProgramiv;
        GrGLFunction<GrGLGetRenderbufferParameterivProc> fGetRenderbufferParameteriv;
        GrGLFunction<GrGLGetShaderInfoLogProc> fGetShaderInfoLog;
        GrGLFunction<GrGLGetShaderivProc> fGetShaderiv;
        GrGLFunction<GrGLGetShaderPrecisionFormatProc> fGetShaderPrecisionFormat;
        GrGLFunction<GrGLGetStringProc> fGetString;
        GrGLFunction<GrGLGetStringiProc> fGetStringi;
        GrGLFunction<GrGLGetTexLevelParameterivProc> fGetTexLevelParameteriv;
        GrGLFunction<GrGLGetUniformLocationProc> fGetUniformLocation;
        GrGLFunction<GrGLInsertEventMarkerProc> fInsertEventMarker;
        GrGLFunction<GrGLInvalidateBufferDataProc> fInvalidateBufferData;
        GrGLFunction<GrGLInvalidateBufferSubDataProc> fInvalidateBufferSubData;
        GrGLFunction<GrGLInvalidateFramebufferProc> fInvalidateFramebuffer;
        GrGLFunction<GrGLInvalidateSubFramebufferProc> fInvalidateSubFramebuffer;
        GrGLFunction<GrGLInvalidateTexImageProc> fInvalidateTexImage;
        GrGLFunction<GrGLInvalidateTexSubImageProc> fInvalidateTexSubImage;
        GrGLFunction<GrGLIsTextureProc> fIsTexture;
        GrGLFunction<GrGLLineWidthProc> fLineWidth;
        GrGLFunction<GrGLLinkProgramProc> fLinkProgram;
        GrGLFunction<GrGLMapBufferProc> fMapBuffer;
        GrGLFunction<GrGLMapBufferRangeProc> fMapBufferRange;
        GrGLFunction<GrGLMapBufferSubDataProc> fMapBufferSubData;
        GrGLFunction<GrGLMapTexSubImage2DProc> fMapTexSubImage2D;
        GrGLFunction<GrGLMultiDrawArraysIndirectProc> fMultiDrawArraysIndirect;
        GrGLFunction<GrGLMultiDrawElementsIndirectProc> fMultiDrawElementsIndirect;
        GrGLFunction<GrGLPixelStoreiProc> fPixelStorei;
        GrGLFunction<GrGLPopGroupMarkerProc> fPopGroupMarker;
        GrGLFunction<GrGLPushGroupMarkerProc> fPushGroupMarker;
        GrGLFunction<GrGLQueryCounterProc> fQueryCounter;
        GrGLFunction<GrGLRasterSamplesProc> fRasterSamples;
        GrGLFunction<GrGLReadBufferProc> fReadBuffer;
        GrGLFunction<GrGLReadPixelsProc> fReadPixels;
        GrGLFunction<GrGLRenderbufferStorageProc> fRenderbufferStorage;
=======
        GLPtr<GrGLActiveTextureProc> fActiveTexture;
        GLPtr<GrGLAttachShaderProc> fAttachShader;
        GLPtr<GrGLBeginQueryProc> fBeginQuery;
        GLPtr<GrGLBindAttribLocationProc> fBindAttribLocation;
        GLPtr<GrGLBindBufferProc> fBindBuffer;
        GLPtr<GrGLBindFragDataLocationProc> fBindFragDataLocation;
        GLPtr<GrGLBindFragDataLocationIndexedProc> fBindFragDataLocationIndexed;
        GLPtr<GrGLBindFramebufferProc> fBindFramebuffer;
        GLPtr<GrGLBindRenderbufferProc> fBindRenderbuffer;
        GLPtr<GrGLBindTextureProc> fBindTexture;
        GLPtr<GrGLBindVertexArrayProc> fBindVertexArray;
        GLPtr<GrGLBlendBarrierProc> fBlendBarrier;
        GLPtr<GrGLBlendColorProc> fBlendColor;
        GLPtr<GrGLBlendEquationProc> fBlendEquation;
        GLPtr<GrGLBlendFuncProc> fBlendFunc;
        GLPtr<GrGLBlitFramebufferProc> fBlitFramebuffer;
        GLPtr<GrGLBufferDataProc> fBufferData;
        GLPtr<GrGLBufferSubDataProc> fBufferSubData;
        GLPtr<GrGLCheckFramebufferStatusProc> fCheckFramebufferStatus;
        GLPtr<GrGLClearProc> fClear;
        GLPtr<GrGLClearColorProc> fClearColor;
        GLPtr<GrGLClearStencilProc> fClearStencil;
        GLPtr<GrGLColorMaskProc> fColorMask;
        GLPtr<GrGLCompileShaderProc> fCompileShader;
        GLPtr<GrGLCompressedTexImage2DProc> fCompressedTexImage2D;
        GLPtr<GrGLCompressedTexSubImage2DProc> fCompressedTexSubImage2D;
        GLPtr<GrGLCopyTexSubImage2DProc> fCopyTexSubImage2D;
        GLPtr<GrGLCopyTextureCHROMIUMProc> fCopyTextureCHROMIUM;
        GLPtr<GrGLCreateProgramProc> fCreateProgram;
        GLPtr<GrGLCreateShaderProc> fCreateShader;
        GLPtr<GrGLCullFaceProc> fCullFace;
        GLPtr<GrGLDeleteBuffersProc> fDeleteBuffers;
        GLPtr<GrGLDeleteFramebuffersProc> fDeleteFramebuffers;
        GLPtr<GrGLDeleteProgramProc> fDeleteProgram;
        GLPtr<GrGLDeleteQueriesProc> fDeleteQueries;
        GLPtr<GrGLDeleteRenderbuffersProc> fDeleteRenderbuffers;
        GLPtr<GrGLDeleteShaderProc> fDeleteShader;
        GLPtr<GrGLDeleteTexturesProc> fDeleteTextures;
        GLPtr<GrGLDeleteVertexArraysProc> fDeleteVertexArrays;
        GLPtr<GrGLDepthMaskProc> fDepthMask;
        GLPtr<GrGLDisableProc> fDisable;
        GLPtr<GrGLDisableVertexAttribArrayProc> fDisableVertexAttribArray;
        GLPtr<GrGLDrawArraysProc> fDrawArrays;
        GLPtr<GrGLDrawBufferProc> fDrawBuffer;
        GLPtr<GrGLDrawBuffersProc> fDrawBuffers;
        GLPtr<GrGLDrawElementsProc> fDrawElements;
        GLPtr<GrGLEnableProc> fEnable;
        GLPtr<GrGLEnableVertexAttribArrayProc> fEnableVertexAttribArray;
        GLPtr<GrGLEndQueryProc> fEndQuery;
        GLPtr<GrGLFinishProc> fFinish;
        GLPtr<GrGLFlushProc> fFlush;
        GLPtr<GrGLFlushMappedBufferRangeProc> fFlushMappedBufferRange;
        GLPtr<GrGLFramebufferRenderbufferProc> fFramebufferRenderbuffer;
        GLPtr<GrGLFramebufferTexture2DProc> fFramebufferTexture2D;
        GLPtr<GrGLFramebufferTexture2DMultisampleProc> fFramebufferTexture2DMultisample;
        GLPtr<GrGLFrontFaceProc> fFrontFace;
        GLPtr<GrGLGenBuffersProc> fGenBuffers;
        GLPtr<GrGLGenFramebuffersProc> fGenFramebuffers;
        GLPtr<GrGLGenerateMipmapProc> fGenerateMipmap;
        GLPtr<GrGLGenQueriesProc> fGenQueries;
        GLPtr<GrGLGenRenderbuffersProc> fGenRenderbuffers;
        GLPtr<GrGLGenTexturesProc> fGenTextures;
        GLPtr<GrGLGenVertexArraysProc> fGenVertexArrays;
        GLPtr<GrGLGetBufferParameterivProc> fGetBufferParameteriv;
        GLPtr<GrGLGetErrorProc> fGetError;
        GLPtr<GrGLGetFramebufferAttachmentParameterivProc> fGetFramebufferAttachmentParameteriv;
        GLPtr<GrGLGetIntegervProc> fGetIntegerv;
        GLPtr<GrGLGetQueryObjecti64vProc> fGetQueryObjecti64v;
        GLPtr<GrGLGetQueryObjectivProc> fGetQueryObjectiv;
        GLPtr<GrGLGetQueryObjectui64vProc> fGetQueryObjectui64v;
        GLPtr<GrGLGetQueryObjectuivProc> fGetQueryObjectuiv;
        GLPtr<GrGLGetQueryivProc> fGetQueryiv;
        GLPtr<GrGLGetProgramInfoLogProc> fGetProgramInfoLog;
        GLPtr<GrGLGetProgramivProc> fGetProgramiv;
        GLPtr<GrGLGetRenderbufferParameterivProc> fGetRenderbufferParameteriv;
        GLPtr<GrGLGetShaderInfoLogProc> fGetShaderInfoLog;
        GLPtr<GrGLGetShaderivProc> fGetShaderiv;
        GLPtr<GrGLGetShaderPrecisionFormatProc> fGetShaderPrecisionFormat;
        GLPtr<GrGLGetStringProc> fGetString;
        GLPtr<GrGLGetStringiProc> fGetStringi;
        GLPtr<GrGLGetTexLevelParameterivProc> fGetTexLevelParameteriv;
        GLPtr<GrGLGetUniformLocationProc> fGetUniformLocation;
        GLPtr<GrGLInsertEventMarkerProc> fInsertEventMarker;
        GLPtr<GrGLInvalidateBufferDataProc> fInvalidateBufferData;
        GLPtr<GrGLInvalidateBufferSubDataProc> fInvalidateBufferSubData;
        GLPtr<GrGLInvalidateFramebufferProc> fInvalidateFramebuffer;
        GLPtr<GrGLInvalidateSubFramebufferProc> fInvalidateSubFramebuffer;
        GLPtr<GrGLInvalidateTexImageProc> fInvalidateTexImage;
        GLPtr<GrGLInvalidateTexSubImageProc> fInvalidateTexSubImage;
        GLPtr<GrGLIsTextureProc> fIsTexture;
        GLPtr<GrGLLineWidthProc> fLineWidth;
        GLPtr<GrGLLinkProgramProc> fLinkProgram;
        GLPtr<GrGLMapBufferProc> fMapBuffer;
        GLPtr<GrGLMapBufferRangeProc> fMapBufferRange;
        GLPtr<GrGLMapBufferSubDataProc> fMapBufferSubData;
        GLPtr<GrGLMapTexSubImage2DProc> fMapTexSubImage2D;
        GLPtr<GrGLPixelStoreiProc> fPixelStorei;
        GLPtr<GrGLPopGroupMarkerProc> fPopGroupMarker;
        GLPtr<GrGLPushGroupMarkerProc> fPushGroupMarker;
        GLPtr<GrGLQueryCounterProc> fQueryCounter;
        GLPtr<GrGLRasterSamplesProc> fRasterSamples;
        GLPtr<GrGLReadBufferProc> fReadBuffer;
        GLPtr<GrGLReadPixelsProc> fReadPixels;
        GLPtr<GrGLRenderbufferStorageProc> fRenderbufferStorage;
>>>>>>> miniblink49

        //  On OpenGL ES there are multiple incompatible extensions that add support for MSAA
        //  and ES3 adds MSAA support to the standard. On an ES3 driver we may still use the
        //  older extensions for performance reasons or due to ES3 driver bugs. We want the function
        //  that creates the GrGLInterface to provide all available functions and internally
        //  we will select among them. They all have a method called glRenderbufferStorageMultisample*.
        //  So we have separate function pointers for GL_IMG/EXT_multisampled_to_texture,
        //  GL_CHROMIUM/ANGLE_framebuffer_multisample/ES3, and GL_APPLE_framebuffer_multisample
        //  variations.
        //
        //  If a driver supports multiple GL_ARB_framebuffer_multisample-style extensions then we will
        //  assume the function pointers for the standard (or equivalent GL_ARB) version have
        //  been preferred over GL_EXT, GL_CHROMIUM, or GL_ANGLE variations that have reduced
        //  functionality.

        //  GL_EXT_multisampled_render_to_texture (preferred) or GL_IMG_multisampled_render_to_texture
<<<<<<< HEAD
        GrGLFunction<GrGLRenderbufferStorageMultisampleProc> fRenderbufferStorageMultisampleES2EXT;
        //  GL_APPLE_framebuffer_multisample
        GrGLFunction<GrGLRenderbufferStorageMultisampleProc> fRenderbufferStorageMultisampleES2APPLE;

        //  This is used to store the pointer for GL_ARB/EXT/ANGLE/CHROMIUM_framebuffer_multisample or
        //  the standard function in ES3+ or GL 3.0+.
        GrGLFunction<GrGLRenderbufferStorageMultisampleProc> fRenderbufferStorageMultisample;

        // Pointer to BindUniformLocationCHROMIUM from the GL_CHROMIUM_bind_uniform_location extension.
        GrGLFunction<GrGLBindUniformLocationProc> fBindUniformLocation;

        GrGLFunction<GrGLResolveMultisampleFramebufferProc> fResolveMultisampleFramebuffer;
        GrGLFunction<GrGLScissorProc> fScissor;
        GrGLFunction<GrGLShaderSourceProc> fShaderSource;
        GrGLFunction<GrGLStencilFuncProc> fStencilFunc;
        GrGLFunction<GrGLStencilFuncSeparateProc> fStencilFuncSeparate;
        GrGLFunction<GrGLStencilMaskProc> fStencilMask;
        GrGLFunction<GrGLStencilMaskSeparateProc> fStencilMaskSeparate;
        GrGLFunction<GrGLStencilOpProc> fStencilOp;
        GrGLFunction<GrGLStencilOpSeparateProc> fStencilOpSeparate;
        GrGLFunction<GrGLTexBufferProc> fTexBuffer;
        GrGLFunction<GrGLTexBufferRangeProc> fTexBufferRange;
        GrGLFunction<GrGLTexImage2DProc> fTexImage2D;
        GrGLFunction<GrGLTexParameteriProc> fTexParameteri;
        GrGLFunction<GrGLTexParameterivProc> fTexParameteriv;
        GrGLFunction<GrGLTexSubImage2DProc> fTexSubImage2D;
        GrGLFunction<GrGLTexStorage2DProc> fTexStorage2D;
        GrGLFunction<GrGLTextureBarrierProc> fTextureBarrier;
        GrGLFunction<GrGLDiscardFramebufferProc> fDiscardFramebuffer;
        GrGLFunction<GrGLUniform1fProc> fUniform1f;
        GrGLFunction<GrGLUniform1iProc> fUniform1i;
        GrGLFunction<GrGLUniform1fvProc> fUniform1fv;
        GrGLFunction<GrGLUniform1ivProc> fUniform1iv;
        GrGLFunction<GrGLUniform2fProc> fUniform2f;
        GrGLFunction<GrGLUniform2iProc> fUniform2i;
        GrGLFunction<GrGLUniform2fvProc> fUniform2fv;
        GrGLFunction<GrGLUniform2ivProc> fUniform2iv;
        GrGLFunction<GrGLUniform3fProc> fUniform3f;
        GrGLFunction<GrGLUniform3iProc> fUniform3i;
        GrGLFunction<GrGLUniform3fvProc> fUniform3fv;
        GrGLFunction<GrGLUniform3ivProc> fUniform3iv;
        GrGLFunction<GrGLUniform4fProc> fUniform4f;
        GrGLFunction<GrGLUniform4iProc> fUniform4i;
        GrGLFunction<GrGLUniform4fvProc> fUniform4fv;
        GrGLFunction<GrGLUniform4ivProc> fUniform4iv;
        GrGLFunction<GrGLUniformMatrix2fvProc> fUniformMatrix2fv;
        GrGLFunction<GrGLUniformMatrix3fvProc> fUniformMatrix3fv;
        GrGLFunction<GrGLUniformMatrix4fvProc> fUniformMatrix4fv;
        GrGLFunction<GrGLUnmapBufferProc> fUnmapBuffer;
        GrGLFunction<GrGLUnmapBufferSubDataProc> fUnmapBufferSubData;
        GrGLFunction<GrGLUnmapTexSubImage2DProc> fUnmapTexSubImage2D;
        GrGLFunction<GrGLUseProgramProc> fUseProgram;
        GrGLFunction<GrGLVertexAttrib1fProc> fVertexAttrib1f;
        GrGLFunction<GrGLVertexAttrib2fvProc> fVertexAttrib2fv;
        GrGLFunction<GrGLVertexAttrib3fvProc> fVertexAttrib3fv;
        GrGLFunction<GrGLVertexAttrib4fvProc> fVertexAttrib4fv;
        GrGLFunction<GrGLVertexAttribDivisorProc> fVertexAttribDivisor;
        GrGLFunction<GrGLVertexAttribIPointerProc> fVertexAttribIPointer;
        GrGLFunction<GrGLVertexAttribPointerProc> fVertexAttribPointer;
        GrGLFunction<GrGLViewportProc> fViewport;

        /* GL_NV_path_rendering */
        GrGLFunction<GrGLMatrixLoadfProc> fMatrixLoadf;
        GrGLFunction<GrGLMatrixLoadIdentityProc> fMatrixLoadIdentity;
        GrGLFunction<GrGLGetProgramResourceLocationProc> fGetProgramResourceLocation;
        GrGLFunction<GrGLPathCommandsProc> fPathCommands;
        GrGLFunction<GrGLPathParameteriProc> fPathParameteri;
        GrGLFunction<GrGLPathParameterfProc> fPathParameterf;
        GrGLFunction<GrGLGenPathsProc> fGenPaths;
        GrGLFunction<GrGLDeletePathsProc> fDeletePaths;
        GrGLFunction<GrGLIsPathProc> fIsPath;
        GrGLFunction<GrGLPathStencilFuncProc> fPathStencilFunc;
        GrGLFunction<GrGLStencilFillPathProc> fStencilFillPath;
        GrGLFunction<GrGLStencilStrokePathProc> fStencilStrokePath;
        GrGLFunction<GrGLStencilFillPathInstancedProc> fStencilFillPathInstanced;
        GrGLFunction<GrGLStencilStrokePathInstancedProc> fStencilStrokePathInstanced;
        GrGLFunction<GrGLCoverFillPathProc> fCoverFillPath;
        GrGLFunction<GrGLCoverStrokePathProc> fCoverStrokePath;
        GrGLFunction<GrGLCoverFillPathInstancedProc> fCoverFillPathInstanced;
        GrGLFunction<GrGLCoverStrokePathInstancedProc> fCoverStrokePathInstanced;
        // NV_path_rendering v1.2
        GrGLFunction<GrGLStencilThenCoverFillPathProc> fStencilThenCoverFillPath;
        GrGLFunction<GrGLStencilThenCoverStrokePathProc> fStencilThenCoverStrokePath;
        GrGLFunction<GrGLStencilThenCoverFillPathInstancedProc> fStencilThenCoverFillPathInstanced;
        GrGLFunction<GrGLStencilThenCoverStrokePathInstancedProc> fStencilThenCoverStrokePathInstanced;
        // NV_path_rendering v1.3
        GrGLFunction<GrGLProgramPathFragmentInputGenProc> fProgramPathFragmentInputGen;
        // CHROMIUM_path_rendering
        GrGLFunction<GrGLBindFragmentInputLocationProc> fBindFragmentInputLocation;

        /* NV_framebuffer_mixed_samples */
        GrGLFunction<GrGLCoverageModulationProc> fCoverageModulation;
=======
        GLPtr<GrGLRenderbufferStorageMultisampleProc> fRenderbufferStorageMultisampleES2EXT;
        //  GL_APPLE_framebuffer_multisample
        GLPtr<GrGLRenderbufferStorageMultisampleProc> fRenderbufferStorageMultisampleES2APPLE;

        //  This is used to store the pointer for GL_ARB/EXT/ANGLE/CHROMIUM_framebuffer_multisample or
        //  the standard function in ES3+ or GL 3.0+.
        GLPtr<GrGLRenderbufferStorageMultisampleProc> fRenderbufferStorageMultisample;

        // Pointer to BindUniformLocationCHROMIUM from the GL_CHROMIUM_bind_uniform_location extension.
        GLPtr<GrGLBindUniformLocation> fBindUniformLocation;

        GLPtr<GrGLResolveMultisampleFramebufferProc> fResolveMultisampleFramebuffer;
        GLPtr<GrGLScissorProc> fScissor;
        GLPtr<GrGLShaderSourceProc> fShaderSource;
        GLPtr<GrGLStencilFuncProc> fStencilFunc;
        GLPtr<GrGLStencilFuncSeparateProc> fStencilFuncSeparate;
        GLPtr<GrGLStencilMaskProc> fStencilMask;
        GLPtr<GrGLStencilMaskSeparateProc> fStencilMaskSeparate;
        GLPtr<GrGLStencilOpProc> fStencilOp;
        GLPtr<GrGLStencilOpSeparateProc> fStencilOpSeparate;
        GLPtr<GrGLTexImage2DProc> fTexImage2D;
        GLPtr<GrGLTexParameteriProc> fTexParameteri;
        GLPtr<GrGLTexParameterivProc> fTexParameteriv;
        GLPtr<GrGLTexSubImage2DProc> fTexSubImage2D;
        GLPtr<GrGLTexStorage2DProc> fTexStorage2D;
        GLPtr<GrGLTextureBarrierProc> fTextureBarrier;
        GLPtr<GrGLDiscardFramebufferProc> fDiscardFramebuffer;
        GLPtr<GrGLUniform1fProc> fUniform1f;
        GLPtr<GrGLUniform1iProc> fUniform1i;
        GLPtr<GrGLUniform1fvProc> fUniform1fv;
        GLPtr<GrGLUniform1ivProc> fUniform1iv;
        GLPtr<GrGLUniform2fProc> fUniform2f;
        GLPtr<GrGLUniform2iProc> fUniform2i;
        GLPtr<GrGLUniform2fvProc> fUniform2fv;
        GLPtr<GrGLUniform2ivProc> fUniform2iv;
        GLPtr<GrGLUniform3fProc> fUniform3f;
        GLPtr<GrGLUniform3iProc> fUniform3i;
        GLPtr<GrGLUniform3fvProc> fUniform3fv;
        GLPtr<GrGLUniform3ivProc> fUniform3iv;
        GLPtr<GrGLUniform4fProc> fUniform4f;
        GLPtr<GrGLUniform4iProc> fUniform4i;
        GLPtr<GrGLUniform4fvProc> fUniform4fv;
        GLPtr<GrGLUniform4ivProc> fUniform4iv;
        GLPtr<GrGLUniformMatrix2fvProc> fUniformMatrix2fv;
        GLPtr<GrGLUniformMatrix3fvProc> fUniformMatrix3fv;
        GLPtr<GrGLUniformMatrix4fvProc> fUniformMatrix4fv;
        GLPtr<GrGLUnmapBufferProc> fUnmapBuffer;
        GLPtr<GrGLUnmapBufferSubDataProc> fUnmapBufferSubData;
        GLPtr<GrGLUnmapTexSubImage2DProc> fUnmapTexSubImage2D;
        GLPtr<GrGLUseProgramProc> fUseProgram;
        GLPtr<GrGLVertexAttrib1fProc> fVertexAttrib1f;
        GLPtr<GrGLVertexAttrib2fvProc> fVertexAttrib2fv;
        GLPtr<GrGLVertexAttrib3fvProc> fVertexAttrib3fv;
        GLPtr<GrGLVertexAttrib4fvProc> fVertexAttrib4fv;
        GLPtr<GrGLVertexAttribPointerProc> fVertexAttribPointer;
        GLPtr<GrGLViewportProc> fViewport;

        /* GL_NV_path_rendering */
        GLPtr<GrGLMatrixLoadfProc> fMatrixLoadf;
        GLPtr<GrGLMatrixLoadIdentityProc> fMatrixLoadIdentity;
        GLPtr<GrGLGetProgramResourceLocationProc> fGetProgramResourceLocation;
        GLPtr<GrGLPathCommandsProc> fPathCommands;
        GLPtr<GrGLPathParameteriProc> fPathParameteri;
        GLPtr<GrGLPathParameterfProc> fPathParameterf;
        GLPtr<GrGLGenPathsProc> fGenPaths;
        GLPtr<GrGLDeletePathsProc> fDeletePaths;
        GLPtr<GrGLIsPathProc> fIsPath;
        GLPtr<GrGLPathStencilFuncProc> fPathStencilFunc;
        GLPtr<GrGLStencilFillPathProc> fStencilFillPath;
        GLPtr<GrGLStencilStrokePathProc> fStencilStrokePath;
        GLPtr<GrGLStencilFillPathInstancedProc> fStencilFillPathInstanced;
        GLPtr<GrGLStencilStrokePathInstancedProc> fStencilStrokePathInstanced;
        GLPtr<GrGLCoverFillPathProc> fCoverFillPath;
        GLPtr<GrGLCoverStrokePathProc> fCoverStrokePath;
        GLPtr<GrGLCoverFillPathInstancedProc> fCoverFillPathInstanced;
        GLPtr<GrGLCoverStrokePathInstancedProc> fCoverStrokePathInstanced;
        // NV_path_rendering v1.2
        GLPtr<GrGLStencilThenCoverFillPathProc> fStencilThenCoverFillPath;
        GLPtr<GrGLStencilThenCoverStrokePathProc> fStencilThenCoverStrokePath;
        GLPtr<GrGLStencilThenCoverFillPathInstancedProc> fStencilThenCoverFillPathInstanced;
        GLPtr<GrGLStencilThenCoverStrokePathInstancedProc> fStencilThenCoverStrokePathInstanced;
        // NV_path_rendering v1.3
        GLPtr<GrGLProgramPathFragmentInputGenProc> fProgramPathFragmentInputGen;

        /* NV_framebuffer_mixed_samples */
        GLPtr<GrGLCoverageModulationProc> fCoverageModulation;

        /* ARB_draw_instanced */
        GLPtr<GrGLDrawArraysInstancedProc> fDrawArraysInstanced;
        GLPtr<GrGLDrawElementsInstancedProc> fDrawElementsInstanced;

        /* ARB_instanced_arrays */
        GLPtr<GrGLVertexAttribDivisorProc> fVertexAttribDivisor;
>>>>>>> miniblink49

        /* NV_bindless_texture */
        // We use the NVIDIA verson for now because it does not require dynamically uniform handles.
        // We may switch the the ARB version and/or omit methods in the future.
<<<<<<< HEAD
        GrGLFunction<GrGLGetTextureHandleProc> fGetTextureHandle;
        GrGLFunction<GrGLGetTextureSamplerHandleProc> fGetTextureSamplerHandle;
        GrGLFunction<GrGLMakeTextureHandleResidentProc> fMakeTextureHandleResident;
        GrGLFunction<GrGLMakeTextureHandleNonResidentProc> fMakeTextureHandleNonResident;
        GrGLFunction<GrGLGetImageHandleProc> fGetImageHandle;
        GrGLFunction<GrGLMakeImageHandleResidentProc> fMakeImageHandleResident;
        GrGLFunction<GrGLMakeImageHandleNonResidentProc> fMakeImageHandleNonResident;
        GrGLFunction<GrGLIsTextureHandleResidentProc> fIsTextureHandleResident;
        GrGLFunction<GrGLIsImageHandleResidentProc> fIsImageHandleResident;
        GrGLFunction<GrGLUniformHandleui64Proc> fUniformHandleui64;
        GrGLFunction<GrGLUniformHandleui64vProc> fUniformHandleui64v;
        GrGLFunction<GrGLProgramUniformHandleui64Proc> fProgramUniformHandleui64;
        GrGLFunction<GrGLProgramUniformHandleui64vProc> fProgramUniformHandleui64v;

        /* ARB_sample_shading */
        GrGLFunction<GrGLMinSampleShadingProc> fMinSampleShading;
=======
        GLPtr<GrGLGetTextureHandleProc> fGetTextureHandle;
        GLPtr<GrGLGetTextureSamplerHandleProc> fGetTextureSamplerHandle;
        GLPtr<GrGLMakeTextureHandleResidentProc> fMakeTextureHandleResident;
        GLPtr<GrGLMakeTextureHandleNonResidentProc> fMakeTextureHandleNonResident;
        GLPtr<GrGLGetImageHandleProc> fGetImageHandle;
        GLPtr<GrGLMakeImageHandleResidentProc> fMakeImageHandleResident;
        GLPtr<GrGLMakeImageHandleNonResidentProc> fMakeImageHandleNonResident;
        GLPtr<GrGLIsTextureHandleResidentProc> fIsTextureHandleResident;
        GLPtr<GrGLIsImageHandleResidentProc> fIsImageHandleResident;
        GLPtr<GrGLUniformHandleui64Proc> fUniformHandleui64;
        GLPtr<GrGLUniformHandleui64vProc> fUniformHandleui64v;
        GLPtr<GrGLProgramUniformHandleui64Proc> fProgramUniformHandleui64;
        GLPtr<GrGLProgramUniformHandleui64vProc> fProgramUniformHandleui64v;
>>>>>>> miniblink49

        /* EXT_direct_state_access */
        // We use the EXT verson because it is more expansive and interacts with more extensions
        // than the ARB or core (4.5) versions. We may switch and/or omit methods in the future.
<<<<<<< HEAD
        GrGLFunction<GrGLTextureParameteriProc> fTextureParameteri;
        GrGLFunction<GrGLTextureParameterivProc> fTextureParameteriv;
        GrGLFunction<GrGLTextureParameterfProc> fTextureParameterf;
        GrGLFunction<GrGLTextureParameterfvProc> fTextureParameterfv;
        GrGLFunction<GrGLTextureImage1DProc> fTextureImage1D;
        GrGLFunction<GrGLTextureImage2DProc> fTextureImage2D;
        GrGLFunction<GrGLTextureSubImage1DProc> fTextureSubImage1D;
        GrGLFunction<GrGLTextureSubImage2DProc> fTextureSubImage2D;
        GrGLFunction<GrGLCopyTextureImage1DProc> fCopyTextureImage1D;
        GrGLFunction<GrGLCopyTextureImage2DProc> fCopyTextureImage2D;
        GrGLFunction<GrGLCopyTextureSubImage1DProc> fCopyTextureSubImage1D;
        GrGLFunction<GrGLCopyTextureSubImage2DProc> fCopyTextureSubImage2D;
        GrGLFunction<GrGLGetTextureImageProc> fGetTextureImage;
        GrGLFunction<GrGLGetTextureParameterfvProc> fGetTextureParameterfv;
        GrGLFunction<GrGLGetTextureParameterivProc> fGetTextureParameteriv;
        GrGLFunction<GrGLGetTextureLevelParameterfvProc> fGetTextureLevelParameterfv;
        GrGLFunction<GrGLGetTextureLevelParameterivProc> fGetTextureLevelParameteriv;
        // OpenGL 1.2
        GrGLFunction<GrGLTextureImage3DProc> fTextureImage3D;
        GrGLFunction<GrGLTextureSubImage3DProc> fTextureSubImage3D;
        GrGLFunction<GrGLCopyTextureSubImage3DProc> fCopyTextureSubImage3D;
        GrGLFunction<GrGLCompressedTextureImage3DProc> fCompressedTextureImage3D;
        GrGLFunction<GrGLCompressedTextureImage2DProc> fCompressedTextureImage2D;
        GrGLFunction<GrGLCompressedTextureImage1DProc> fCompressedTextureImage1D;
        GrGLFunction<GrGLCompressedTextureSubImage3DProc> fCompressedTextureSubImage3D;
        GrGLFunction<GrGLCompressedTextureSubImage2DProc> fCompressedTextureSubImage2D;
        GrGLFunction<GrGLCompressedTextureSubImage1DProc> fCompressedTextureSubImage1D;
        GrGLFunction<GrGLGetCompressedTextureImageProc> fGetCompressedTextureImage;
        // OpenGL 1.5
        GrGLFunction<GrGLNamedBufferDataProc> fNamedBufferData;
        GrGLFunction<GrGLNamedBufferSubDataProc> fNamedBufferSubData;
        GrGLFunction<GrGLMapNamedBufferProc> fMapNamedBuffer;
        GrGLFunction<GrGLUnmapNamedBufferProc> fUnmapNamedBuffer;
        GrGLFunction<GrGLGetNamedBufferParameterivProc> fGetNamedBufferParameteriv;
        GrGLFunction<GrGLGetNamedBufferPointervProc> fGetNamedBufferPointerv;
        GrGLFunction<GrGLGetNamedBufferSubDataProc> fGetNamedBufferSubData;
        // OpenGL 2.0
        GrGLFunction<GrGLProgramUniform1fProc> fProgramUniform1f;
        GrGLFunction<GrGLProgramUniform2fProc> fProgramUniform2f;
        GrGLFunction<GrGLProgramUniform3fProc> fProgramUniform3f;
        GrGLFunction<GrGLProgramUniform4fProc> fProgramUniform4f;
        GrGLFunction<GrGLProgramUniform1iProc> fProgramUniform1i;
        GrGLFunction<GrGLProgramUniform2iProc> fProgramUniform2i;
        GrGLFunction<GrGLProgramUniform3iProc> fProgramUniform3i;
        GrGLFunction<GrGLProgramUniform4iProc> fProgramUniform4i;
        GrGLFunction<GrGLProgramUniform1fvProc> fProgramUniform1fv;
        GrGLFunction<GrGLProgramUniform2fvProc> fProgramUniform2fv;
        GrGLFunction<GrGLProgramUniform3fvProc> fProgramUniform3fv;
        GrGLFunction<GrGLProgramUniform4fvProc> fProgramUniform4fv;
        GrGLFunction<GrGLProgramUniform1ivProc> fProgramUniform1iv;
        GrGLFunction<GrGLProgramUniform2ivProc> fProgramUniform2iv;
        GrGLFunction<GrGLProgramUniform3ivProc> fProgramUniform3iv;
        GrGLFunction<GrGLProgramUniform4ivProc> fProgramUniform4iv;
        GrGLFunction<GrGLProgramUniformMatrix2fvProc> fProgramUniformMatrix2fv;
        GrGLFunction<GrGLProgramUniformMatrix3fvProc> fProgramUniformMatrix3fv;
        GrGLFunction<GrGLProgramUniformMatrix4fvProc> fProgramUniformMatrix4fv;
        // OpenGL 2.1
        GrGLFunction<GrGLProgramUniformMatrix2x3fvProc> fProgramUniformMatrix2x3fv;
        GrGLFunction<GrGLProgramUniformMatrix3x2fvProc> fProgramUniformMatrix3x2fv;
        GrGLFunction<GrGLProgramUniformMatrix2x4fvProc> fProgramUniformMatrix2x4fv;
        GrGLFunction<GrGLProgramUniformMatrix4x2fvProc> fProgramUniformMatrix4x2fv;
        GrGLFunction<GrGLProgramUniformMatrix3x4fvProc> fProgramUniformMatrix3x4fv;
        GrGLFunction<GrGLProgramUniformMatrix4x3fvProc> fProgramUniformMatrix4x3fv;
        // OpenGL 3.0
        GrGLFunction<GrGLNamedRenderbufferStorageProc> fNamedRenderbufferStorage;
        GrGLFunction<GrGLGetNamedRenderbufferParameterivProc> fGetNamedRenderbufferParameteriv;
        GrGLFunction<GrGLNamedRenderbufferStorageMultisampleProc> fNamedRenderbufferStorageMultisample;
        GrGLFunction<GrGLCheckNamedFramebufferStatusProc> fCheckNamedFramebufferStatus;
        GrGLFunction<GrGLNamedFramebufferTexture1DProc> fNamedFramebufferTexture1D;
        GrGLFunction<GrGLNamedFramebufferTexture2DProc> fNamedFramebufferTexture2D;
        GrGLFunction<GrGLNamedFramebufferTexture3DProc> fNamedFramebufferTexture3D;
        GrGLFunction<GrGLNamedFramebufferRenderbufferProc> fNamedFramebufferRenderbuffer;
        GrGLFunction<GrGLGetNamedFramebufferAttachmentParameterivProc> fGetNamedFramebufferAttachmentParameteriv;
        GrGLFunction<GrGLGenerateTextureMipmapProc> fGenerateTextureMipmap;
        GrGLFunction<GrGLFramebufferDrawBufferProc> fFramebufferDrawBuffer;
        GrGLFunction<GrGLFramebufferDrawBuffersProc> fFramebufferDrawBuffers;
        GrGLFunction<GrGLFramebufferReadBufferProc> fFramebufferReadBuffer;
        GrGLFunction<GrGLGetFramebufferParameterivProc> fGetFramebufferParameteriv;
        GrGLFunction<GrGLNamedCopyBufferSubDataProc> fNamedCopyBufferSubData;
        GrGLFunction<GrGLVertexArrayVertexOffsetProc> fVertexArrayVertexOffset;
        GrGLFunction<GrGLVertexArrayColorOffsetProc> fVertexArrayColorOffset;
        GrGLFunction<GrGLVertexArrayEdgeFlagOffsetProc> fVertexArrayEdgeFlagOffset;
        GrGLFunction<GrGLVertexArrayIndexOffsetProc> fVertexArrayIndexOffset;
        GrGLFunction<GrGLVertexArrayNormalOffsetProc> fVertexArrayNormalOffset;
        GrGLFunction<GrGLVertexArrayTexCoordOffsetProc> fVertexArrayTexCoordOffset;
        GrGLFunction<GrGLVertexArrayMultiTexCoordOffsetProc> fVertexArrayMultiTexCoordOffset;
        GrGLFunction<GrGLVertexArrayFogCoordOffsetProc> fVertexArrayFogCoordOffset;
        GrGLFunction<GrGLVertexArraySecondaryColorOffsetProc> fVertexArraySecondaryColorOffset;
        GrGLFunction<GrGLVertexArrayVertexAttribOffsetProc> fVertexArrayVertexAttribOffset;
        GrGLFunction<GrGLVertexArrayVertexAttribIOffsetProc> fVertexArrayVertexAttribIOffset;
        GrGLFunction<GrGLEnableVertexArrayProc> fEnableVertexArray;
        GrGLFunction<GrGLDisableVertexArrayProc> fDisableVertexArray;
        GrGLFunction<GrGLEnableVertexArrayAttribProc> fEnableVertexArrayAttrib;
        GrGLFunction<GrGLDisableVertexArrayAttribProc> fDisableVertexArrayAttrib;
        GrGLFunction<GrGLGetVertexArrayIntegervProc> fGetVertexArrayIntegerv;
        GrGLFunction<GrGLGetVertexArrayPointervProc> fGetVertexArrayPointerv;
        GrGLFunction<GrGLGetVertexArrayIntegeri_vProc> fGetVertexArrayIntegeri_v;
        GrGLFunction<GrGLGetVertexArrayPointeri_vProc> fGetVertexArrayPointeri_v;
        GrGLFunction<GrGLMapNamedBufferRangeProc> fMapNamedBufferRange;
        GrGLFunction<GrGLFlushMappedNamedBufferRangeProc> fFlushMappedNamedBufferRange;
        // OpenGL 3.1
        GrGLFunction<GrGLTextureBufferProc> fTextureBuffer;

        /* KHR_debug */
        GrGLFunction<GrGLDebugMessageControlProc> fDebugMessageControl;
        GrGLFunction<GrGLDebugMessageInsertProc> fDebugMessageInsert;
        GrGLFunction<GrGLDebugMessageCallbackProc> fDebugMessageCallback;
        GrGLFunction<GrGLGetDebugMessageLogProc> fGetDebugMessageLog;
        GrGLFunction<GrGLPushDebugGroupProc> fPushDebugGroup;
        GrGLFunction<GrGLPopDebugGroupProc> fPopDebugGroup;
        GrGLFunction<GrGLObjectLabelProc> fObjectLabel;

        /* EGL functions */
        GrGLFunction<GrEGLCreateImageProc> fEGLCreateImage;
        GrGLFunction<GrEGLDestroyImageProc> fEGLDestroyImage;
    } fFunctions;

    // This exists for internal testing.
    virtual void abandon() const { }
=======
        GLPtr<GrGLTextureParameteriProc> fTextureParameteri;
        GLPtr<GrGLTextureParameterivProc> fTextureParameteriv;
        GLPtr<GrGLTextureParameterfProc> fTextureParameterf;
        GLPtr<GrGLTextureParameterfvProc> fTextureParameterfv;
        GLPtr<GrGLTextureImage1DProc> fTextureImage1D;
        GLPtr<GrGLTextureImage2DProc> fTextureImage2D;
        GLPtr<GrGLTextureSubImage1DProc> fTextureSubImage1D;
        GLPtr<GrGLTextureSubImage2DProc> fTextureSubImage2D;
        GLPtr<GrGLCopyTextureImage1DProc> fCopyTextureImage1D;
        GLPtr<GrGLCopyTextureImage2DProc> fCopyTextureImage2D;
        GLPtr<GrGLCopyTextureSubImage1DProc> fCopyTextureSubImage1D;
        GLPtr<GrGLCopyTextureSubImage2DProc> fCopyTextureSubImage2D;
        GLPtr<GrGLGetTextureImageProc> fGetTextureImage;
        GLPtr<GrGLGetTextureParameterfvProc> fGetTextureParameterfv;
        GLPtr<GrGLGetTextureParameterivProc> fGetTextureParameteriv;
        GLPtr<GrGLGetTextureLevelParameterfvProc> fGetTextureLevelParameterfv;
        GLPtr<GrGLGetTextureLevelParameterivProc> fGetTextureLevelParameteriv;
        // OpenGL 1.2
        GLPtr<GrGLTextureImage3DProc> fTextureImage3D;
        GLPtr<GrGLTextureSubImage3DProc> fTextureSubImage3D;
        GLPtr<GrGLCopyTextureSubImage3DProc> fCopyTextureSubImage3D;
        GLPtr<GrGLCompressedTextureImage3DProc> fCompressedTextureImage3D;
        GLPtr<GrGLCompressedTextureImage2DProc> fCompressedTextureImage2D;
        GLPtr<GrGLCompressedTextureImage1DProc> fCompressedTextureImage1D;
        GLPtr<GrGLCompressedTextureSubImage3DProc> fCompressedTextureSubImage3D;
        GLPtr<GrGLCompressedTextureSubImage2DProc> fCompressedTextureSubImage2D;
        GLPtr<GrGLCompressedTextureSubImage1DProc> fCompressedTextureSubImage1D;
        GLPtr<GrGLGetCompressedTextureImageProc> fGetCompressedTextureImage;
        // OpenGL 1.5
        GLPtr<GrGLNamedBufferDataProc> fNamedBufferData;
        GLPtr<GrGLNamedBufferSubDataProc> fNamedBufferSubData;
        GLPtr<GrGLMapNamedBufferProc> fMapNamedBuffer;
        GLPtr<GrGLUnmapNamedBufferProc> fUnmapNamedBuffer;
        GLPtr<GrGLGetNamedBufferParameterivProc> fGetNamedBufferParameteriv;
        GLPtr<GrGLGetNamedBufferPointervProc> fGetNamedBufferPointerv;
        GLPtr<GrGLGetNamedBufferSubDataProc> fGetNamedBufferSubData;
        // OpenGL 2.0
        GLPtr<GrGLProgramUniform1fProc> fProgramUniform1f;
        GLPtr<GrGLProgramUniform2fProc> fProgramUniform2f;
        GLPtr<GrGLProgramUniform3fProc> fProgramUniform3f;
        GLPtr<GrGLProgramUniform4fProc> fProgramUniform4f;
        GLPtr<GrGLProgramUniform1iProc> fProgramUniform1i;
        GLPtr<GrGLProgramUniform2iProc> fProgramUniform2i;
        GLPtr<GrGLProgramUniform3iProc> fProgramUniform3i;
        GLPtr<GrGLProgramUniform4iProc> fProgramUniform4i;
        GLPtr<GrGLProgramUniform1fvProc> fProgramUniform1fv;
        GLPtr<GrGLProgramUniform2fvProc> fProgramUniform2fv;
        GLPtr<GrGLProgramUniform3fvProc> fProgramUniform3fv;
        GLPtr<GrGLProgramUniform4fvProc> fProgramUniform4fv;
        GLPtr<GrGLProgramUniform1ivProc> fProgramUniform1iv;
        GLPtr<GrGLProgramUniform2ivProc> fProgramUniform2iv;
        GLPtr<GrGLProgramUniform3ivProc> fProgramUniform3iv;
        GLPtr<GrGLProgramUniform4ivProc> fProgramUniform4iv;
        GLPtr<GrGLProgramUniformMatrix2fvProc> fProgramUniformMatrix2fv;
        GLPtr<GrGLProgramUniformMatrix3fvProc> fProgramUniformMatrix3fv;
        GLPtr<GrGLProgramUniformMatrix4fvProc> fProgramUniformMatrix4fv;
        // OpenGL 2.1
        GLPtr<GrGLProgramUniformMatrix2x3fvProc> fProgramUniformMatrix2x3fv;
        GLPtr<GrGLProgramUniformMatrix3x2fvProc> fProgramUniformMatrix3x2fv;
        GLPtr<GrGLProgramUniformMatrix2x4fvProc> fProgramUniformMatrix2x4fv;
        GLPtr<GrGLProgramUniformMatrix4x2fvProc> fProgramUniformMatrix4x2fv;
        GLPtr<GrGLProgramUniformMatrix3x4fvProc> fProgramUniformMatrix3x4fv;
        GLPtr<GrGLProgramUniformMatrix4x3fvProc> fProgramUniformMatrix4x3fv;
        // OpenGL 3.0
        GLPtr<GrGLNamedRenderbufferStorageProc> fNamedRenderbufferStorage;
        GLPtr<GrGLGetNamedRenderbufferParameterivProc> fGetNamedRenderbufferParameteriv;
        GLPtr<GrGLNamedRenderbufferStorageMultisampleProc> fNamedRenderbufferStorageMultisample;
        GLPtr<GrGLCheckNamedFramebufferStatusProc> fCheckNamedFramebufferStatus;
        GLPtr<GrGLNamedFramebufferTexture1DProc> fNamedFramebufferTexture1D;
        GLPtr<GrGLNamedFramebufferTexture2DProc> fNamedFramebufferTexture2D;
        GLPtr<GrGLNamedFramebufferTexture3DProc> fNamedFramebufferTexture3D;
        GLPtr<GrGLNamedFramebufferRenderbufferProc> fNamedFramebufferRenderbuffer;
        GLPtr<GrGLGetNamedFramebufferAttachmentParameterivProc> fGetNamedFramebufferAttachmentParameteriv;
        GLPtr<GrGLGenerateTextureMipmapProc> fGenerateTextureMipmap;
        GLPtr<GrGLFramebufferDrawBufferProc> fFramebufferDrawBuffer;
        GLPtr<GrGLFramebufferDrawBuffersProc> fFramebufferDrawBuffers;
        GLPtr<GrGLFramebufferReadBufferProc> fFramebufferReadBuffer;
        GLPtr<GrGLGetFramebufferParameterivProc> fGetFramebufferParameteriv;
        GLPtr<GrGLNamedCopyBufferSubDataProc> fNamedCopyBufferSubData;
        GLPtr<GrGLVertexArrayVertexOffsetProc> fVertexArrayVertexOffset;
        GLPtr<GrGLVertexArrayColorOffsetProc> fVertexArrayColorOffset;
        GLPtr<GrGLVertexArrayEdgeFlagOffsetProc> fVertexArrayEdgeFlagOffset;
        GLPtr<GrGLVertexArrayIndexOffsetProc> fVertexArrayIndexOffset;
        GLPtr<GrGLVertexArrayNormalOffsetProc> fVertexArrayNormalOffset;
        GLPtr<GrGLVertexArrayTexCoordOffsetProc> fVertexArrayTexCoordOffset;
        GLPtr<GrGLVertexArrayMultiTexCoordOffsetProc> fVertexArrayMultiTexCoordOffset;
        GLPtr<GrGLVertexArrayFogCoordOffsetProc> fVertexArrayFogCoordOffset;
        GLPtr<GrGLVertexArraySecondaryColorOffsetProc> fVertexArraySecondaryColorOffset;
        GLPtr<GrGLVertexArrayVertexAttribOffsetProc> fVertexArrayVertexAttribOffset;
        GLPtr<GrGLVertexArrayVertexAttribIOffsetProc> fVertexArrayVertexAttribIOffset;
        GLPtr<GrGLEnableVertexArrayProc> fEnableVertexArray;
        GLPtr<GrGLDisableVertexArrayProc> fDisableVertexArray;
        GLPtr<GrGLEnableVertexArrayAttribProc> fEnableVertexArrayAttrib;
        GLPtr<GrGLDisableVertexArrayAttribProc> fDisableVertexArrayAttrib;
        GLPtr<GrGLGetVertexArrayIntegervProc> fGetVertexArrayIntegerv;
        GLPtr<GrGLGetVertexArrayPointervProc> fGetVertexArrayPointerv;
        GLPtr<GrGLGetVertexArrayIntegeri_vProc> fGetVertexArrayIntegeri_v;
        GLPtr<GrGLGetVertexArrayPointeri_vProc> fGetVertexArrayPointeri_v;
        GLPtr<GrGLMapNamedBufferRangeProc> fMapNamedBufferRange;
        GLPtr<GrGLFlushMappedNamedBufferRangeProc> fFlushMappedNamedBufferRange;

        /* KHR_debug */
        GLPtr<GrGLDebugMessageControlProc> fDebugMessageControl;
        GLPtr<GrGLDebugMessageInsertProc> fDebugMessageInsert;
        GLPtr<GrGLDebugMessageCallbackProc> fDebugMessageCallback;
        GLPtr<GrGLGetDebugMessageLogProc> fGetDebugMessageLog;
        GLPtr<GrGLPushDebugGroupProc> fPushDebugGroup;
        GLPtr<GrGLPopDebugGroupProc> fPopDebugGroup;
        GLPtr<GrGLObjectLabelProc> fObjectLabel;
    } fFunctions;

    // Per-GL func callback
#if GR_GL_PER_GL_FUNC_CALLBACK
    GrGLInterfaceCallbackProc fCallback;
    GrGLInterfaceCallbackData fCallbackData;
#endif

    // This exists for internal testing.
    virtual void abandon() const {}
>>>>>>> miniblink49
};

#endif
