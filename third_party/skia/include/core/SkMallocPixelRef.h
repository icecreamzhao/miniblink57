/*
 * Copyright 2008 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkMallocPixelRef_DEFINED
#define SkMallocPixelRef_DEFINED

#include "SkPixelRef.h"

/** We explicitly use the same allocator for our pixels that SkMask does,
    so that we can freely assign memory allocated by one class to the other.
*/
class SK_API SkMallocPixelRef : public SkPixelRef {
public:
    /**
     *  Return a new SkMallocPixelRef with the provided pixel storage, rowBytes,
     *  and optional colortable. The caller is responsible for managing the
     *  lifetime of the pixel storage buffer, as this pixelref will not try
     *  to delete it.
     *
     *  The pixelref will ref() the colortable (if not NULL).
     *
     *  Returns NULL on failure.
     */
    static SkMallocPixelRef* NewDirect(const SkImageInfo&, void* addr,
<<<<<<< HEAD
        size_t rowBytes, SkColorTable*);
=======
                                       size_t rowBytes, SkColorTable*);
>>>>>>> miniblink49

    /**
     *  Return a new SkMallocPixelRef, automatically allocating storage for the
     *  pixels. If rowBytes are 0, an optimal value will be chosen automatically.
     *  If rowBytes is > 0, then it will be respected, or NULL will be returned
     *  if rowBytes is invalid for the specified info.
     *
     *  This pixelref will ref() the specified colortable (if not NULL).
     *
     *  Returns NULL on failure.
     */
    static SkMallocPixelRef* NewAllocate(const SkImageInfo& info,
<<<<<<< HEAD
        size_t rowBytes, SkColorTable*);

    /**
     *  Identical to NewAllocate, except all pixel bytes are zeroed.
     */
    static SkMallocPixelRef* NewZeroed(const SkImageInfo& info,
        size_t rowBytes, SkColorTable*);
=======
                                         size_t rowBytes, SkColorTable*);
>>>>>>> miniblink49

    /**
     *  Return a new SkMallocPixelRef with the provided pixel storage,
     *  rowBytes, and optional colortable. On destruction, ReleaseProc
     *  will be called.
     *
     *  This pixelref will ref() the specified colortable (if not NULL).
     *
     *  If ReleaseProc is NULL, the pixels will never be released. This
     *  can be useful if the pixels were stack allocated. However, such an
     *  SkMallocPixelRef must not live beyond its pixels (e.g. by copying
     *  an SkBitmap pointing to it, or drawing to an SkPicture).
     *
     *  Returns NULL on failure.
     */
    typedef void (*ReleaseProc)(void* addr, void* context);
    static SkMallocPixelRef* NewWithProc(const SkImageInfo& info,
<<<<<<< HEAD
        size_t rowBytes, SkColorTable*,
        void* addr, ReleaseProc proc,
        void* context);
=======
                                         size_t rowBytes, SkColorTable*,
                                         void* addr, ReleaseProc proc,
                                         void* context);
>>>>>>> miniblink49

    /**
     *  Return a new SkMallocPixelRef that will use the provided
     *  SkData, rowBytes, and optional colortable as pixel storage.
     *  The SkData will be ref()ed and on destruction of the PielRef,
     *  the SkData will be unref()ed.
     *
     *  This pixelref will ref() the specified colortable (if not NULL).
     *
     *  Returns NULL on failure.
     */
    static SkMallocPixelRef* NewWithData(const SkImageInfo& info,
<<<<<<< HEAD
        size_t rowBytes,
        SkColorTable* ctable,
        SkData* data);
=======
                                         size_t rowBytes,
                                         SkColorTable* ctable,
                                         SkData* data);
>>>>>>> miniblink49

    void* getAddr() const { return fStorage; }

    class PRFactory : public SkPixelRefFactory {
    public:
<<<<<<< HEAD
        SkPixelRef* create(const SkImageInfo&, size_t rowBytes, SkColorTable*) override;
    };

    class ZeroedPRFactory : public SkPixelRefFactory {
    public:
        SkPixelRef* create(const SkImageInfo&, size_t rowBytes, SkColorTable*) override;
=======
        virtual SkPixelRef* create(const SkImageInfo&,
                                   size_t rowBytes,
                                   SkColorTable*) override;
>>>>>>> miniblink49
    };

protected:
    // The ownPixels version of this constructor is deprecated.
    SkMallocPixelRef(const SkImageInfo&, void* addr, size_t rb, SkColorTable*,
<<<<<<< HEAD
        bool ownPixels);
=======
                     bool ownPixels);
>>>>>>> miniblink49
    virtual ~SkMallocPixelRef();

    bool onNewLockPixels(LockRec*) override;
    void onUnlockPixels() override;
    size_t getAllocatedSizeInBytes() const override;

private:
<<<<<<< HEAD
    // Uses alloc to implement NewAllocate or NewZeroed.
    static SkMallocPixelRef* NewUsing(void* (*alloc)(size_t),
        const SkImageInfo&,
        size_t rowBytes,
        SkColorTable*);

    void* fStorage;
    SkColorTable* fCTable;
    size_t fRB;
    ReleaseProc fReleaseProc;
    void* fReleaseProcContext;

    SkMallocPixelRef(const SkImageInfo&, void* addr, size_t rb, SkColorTable*,
        ReleaseProc proc, void* context);
=======
    void*           fStorage;
    SkColorTable*   fCTable;
    size_t          fRB;
    ReleaseProc     fReleaseProc;
    void*           fReleaseProcContext;

    SkMallocPixelRef(const SkImageInfo&, void* addr, size_t rb, SkColorTable*,
                     ReleaseProc proc, void* context);
>>>>>>> miniblink49

    typedef SkPixelRef INHERITED;
};

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#endif
