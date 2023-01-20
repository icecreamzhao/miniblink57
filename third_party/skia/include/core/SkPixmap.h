/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkPixmap_DEFINED
#define SkPixmap_DEFINED

#include "SkColor.h"
<<<<<<< HEAD
#include "SkFilterQuality.h"
#include "SkImageInfo.h"

class SkColorTable;
class SkData;
=======
#include "SkImageInfo.h"

class SkColorTable;
>>>>>>> miniblink49
struct SkMask;

/**
 *  Pairs SkImageInfo with actual pixels and rowbytes. This class does not try to manage the
 *  lifetime of the pixel memory (nor the colortable if provided).
 */
<<<<<<< HEAD
class SK_API SkPixmap {
public:
    SkPixmap()
        : fPixels(NULL)
        , fCTable(NULL)
        , fRowBytes(0)
        , fInfo(SkImageInfo::MakeUnknown(0, 0))
    {
    }

    SkPixmap(const SkImageInfo& info, const void* addr, size_t rowBytes,
        SkColorTable* ctable = NULL)
        : fPixels(addr)
        , fCTable(ctable)
        , fRowBytes(rowBytes)
        , fInfo(info)
=======
class SkPixmap {
public:
    SkPixmap()
        : fPixels(NULL), fCTable(NULL), fRowBytes(0), fInfo(SkImageInfo::MakeUnknown(0, 0))
    {}

    SkPixmap(const SkImageInfo& info, const void* addr, size_t rowBytes,
             SkColorTable* ctable = NULL)
        : fPixels(addr), fCTable(ctable), fRowBytes(rowBytes), fInfo(info)
>>>>>>> miniblink49
    {
        if (kIndex_8_SkColorType == info.colorType()) {
            SkASSERT(ctable);
        } else {
            SkASSERT(NULL == ctable);
        }
    }

    void reset();
    void reset(const SkImageInfo& info, const void* addr, size_t rowBytes,
<<<<<<< HEAD
        SkColorTable* ctable = NULL);
    void reset(const SkImageInfo& info)
    {
        this->reset(info, NULL, 0, NULL);
    }

    // overrides the colorspace in the SkImageInfo of the pixmap
    void setColorSpace(sk_sp<SkColorSpace>);

=======
               SkColorTable* ctable = NULL);
    void reset(const SkImageInfo& info) {
        this->reset(info, NULL, 0, NULL);
    }

>>>>>>> miniblink49
    /**
     *  If supported, set this pixmap to point to the pixels in the specified mask and return true.
     *  On failure, return false and set this pixmap to empty.
     */
    bool SK_WARN_UNUSED_RESULT reset(const SkMask&);

    /**
     *  Computes the intersection of area and this pixmap. If that intersection is non-empty,
     *  set subset to that intersection and return true.
     *
     *  On failure, return false and ignore the subset parameter.
     */
    bool SK_WARN_UNUSED_RESULT extractSubset(SkPixmap* subset, const SkIRect& area) const;

    const SkImageInfo& info() const { return fInfo; }
    size_t rowBytes() const { return fRowBytes; }
    const void* addr() const { return fPixels; }
    SkColorTable* ctable() const { return fCTable; }

    int width() const { return fInfo.width(); }
    int height() const { return fInfo.height(); }
    SkColorType colorType() const { return fInfo.colorType(); }
    SkAlphaType alphaType() const { return fInfo.alphaType(); }
    bool isOpaque() const { return fInfo.isOpaque(); }

    SkIRect bounds() const { return SkIRect::MakeWH(this->width(), this->height()); }

<<<<<<< HEAD
    /**
     *  Return the rowbytes expressed as a number of pixels (like width and height).
     */
    int rowBytesAsPixels() const { return int(fRowBytes >> this->shiftPerPixel()); }

    /**
     *  Return the shift amount per pixel (i.e. 0 for 1-byte per pixel, 1 for 2-bytes per pixel
     *  colortypes, 2 for 4-bytes per pixel colortypes). Return 0 for kUnknown_SkColorType.
     */
    int shiftPerPixel() const { return fInfo.shiftPerPixel(); }

=======
>>>>>>> miniblink49
    uint64_t getSize64() const { return sk_64_mul(fInfo.height(), fRowBytes); }
    uint64_t getSafeSize64() const { return fInfo.getSafeSize64(fRowBytes); }
    size_t getSafeSize() const { return fInfo.getSafeSize(fRowBytes); }

<<<<<<< HEAD
    const void* addr(int x, int y) const
    {
        return (const char*)fPixels + fInfo.computeOffset(x, y, fRowBytes);
    }
    const uint8_t* addr8() const
    {
        SkASSERT(1 == SkColorTypeBytesPerPixel(fInfo.colorType()));
        return reinterpret_cast<const uint8_t*>(fPixels);
    }
    const uint16_t* addr16() const
    {
        SkASSERT(2 == SkColorTypeBytesPerPixel(fInfo.colorType()));
        return reinterpret_cast<const uint16_t*>(fPixels);
    }
    const uint32_t* addr32() const
    {
        SkASSERT(4 == SkColorTypeBytesPerPixel(fInfo.colorType()));
        return reinterpret_cast<const uint32_t*>(fPixels);
    }
    const uint64_t* addr64() const
    {
        SkASSERT(8 == SkColorTypeBytesPerPixel(fInfo.colorType()));
        return reinterpret_cast<const uint64_t*>(fPixels);
    }
    const uint16_t* addrF16() const
    {
        SkASSERT(8 == SkColorTypeBytesPerPixel(fInfo.colorType()));
        SkASSERT(kRGBA_F16_SkColorType == fInfo.colorType());
        return reinterpret_cast<const uint16_t*>(fPixels);
    }

    // Offset by the specified x,y coordinates

    const uint8_t* addr8(int x, int y) const
    {
        SkASSERT((unsigned)x < (unsigned)fInfo.width());
        SkASSERT((unsigned)y < (unsigned)fInfo.height());
        return (const uint8_t*)((const char*)this->addr8() + y * fRowBytes + (x << 0));
    }
    const uint16_t* addr16(int x, int y) const
    {
        SkASSERT((unsigned)x < (unsigned)fInfo.width());
        SkASSERT((unsigned)y < (unsigned)fInfo.height());
        return (const uint16_t*)((const char*)this->addr16() + y * fRowBytes + (x << 1));
    }
    const uint32_t* addr32(int x, int y) const
    {
=======
    const uint32_t* addr32() const {
        SkASSERT(4 == SkColorTypeBytesPerPixel(fInfo.colorType()));
        return reinterpret_cast<const uint32_t*>(fPixels);
    }

    const uint16_t* addr16() const {
        SkASSERT(2 == SkColorTypeBytesPerPixel(fInfo.colorType()));
        return reinterpret_cast<const uint16_t*>(fPixels);
    }

    const uint8_t* addr8() const {
        SkASSERT(1 == SkColorTypeBytesPerPixel(fInfo.colorType()));
        return reinterpret_cast<const uint8_t*>(fPixels);
    }

    const uint32_t* addr32(int x, int y) const {
>>>>>>> miniblink49
        SkASSERT((unsigned)x < (unsigned)fInfo.width());
        SkASSERT((unsigned)y < (unsigned)fInfo.height());
        return (const uint32_t*)((const char*)this->addr32() + y * fRowBytes + (x << 2));
    }
<<<<<<< HEAD
    const uint64_t* addr64(int x, int y) const
    {
        SkASSERT((unsigned)x < (unsigned)fInfo.width());
        SkASSERT((unsigned)y < (unsigned)fInfo.height());
        return (const uint64_t*)((const char*)this->addr64() + y * fRowBytes + (x << 3));
    }
    const uint16_t* addrF16(int x, int y) const
    {
        SkASSERT(kRGBA_F16_SkColorType == fInfo.colorType());
        return reinterpret_cast<const uint16_t*>(this->addr64(x, y));
=======
    const uint16_t* addr16(int x, int y) const {
        SkASSERT((unsigned)x < (unsigned)fInfo.width());
        SkASSERT((unsigned)y < (unsigned)fInfo.height());
        return (const uint16_t*)((const char*)this->addr16() + y * fRowBytes + (x << 1));
    }
    const uint8_t* addr8(int x, int y) const {
        SkASSERT((unsigned)x < (unsigned)fInfo.width());
        SkASSERT((unsigned)y < (unsigned)fInfo.height());
        return (const uint8_t*)((const char*)this->addr8() + y * fRowBytes + (x << 0));
    }
    const void* addr(int x, int y) const {
        return (const char*)fPixels + fInfo.computeOffset(x, y, fRowBytes);
>>>>>>> miniblink49
    }

    // Writable versions

    void* writable_addr() const { return const_cast<void*>(fPixels); }
<<<<<<< HEAD
    void* writable_addr(int x, int y) const
    {
        return const_cast<void*>(this->addr(x, y));
    }
    uint8_t* writable_addr8(int x, int y) const
    {
        return const_cast<uint8_t*>(this->addr8(x, y));
    }
    uint16_t* writable_addr16(int x, int y) const
    {
        return const_cast<uint16_t*>(this->addr16(x, y));
    }
    uint32_t* writable_addr32(int x, int y) const
    {
        return const_cast<uint32_t*>(this->addr32(x, y));
    }
    uint64_t* writable_addr64(int x, int y) const
    {
        return const_cast<uint64_t*>(this->addr64(x, y));
    }
    uint16_t* writable_addrF16(int x, int y) const
    {
        return reinterpret_cast<uint16_t*>(writable_addr64(x, y));
=======
    uint32_t* writable_addr32(int x, int y) const {
        return const_cast<uint32_t*>(this->addr32(x, y));
    }
    uint16_t* writable_addr16(int x, int y) const {
        return const_cast<uint16_t*>(this->addr16(x, y));
    }
    uint8_t* writable_addr8(int x, int y) const {
        return const_cast<uint8_t*>(this->addr8(x, y));
>>>>>>> miniblink49
    }

    // copy methods

    bool readPixels(const SkImageInfo& dstInfo, void* dstPixels, size_t dstRowBytes,
<<<<<<< HEAD
        int srcX, int srcY) const;
    bool readPixels(const SkImageInfo& dstInfo, void* dstPixels, size_t dstRowBytes) const
    {
        return this->readPixels(dstInfo, dstPixels, dstRowBytes, 0, 0);
    }
    bool readPixels(const SkPixmap& dst, int srcX, int srcY) const
    {
        return this->readPixels(dst.info(), dst.writable_addr(), dst.rowBytes(), srcX, srcY);
    }
    bool readPixels(const SkPixmap& dst) const
    {
=======
                    int srcX, int srcY) const;
    bool readPixels(const SkImageInfo& dstInfo, void* dstPixels, size_t dstRowBytes) const {
        return this->readPixels(dstInfo, dstPixels, dstRowBytes, 0, 0);
    }
    bool readPixels(const SkPixmap& dst, int srcX, int srcY) const {
        return this->readPixels(dst.info(), dst.writable_addr(), dst.rowBytes(), srcX, srcY);
    }
    bool readPixels(const SkPixmap& dst) const {
>>>>>>> miniblink49
        return this->readPixels(dst.info(), dst.writable_addr(), dst.rowBytes(), 0, 0);
    }

    /**
<<<<<<< HEAD
     *  Copy the pixels from this pixmap into the dst pixmap, converting as needed into dst's
     *  colortype/alphatype. If the conversion cannot be performed, false is returned.
     *
     *  If dst's dimensions differ from the src dimension, the image will be scaled, applying the
     *  specified filter-quality.
     */
    bool scalePixels(const SkPixmap& dst, SkFilterQuality) const;

    /**
=======
>>>>>>> miniblink49
     *  Returns true if pixels were written to (e.g. if colorType is kUnknown_SkColorType, this
     *  will return false). If subset does not intersect the bounds of this pixmap, returns false.
     */
    bool erase(SkColor, const SkIRect& subset) const;

    bool erase(SkColor color) const { return this->erase(color, this->bounds()); }
<<<<<<< HEAD
    bool erase(const SkColor4f&, const SkIRect* subset = nullptr) const;

private:
    const void* fPixels;
    SkColorTable* fCTable;
    size_t fRowBytes;
    SkImageInfo fInfo;
=======

private:
    const void*     fPixels;
    SkColorTable*   fCTable;
    size_t          fRowBytes;
    SkImageInfo     fInfo;
>>>>>>> miniblink49
};

/////////////////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
/////////////////////////////////////////////////////////////////////////////////////////////

class SK_API SkAutoPixmapUnlock : ::SkNoncopyable {
public:
    SkAutoPixmapUnlock()
        : fUnlockProc(NULL)
        , fIsLocked(false)
    {
    }
    SkAutoPixmapUnlock(const SkPixmap& pm, void (*unlock)(void*), void* ctx)
        : fUnlockProc(unlock)
        , fUnlockContext(ctx)
        , fPixmap(pm)
        , fIsLocked(true)
    {
    }
=======
class SkAutoPixmapStorage : public SkPixmap {
public:
    SkAutoPixmapStorage();
    ~SkAutoPixmapStorage();

    /**
     *  Try to allocate memory for the pixels needed to match the specified Info. On success
     *  return true and fill out the pixmap to point to that memory. The storage will be freed
     *  when this object is destroyed, or if another call to tryAlloc() or alloc() is made.
     *
     *  On failure, return false and reset() the pixmap to empty.
     */
    bool tryAlloc(const SkImageInfo&);

    /**
     *  Allocate memory for the pixels needed to match the specified Info and fill out the pixmap
     *  to point to that memory. The storage will be freed when this object is destroyed,
     *  or if another call to tryAlloc() or alloc() is made.
     *
     *  If the memory cannot be allocated, calls sk_throw().
     */
    void alloc(const SkImageInfo&);

    // We wrap these so we can clear our internal storage

    void reset() {
        this->freeStorage();
        this->INHERITED::reset();
    }
    void reset(const SkImageInfo& info, const void* addr, size_t rb, SkColorTable* ctable = NULL) {
        this->freeStorage();
        this->INHERITED::reset(info, addr, rb, ctable);
    }
    void reset(const SkImageInfo& info) {
        this->freeStorage();
        this->INHERITED::reset(info);
    }
    bool SK_WARN_UNUSED_RESULT reset(const SkMask& mask) {
        this->freeStorage();
        return this->INHERITED::reset(mask);
    }

private:
    void*   fStorage;

    void freeStorage() {
        sk_free(fStorage);
        fStorage = NULL;
    }

    typedef SkPixmap INHERITED;
};

/////////////////////////////////////////////////////////////////////////////////////////////

class SkAutoPixmapUnlock : ::SkNoncopyable {
public:
    SkAutoPixmapUnlock() : fUnlockProc(NULL), fIsLocked(false) {}
    SkAutoPixmapUnlock(const SkPixmap& pm, void (*unlock)(void*), void* ctx)
        : fUnlockProc(unlock), fUnlockContext(ctx), fPixmap(pm), fIsLocked(true)
    {}
>>>>>>> miniblink49
    ~SkAutoPixmapUnlock() { this->unlock(); }

    /**
     *  Return the currently locked pixmap. Undefined if it has been unlocked.
     */
<<<<<<< HEAD
    const SkPixmap& pixmap() const
    {
=======
    const SkPixmap& pixmap() const {
>>>>>>> miniblink49
        SkASSERT(this->isLocked());
        return fPixmap;
    }

    bool isLocked() const { return fIsLocked; }

    /**
     *  Unlocks the pixmap. Can safely be called more than once as it will only call the underlying
     *  unlock-proc once.
     */
<<<<<<< HEAD
    void unlock()
    {
=======
    void unlock() {
>>>>>>> miniblink49
        if (fUnlockProc) {
            SkASSERT(fIsLocked);
            fUnlockProc(fUnlockContext);
            fUnlockProc = NULL;
            fIsLocked = false;
        }
    }

    /**
     *  If there is a currently locked pixmap, unlock it, then copy the specified pixmap
     *  and (optional) unlock proc/context.
     */
    void reset(const SkPixmap& pm, void (*unlock)(void*), void* ctx);

private:
<<<<<<< HEAD
    void (*fUnlockProc)(void*);
    void* fUnlockContext;
    SkPixmap fPixmap;
    bool fIsLocked;
=======
    void        (*fUnlockProc)(void*);
    void*       fUnlockContext;
    SkPixmap    fPixmap;
    bool        fIsLocked;
>>>>>>> miniblink49

    friend class SkBitmap;
};

#endif
