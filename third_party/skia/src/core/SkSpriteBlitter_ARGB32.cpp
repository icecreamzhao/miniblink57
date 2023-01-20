<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkBlitRow.h"
#include "SkColorFilter.h"
#include "SkColorPriv.h"
#include "SkSpriteBlitter.h"
=======

#include "SkSpriteBlitter.h"
#include "SkBlitRow.h"
#include "SkColorFilter.h"
#include "SkColorPriv.h"
>>>>>>> miniblink49
#include "SkTemplates.h"
#include "SkUtils.h"
#include "SkXfermode.h"

///////////////////////////////////////////////////////////////////////////////

class Sprite_D32_S32 : public SkSpriteBlitter {
public:
<<<<<<< HEAD
    Sprite_D32_S32(const SkPixmap& src, U8CPU alpha)
        : INHERITED(src)
    {
=======
    Sprite_D32_S32(const SkPixmap& src, U8CPU alpha)  : INHERITED(src) {
>>>>>>> miniblink49
        SkASSERT(src.colorType() == kN32_SkColorType);

        unsigned flags32 = 0;
        if (255 != alpha) {
            flags32 |= SkBlitRow::kGlobalAlpha_Flag32;
        }
        if (!src.isOpaque()) {
            flags32 |= SkBlitRow::kSrcPixelAlpha_Flag32;
        }

        fProc32 = SkBlitRow::Factory32(flags32);
        fAlpha = alpha;
    }

<<<<<<< HEAD
    void blitRect(int x, int y, int width, int height) override
    {
=======
    void blitRect(int x, int y, int width, int height) override {
>>>>>>> miniblink49
        SkASSERT(width > 0 && height > 0);
        uint32_t* SK_RESTRICT dst = fDst.writable_addr32(x, y);
        const uint32_t* SK_RESTRICT src = fSource.addr32(x - fLeft, y - fTop);
        size_t dstRB = fDst.rowBytes();
        size_t srcRB = fSource.rowBytes();
        SkBlitRow::Proc32 proc = fProc32;
<<<<<<< HEAD
        U8CPU alpha = fAlpha;

        do {
            proc(dst, src, width, alpha);
            dst = (uint32_t * SK_RESTRICT)((char*)dst + dstRB);
=======
        U8CPU             alpha = fAlpha;

        do {
            proc(dst, src, width, alpha);
            dst = (uint32_t* SK_RESTRICT)((char*)dst + dstRB);
>>>>>>> miniblink49
            src = (const uint32_t* SK_RESTRICT)((const char*)src + srcRB);
        } while (--height != 0);
    }

private:
<<<<<<< HEAD
    SkBlitRow::Proc32 fProc32;
    U8CPU fAlpha;
=======
    SkBlitRow::Proc32   fProc32;
    U8CPU               fAlpha;
>>>>>>> miniblink49

    typedef SkSpriteBlitter INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

class Sprite_D32_XferFilter : public SkSpriteBlitter {
public:
<<<<<<< HEAD
    Sprite_D32_XferFilter(const SkPixmap& source, const SkPaint& paint)
        : SkSpriteBlitter(source)
    {
=======
    Sprite_D32_XferFilter(const SkPixmap& source, const SkPaint& paint) : SkSpriteBlitter(source) {
>>>>>>> miniblink49
        fColorFilter = paint.getColorFilter();
        SkSafeRef(fColorFilter);

        fXfermode = paint.getXfermode();
        SkSafeRef(fXfermode);

        fBufferSize = 0;
<<<<<<< HEAD
        fBuffer = nullptr;
=======
        fBuffer = NULL;
>>>>>>> miniblink49

        unsigned flags32 = 0;
        if (255 != paint.getAlpha()) {
            flags32 |= SkBlitRow::kGlobalAlpha_Flag32;
        }
        if (!source.isOpaque()) {
            flags32 |= SkBlitRow::kSrcPixelAlpha_Flag32;
        }

        fProc32 = SkBlitRow::Factory32(flags32);
        fAlpha = paint.getAlpha();
    }

<<<<<<< HEAD
    virtual ~Sprite_D32_XferFilter()
    {
=======
    virtual ~Sprite_D32_XferFilter() {
>>>>>>> miniblink49
        delete[] fBuffer;
        SkSafeUnref(fXfermode);
        SkSafeUnref(fColorFilter);
    }

<<<<<<< HEAD
    void setup(const SkPixmap& dst, int left, int top, const SkPaint& paint) override
    {
=======
    void setup(const SkPixmap& dst, int left, int top, const SkPaint& paint) override {
>>>>>>> miniblink49
        this->INHERITED::setup(dst, left, top, paint);

        int width = dst.width();
        if (width > fBufferSize) {
            fBufferSize = width;
            delete[] fBuffer;
            fBuffer = new SkPMColor[width];
        }
    }

protected:
<<<<<<< HEAD
    SkColorFilter* fColorFilter;
    SkXfermode* fXfermode;
    int fBufferSize;
    SkPMColor* fBuffer;
    SkBlitRow::Proc32 fProc32;
    U8CPU fAlpha;
=======
    SkColorFilter*      fColorFilter;
    SkXfermode*         fXfermode;
    int                 fBufferSize;
    SkPMColor*          fBuffer;
    SkBlitRow::Proc32   fProc32;
    U8CPU               fAlpha;
>>>>>>> miniblink49

private:
    typedef SkSpriteBlitter INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

class Sprite_D32_S32A_XferFilter : public Sprite_D32_XferFilter {
public:
    Sprite_D32_S32A_XferFilter(const SkPixmap& source, const SkPaint& paint)
<<<<<<< HEAD
        : Sprite_D32_XferFilter(source, paint)
    {
    }

    void blitRect(int x, int y, int width, int height) override
    {
=======
        : Sprite_D32_XferFilter(source, paint) {}

    void blitRect(int x, int y, int width, int height) override {
>>>>>>> miniblink49
        SkASSERT(width > 0 && height > 0);
        uint32_t* SK_RESTRICT dst = fDst.writable_addr32(x, y);
        const uint32_t* SK_RESTRICT src = fSource.addr32(x - fLeft, y - fTop);
        size_t dstRB = fDst.rowBytes();
        size_t srcRB = fSource.rowBytes();
        SkColorFilter* colorFilter = fColorFilter;
        SkXfermode* xfermode = fXfermode;

        do {
            const SkPMColor* tmp = src;

            if (colorFilter) {
                colorFilter->filterSpan(src, width, fBuffer);
                tmp = fBuffer;
            }

            if (xfermode) {
<<<<<<< HEAD
                xfermode->xfer32(dst, tmp, width, nullptr);
=======
                xfermode->xfer32(dst, tmp, width, NULL);
>>>>>>> miniblink49
            } else {
                fProc32(dst, tmp, width, fAlpha);
            }

<<<<<<< HEAD
            dst = (uint32_t * SK_RESTRICT)((char*)dst + dstRB);
=======
            dst = (uint32_t* SK_RESTRICT)((char*)dst + dstRB);
>>>>>>> miniblink49
            src = (const uint32_t* SK_RESTRICT)((const char*)src + srcRB);
        } while (--height != 0);
    }

private:
    typedef Sprite_D32_XferFilter INHERITED;
};

static void fillbuffer(SkPMColor* SK_RESTRICT dst,
<<<<<<< HEAD
    const SkPMColor16* SK_RESTRICT src, int count)
{
=======
                       const SkPMColor16* SK_RESTRICT src, int count) {
>>>>>>> miniblink49
    SkASSERT(count > 0);

    do {
        *dst++ = SkPixel4444ToPixel32(*src++);
    } while (--count != 0);
}

class Sprite_D32_S4444_XferFilter : public Sprite_D32_XferFilter {
public:
    Sprite_D32_S4444_XferFilter(const SkPixmap& source, const SkPaint& paint)
<<<<<<< HEAD
        : Sprite_D32_XferFilter(source, paint)
    {
    }

    void blitRect(int x, int y, int width, int height) override
    {
=======
        : Sprite_D32_XferFilter(source, paint) {}

    void blitRect(int x, int y, int width, int height) override {
>>>>>>> miniblink49
        SkASSERT(width > 0 && height > 0);
        SkPMColor* SK_RESTRICT dst = fDst.writable_addr32(x, y);
        const SkPMColor16* SK_RESTRICT src = fSource.addr16(x - fLeft, y - fTop);
        size_t dstRB = fDst.rowBytes();
        size_t srcRB = fSource.rowBytes();
        SkPMColor* SK_RESTRICT buffer = fBuffer;
        SkColorFilter* colorFilter = fColorFilter;
        SkXfermode* xfermode = fXfermode;

        do {
            fillbuffer(buffer, src, width);

            if (colorFilter) {
                colorFilter->filterSpan(buffer, width, buffer);
            }
            if (xfermode) {
<<<<<<< HEAD
                xfermode->xfer32(dst, buffer, width, nullptr);
=======
                xfermode->xfer32(dst, buffer, width, NULL);
>>>>>>> miniblink49
            } else {
                fProc32(dst, buffer, width, fAlpha);
            }

<<<<<<< HEAD
            dst = (SkPMColor * SK_RESTRICT)((char*)dst + dstRB);
=======
            dst = (SkPMColor* SK_RESTRICT)((char*)dst + dstRB);
>>>>>>> miniblink49
            src = (const SkPMColor16* SK_RESTRICT)((const char*)src + srcRB);
        } while (--height != 0);
    }

private:
    typedef Sprite_D32_XferFilter INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static void src_row(SkPMColor* SK_RESTRICT dst,
<<<<<<< HEAD
    const SkPMColor16* SK_RESTRICT src, int count)
{
=======
                    const SkPMColor16* SK_RESTRICT src, int count) {
>>>>>>> miniblink49
    do {
        *dst = SkPixel4444ToPixel32(*src);
        src += 1;
        dst += 1;
    } while (--count != 0);
}

class Sprite_D32_S4444_Opaque : public SkSpriteBlitter {
public:
<<<<<<< HEAD
    Sprite_D32_S4444_Opaque(const SkPixmap& source)
        : SkSpriteBlitter(source)
    {
    }

    void blitRect(int x, int y, int width, int height) override
    {
=======
    Sprite_D32_S4444_Opaque(const SkPixmap& source) : SkSpriteBlitter(source) {}

    void blitRect(int x, int y, int width, int height) override {
>>>>>>> miniblink49
        SkASSERT(width > 0 && height > 0);
        SkPMColor* SK_RESTRICT dst = fDst.writable_addr32(x, y);
        const SkPMColor16* SK_RESTRICT src = fSource.addr16(x - fLeft, y - fTop);
        size_t dstRB = fDst.rowBytes();
        size_t srcRB = fSource.rowBytes();

        do {
            src_row(dst, src, width);
<<<<<<< HEAD
            dst = (SkPMColor * SK_RESTRICT)((char*)dst + dstRB);
=======
            dst = (SkPMColor* SK_RESTRICT)((char*)dst + dstRB);
>>>>>>> miniblink49
            src = (const SkPMColor16* SK_RESTRICT)((const char*)src + srcRB);
        } while (--height != 0);
    }
};

static void srcover_row(SkPMColor* SK_RESTRICT dst,
<<<<<<< HEAD
    const SkPMColor16* SK_RESTRICT src, int count)
{
=======
                        const SkPMColor16* SK_RESTRICT src, int count) {
>>>>>>> miniblink49
    do {
        *dst = SkPMSrcOver(SkPixel4444ToPixel32(*src), *dst);
        src += 1;
        dst += 1;
    } while (--count != 0);
}

class Sprite_D32_S4444 : public SkSpriteBlitter {
public:
<<<<<<< HEAD
    Sprite_D32_S4444(const SkPixmap& source)
        : SkSpriteBlitter(source)
    {
    }

    void blitRect(int x, int y, int width, int height) override
    {
=======
    Sprite_D32_S4444(const SkPixmap& source) : SkSpriteBlitter(source) {}

    void blitRect(int x, int y, int width, int height) override {
>>>>>>> miniblink49
        SkASSERT(width > 0 && height > 0);
        SkPMColor* SK_RESTRICT dst = fDst.writable_addr32(x, y);
        const SkPMColor16* SK_RESTRICT src = fSource.addr16(x - fLeft, y - fTop);
        size_t dstRB = fDst.rowBytes();
        size_t srcRB = fSource.rowBytes();

        do {
            srcover_row(dst, src, width);
<<<<<<< HEAD
            dst = (SkPMColor * SK_RESTRICT)((char*)dst + dstRB);
=======
            dst = (SkPMColor* SK_RESTRICT)((char*)dst + dstRB);
>>>>>>> miniblink49
            src = (const SkPMColor16* SK_RESTRICT)((const char*)src + srcRB);
        } while (--height != 0);
    }
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkSpriteBlitter* SkSpriteBlitter::ChooseL32(const SkPixmap& source, const SkPaint& paint,
    SkTBlitterAllocator* allocator)
{
    SkASSERT(allocator != nullptr);

    if (paint.getMaskFilter() != nullptr) {
        return nullptr;
    }

    U8CPU alpha = paint.getAlpha();
    SkXfermode* xfermode = paint.getXfermode();
    SkColorFilter* filter = paint.getColorFilter();
    SkSpriteBlitter* blitter = nullptr;

    switch (source.colorType()) {
    case kARGB_4444_SkColorType:
        if (alpha != 0xFF) {
            return nullptr; // we only have opaque sprites
        }
        if (xfermode || filter) {
            blitter = allocator->createT<Sprite_D32_S4444_XferFilter>(source, paint);
        } else if (source.isOpaque()) {
            blitter = allocator->createT<Sprite_D32_S4444_Opaque>(source);
        } else {
            blitter = allocator->createT<Sprite_D32_S4444>(source);
        }
        break;
    case kN32_SkColorType:
        if (xfermode || filter) {
            if (255 == alpha) {
                // this can handle xfermode or filter, but not alpha
                blitter = allocator->createT<Sprite_D32_S32A_XferFilter>(source, paint);
            }
        } else {
            // this can handle alpha, but not xfermode or filter
            blitter = allocator->createT<Sprite_D32_S32>(source, alpha);
        }
        break;
    default:
        break;
=======
SkSpriteBlitter* SkSpriteBlitter::ChooseD32(const SkPixmap& source, const SkPaint& paint,
        SkTBlitterAllocator* allocator) {
    SkASSERT(allocator != NULL);

    if (paint.getMaskFilter() != NULL) {
        return NULL;
    }

    U8CPU       alpha = paint.getAlpha();
    SkXfermode* xfermode = paint.getXfermode();
    SkColorFilter* filter = paint.getColorFilter();
    SkSpriteBlitter* blitter = NULL;

    switch (source.colorType()) {
        case kARGB_4444_SkColorType:
            if (alpha != 0xFF) {
                return NULL;    // we only have opaque sprites
            }
            if (xfermode || filter) {
                blitter = allocator->createT<Sprite_D32_S4444_XferFilter>(source, paint);
            } else if (source.isOpaque()) {
                blitter = allocator->createT<Sprite_D32_S4444_Opaque>(source);
            } else {
                blitter = allocator->createT<Sprite_D32_S4444>(source);
            }
            break;
        case kN32_SkColorType:
            if (xfermode || filter) {
                if (255 == alpha) {
                    // this can handle xfermode or filter, but not alpha
                    blitter = allocator->createT<Sprite_D32_S32A_XferFilter>(source, paint);
                }
            } else {
                // this can handle alpha, but not xfermode or filter
                blitter = allocator->createT<Sprite_D32_S32>(source, alpha);
            }
            break;
        default:
            break;
>>>>>>> miniblink49
    }
    return blitter;
}
