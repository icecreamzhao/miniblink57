/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkCoreBlitters_DEFINED
#define SkCoreBlitters_DEFINED

#include "SkBitmapProcShader.h"
<<<<<<< HEAD
#include "SkBlitRow.h"
#include "SkBlitter.h"
=======
#include "SkBlitter.h"
#include "SkBlitRow.h"
>>>>>>> miniblink49
#include "SkShader.h"
#include "SkSmallAllocator.h"

class SkRasterBlitter : public SkBlitter {
public:
<<<<<<< HEAD
    SkRasterBlitter(const SkPixmap& device)
        : fDevice(device)
    {
    }
=======
    SkRasterBlitter(const SkPixmap& device) : fDevice(device) {}
>>>>>>> miniblink49

protected:
    const SkPixmap fDevice;

private:
    typedef SkBlitter INHERITED;
};

class SkShaderBlitter : public SkRasterBlitter {
public:
    /**
      *  The storage for shaderContext is owned by the caller, but the object itself is not.
      *  The blitter only ensures that the storage always holds a live object, but it may
      *  exchange that object.
      */
    SkShaderBlitter(const SkPixmap& device, const SkPaint& paint,
<<<<<<< HEAD
        SkShader::Context* shaderContext);
=======
                    SkShader::Context* shaderContext);
>>>>>>> miniblink49
    virtual ~SkShaderBlitter();

    /**
      *  Create a new shader context and uses it instead of the old one if successful.
      *  Will create the context at the same location as the old one (this is safe
      *  because the shader itself is unchanged).
      */
    bool resetShaderContext(const SkShader::ContextRec&) override;

    SkShader::Context* getShaderContext() const override { return fShaderContext; }

protected:
<<<<<<< HEAD
    uint32_t fShaderFlags;
    const SkShader* fShader;
    SkShader::Context* fShaderContext;
    bool fConstInY;
=======
    uint32_t            fShaderFlags;
    const SkShader*     fShader;
    SkShader::Context*  fShaderContext;
>>>>>>> miniblink49

private:
    // illegal
    SkShaderBlitter& operator=(const SkShaderBlitter&);

    typedef SkRasterBlitter INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

class SkA8_Coverage_Blitter : public SkRasterBlitter {
public:
    SkA8_Coverage_Blitter(const SkPixmap& device, const SkPaint& paint);
    void blitH(int x, int y, int width) override;
    void blitAntiH(int x, int y, const SkAlpha antialias[], const int16_t runs[]) override;
    void blitV(int x, int y, int height, SkAlpha alpha) override;
    void blitRect(int x, int y, int width, int height) override;
    void blitMask(const SkMask&, const SkIRect&) override;
    const SkPixmap* justAnOpaqueColor(uint32_t*) override;
};

class SkA8_Blitter : public SkRasterBlitter {
public:
    SkA8_Blitter(const SkPixmap& device, const SkPaint& paint);
    void blitH(int x, int y, int width) override;
    void blitAntiH(int x, int y, const SkAlpha antialias[], const int16_t runs[]) override;
    void blitV(int x, int y, int height, SkAlpha alpha) override;
    void blitRect(int x, int y, int width, int height) override;
    void blitMask(const SkMask&, const SkIRect&) override;
    const SkPixmap* justAnOpaqueColor(uint32_t*) override;

private:
    unsigned fSrcA;

    // illegal
    SkA8_Blitter& operator=(const SkA8_Blitter&);

    typedef SkRasterBlitter INHERITED;
};

class SkA8_Shader_Blitter : public SkShaderBlitter {
public:
    SkA8_Shader_Blitter(const SkPixmap& device, const SkPaint& paint,
<<<<<<< HEAD
        SkShader::Context* shaderContext);
=======
                        SkShader::Context* shaderContext);
>>>>>>> miniblink49
    virtual ~SkA8_Shader_Blitter();
    void blitH(int x, int y, int width) override;
    void blitAntiH(int x, int y, const SkAlpha antialias[], const int16_t runs[]) override;
    void blitMask(const SkMask&, const SkIRect&) override;

private:
    SkXfermode* fXfermode;
<<<<<<< HEAD
    SkPMColor* fBuffer;
    uint8_t* fAAExpand;
=======
    SkPMColor*  fBuffer;
    uint8_t*    fAAExpand;
>>>>>>> miniblink49

    // illegal
    SkA8_Shader_Blitter& operator=(const SkA8_Shader_Blitter&);

    typedef SkShaderBlitter INHERITED;
};

////////////////////////////////////////////////////////////////

class SkARGB32_Blitter : public SkRasterBlitter {
public:
    SkARGB32_Blitter(const SkPixmap& device, const SkPaint& paint);
    void blitH(int x, int y, int width) override;
    void blitAntiH(int x, int y, const SkAlpha antialias[], const int16_t runs[]) override;
    void blitV(int x, int y, int height, SkAlpha alpha) override;
    void blitRect(int x, int y, int width, int height) override;
    void blitMask(const SkMask&, const SkIRect&) override;
    const SkPixmap* justAnOpaqueColor(uint32_t*) override;
    void blitAntiH2(int x, int y, U8CPU a0, U8CPU a1) override;
    void blitAntiV2(int x, int y, U8CPU a0, U8CPU a1) override;

protected:
<<<<<<< HEAD
    SkColor fColor;
    SkPMColor fPMColor;
=======
    SkColor                fColor;
    SkPMColor              fPMColor;
>>>>>>> miniblink49

private:
    unsigned fSrcA, fSrcR, fSrcG, fSrcB;

    // illegal
    SkARGB32_Blitter& operator=(const SkARGB32_Blitter&);

    typedef SkRasterBlitter INHERITED;
};

class SkARGB32_Opaque_Blitter : public SkARGB32_Blitter {
public:
    SkARGB32_Opaque_Blitter(const SkPixmap& device, const SkPaint& paint)
<<<<<<< HEAD
        : INHERITED(device, paint)
    {
        SkASSERT(paint.getAlpha() == 0xFF);
    }
=======
        : INHERITED(device, paint) { SkASSERT(paint.getAlpha() == 0xFF); }
>>>>>>> miniblink49
    void blitMask(const SkMask&, const SkIRect&) override;
    void blitAntiH2(int x, int y, U8CPU a0, U8CPU a1) override;
    void blitAntiV2(int x, int y, U8CPU a0, U8CPU a1) override;

private:
    typedef SkARGB32_Blitter INHERITED;
};

class SkARGB32_Black_Blitter : public SkARGB32_Opaque_Blitter {
public:
    SkARGB32_Black_Blitter(const SkPixmap& device, const SkPaint& paint)
<<<<<<< HEAD
        : INHERITED(device, paint)
    {
    }
=======
        : INHERITED(device, paint) {}
>>>>>>> miniblink49
    void blitAntiH(int x, int y, const SkAlpha antialias[], const int16_t runs[]) override;
    void blitAntiH2(int x, int y, U8CPU a0, U8CPU a1) override;
    void blitAntiV2(int x, int y, U8CPU a0, U8CPU a1) override;

private:
    typedef SkARGB32_Opaque_Blitter INHERITED;
};

class SkARGB32_Shader_Blitter : public SkShaderBlitter {
public:
    SkARGB32_Shader_Blitter(const SkPixmap& device, const SkPaint& paint,
<<<<<<< HEAD
        SkShader::Context* shaderContext);
=======
                            SkShader::Context* shaderContext);
>>>>>>> miniblink49
    virtual ~SkARGB32_Shader_Blitter();
    void blitH(int x, int y, int width) override;
    void blitV(int x, int y, int height, SkAlpha alpha) override;
    void blitRect(int x, int y, int width, int height) override;
    void blitAntiH(int x, int y, const SkAlpha[], const int16_t[]) override;
    void blitMask(const SkMask&, const SkIRect&) override;

private:
<<<<<<< HEAD
    SkXfermode* fXfermode;
    SkPMColor* fBuffer;
    SkBlitRow::Proc32 fProc32;
    SkBlitRow::Proc32 fProc32Blend;
    bool fShadeDirectlyIntoDevice;
=======
    SkXfermode*         fXfermode;
    SkPMColor*          fBuffer;
    SkBlitRow::Proc32   fProc32;
    SkBlitRow::Proc32   fProc32Blend;
    bool                fShadeDirectlyIntoDevice;
    bool                fConstInY;
>>>>>>> miniblink49

    // illegal
    SkARGB32_Shader_Blitter& operator=(const SkARGB32_Shader_Blitter&);

    typedef SkShaderBlitter INHERITED;
};

<<<<<<< HEAD
SkBlitter* SkBlitter_ARGB32_Create(const SkPixmap& device, const SkPaint&, SkShader::Context*,
    SkTBlitterAllocator*);

SkBlitter* SkBlitter_F16_Create(const SkPixmap& device, const SkPaint&, SkShader::Context*,
    SkTBlitterAllocator*);

=======
>>>>>>> miniblink49
///////////////////////////////////////////////////////////////////////////////

/*  These return the correct subclass of blitter for their device config.

    Currently, they make the following assumptions about the state of the
    paint:

    1. If there is an xfermode, there will also be a shader
    2. If there is a colorfilter, there will be a shader that itself handles
       calling the filter, so the blitter can always ignore the colorfilter obj

    These pre-conditions must be handled by the caller, in our case
    SkBlitter::Choose(...)
 */

SkBlitter* SkBlitter_ChooseD565(const SkPixmap& device, const SkPaint& paint,
<<<<<<< HEAD
    SkShader::Context* shaderContext,
    SkTBlitterAllocator* allocator);
=======
                                SkShader::Context* shaderContext,
                                SkTBlitterAllocator* allocator);
>>>>>>> miniblink49

#endif
