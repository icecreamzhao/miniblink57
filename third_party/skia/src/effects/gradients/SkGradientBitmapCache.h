<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2010 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkGradientBitmapCache_DEFINED
#define SkGradientBitmapCache_DEFINED

#include "SkBitmap.h"

class SkGradientBitmapCache : SkNoncopyable {
public:
    SkGradientBitmapCache(int maxEntries);
    ~SkGradientBitmapCache();

    bool find(const void* buffer, size_t len, SkBitmap*) const;
    void add(const void* buffer, size_t len, const SkBitmap&);

private:
    int fEntryCount;
    const int fMaxEntries;

    struct Entry;
<<<<<<< HEAD
    mutable Entry* fHead;
    mutable Entry* fTail;

    inline Entry* release(Entry*) const;
=======
    mutable Entry*  fHead;
    mutable Entry*  fTail;

    inline Entry* detach(Entry*) const;
>>>>>>> miniblink49
    inline void attachToHead(Entry*) const;

#ifdef SK_DEBUG
    void validate() const;
#else
<<<<<<< HEAD
    void validate() const
    {
    }
=======
    void validate() const {}
>>>>>>> miniblink49
#endif

    class AutoValidate : SkNoncopyable {
    public:
<<<<<<< HEAD
        AutoValidate(const SkGradientBitmapCache* bc)
            : fBC(bc)
        {
            bc->validate();
        }
        ~AutoValidate() { fBC->validate(); }

=======
        AutoValidate(const SkGradientBitmapCache* bc) : fBC(bc) { bc->validate(); }
        ~AutoValidate() { fBC->validate(); }
>>>>>>> miniblink49
    private:
        const SkGradientBitmapCache* fBC;
    };
};

#endif
