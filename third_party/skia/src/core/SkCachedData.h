/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkCachedData_DEFINED
#define SkCachedData_DEFINED

#include "SkMutex.h"
<<<<<<< HEAD
#include "SkTypes.h"
=======
>>>>>>> miniblink49

class SkDiscardableMemory;

class SkCachedData : ::SkNoncopyable {
public:
    SkCachedData(void* mallocData, size_t size);
    SkCachedData(size_t size, SkDiscardableMemory*);
    virtual ~SkCachedData();

    size_t size() const { return fSize; }
    const void* data() const { return fData; }

    void* writable_data() { return fData; }

    void ref() const { this->internalRef(false); }
    void unref() const { this->internalUnref(false); }

    int testing_only_getRefCnt() const { return fRefCnt; }
    bool testing_only_isLocked() const { return fIsLocked; }
    bool testing_only_isInCache() const { return fInCache; }

<<<<<<< HEAD
    SkDiscardableMemory* diagnostic_only_getDiscardable() const
    {
        return kDiscardableMemory_StorageType == fStorageType ? fStorage.fDM : nullptr;
    }

protected:
    // called when fData changes. could be nullptr.
    virtual void onDataChange(void* oldData, void* newData) { }

private:
    SkMutex fMutex; // could use a pool of these...
=======
protected:
    // called when fData changes. could be NULL.
    virtual void onDataChange(void* oldData, void* newData) {}

private:
    SkMutex fMutex;     // could use a pool of these...
>>>>>>> miniblink49

    enum StorageType {
        kDiscardableMemory_StorageType,
        kMalloc_StorageType
    };

    union {
<<<<<<< HEAD
        SkDiscardableMemory* fDM;
        void* fMalloc;
    } fStorage;
    void* fData;
    size_t fSize;
    int fRefCnt; // low-bit means we're owned by the cache
    StorageType fStorageType;
    bool fInCache;
    bool fIsLocked;
=======
        SkDiscardableMemory*    fDM;
        void*                   fMalloc;
    } fStorage;
    void*       fData;
    size_t      fSize;
    int         fRefCnt;    // low-bit means we're owned by the cache
    StorageType fStorageType;
    bool        fInCache;
    bool        fIsLocked;
>>>>>>> miniblink49

    void internalRef(bool fromCache) const;
    void internalUnref(bool fromCache) const;

    void inMutexRef(bool fromCache);
<<<<<<< HEAD
    bool inMutexUnref(bool fromCache); // returns true if we should delete "this"
=======
    bool inMutexUnref(bool fromCache);  // returns true if we should delete "this"
>>>>>>> miniblink49
    void inMutexLock();
    void inMutexUnlock();

    // called whenever our fData might change (lock or unlock)
<<<<<<< HEAD
    void setData(void* newData)
    {
=======
    void setData(void* newData) {
>>>>>>> miniblink49
        if (newData != fData) {
            // notify our subclasses of the change
            this->onDataChange(fData, newData);
            fData = newData;
        }
    }

    class AutoMutexWritable;

public:
#ifdef SK_DEBUG
    void validate() const;
#else
<<<<<<< HEAD
    void validate() const
    {
    }
#endif

    /*
=======
    void validate() const {}
#endif

   /*
>>>>>>> miniblink49
     *  Attaching a data to to a SkResourceCache (only one at a time) enables the data to be
     *  unlocked when the cache is the only owner, thus freeing it to be purged (assuming the
     *  data is backed by a SkDiscardableMemory).
     *
     *  When attached, it also automatically attempts to "lock" the data when the first client
     *  ref's the data (typically from a find(key, visitor) call).
     *
     *  Thus the data will always be "locked" when a non-cache has a ref on it (whether or not
<<<<<<< HEAD
     *  the lock succeeded to recover the memory -- check data() to see if it is nullptr).
=======
     *  the lock succeeded to recover the memory -- check data() to see if it is NULL).
>>>>>>> miniblink49
     */

    /*
     *  Call when adding this instance to a SkResourceCache::Rec subclass
     *  (typically in the Rec's constructor).
     */
    void attachToCacheAndRef() const { this->internalRef(true); }

    /*
     *  Call when removing this instance from a SkResourceCache::Rec subclass
     *  (typically in the Rec's destructor).
     */
    void detachFromCacheAndUnref() const { this->internalUnref(true); }
};

#endif
