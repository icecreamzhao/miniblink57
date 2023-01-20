<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#ifndef SkTypefaceCache_DEFINED
#define SkTypefaceCache_DEFINED

#include "SkRefCnt.h"
#include "SkTArray.h"
#include "SkTypeface.h"
=======


#ifndef SkTypefaceCache_DEFINED
#define SkTypefaceCache_DEFINED

#include "SkTypeface.h"
#include "SkTDArray.h"

/*  TODO
 *  Provide std way to cache name+requestedStyle aliases to the same typeface.
 *
 *  The current mechanism ends up create a diff typeface for each one, even if
 *  they map to the same internal obj (e.g. CTFontRef on the mac)
 */
>>>>>>> miniblink49

class SkTypefaceCache {
public:
    SkTypefaceCache();
<<<<<<< HEAD
=======
    ~SkTypefaceCache();
>>>>>>> miniblink49

    /**
     * Callback for FindByProc. Returns true if the given typeface is a match
     * for the given context. The passed typeface is owned by the cache and is
     * not additionally ref()ed. The typeface may be in the disposed state.
     */
<<<<<<< HEAD
    typedef bool (*FindProc)(SkTypeface*, void* context);
=======
    typedef bool(*FindProc)(SkTypeface*, const SkFontStyle&, void* context);
>>>>>>> miniblink49

    /**
     *  Add a typeface to the cache. This ref()s the typeface, so that the
     *  cache is also an owner. Later, if we need to purge the cache, typefaces
     *  whose refcnt is 1 (meaning only the cache is an owner) will be
     *  unref()ed.
     */
<<<<<<< HEAD
    void add(SkTypeface*);
=======
    void add(SkTypeface*, const SkFontStyle& requested);
>>>>>>> miniblink49

    /**
     *  Iterate through the cache, calling proc(typeface, ctx) with each
     *  typeface. If proc returns true, then we return that typeface (this
<<<<<<< HEAD
     *  ref()s the typeface). If it never returns true, we return nullptr.
=======
     *  ref()s the typeface). If it never returns true, we return NULL.
>>>>>>> miniblink49
     */
    SkTypeface* findByProcAndRef(FindProc proc, void* ctx) const;

    /**
     *  This will unref all of the typefaces in the cache for which the cache
     *  is the only owner. Normally this is handled automatically as needed.
     *  This function is exposed for clients that explicitly want to purge the
     *  cache (e.g. to look for leaks).
     */
    void purgeAll();

    /**
     *  Helper: returns a unique fontID to pass to the constructor of
     *  your subclass of SkTypeface
     */
    static SkFontID NewFontID();

    // These are static wrappers around a global instance of a cache.

<<<<<<< HEAD
    static void Add(SkTypeface*);
=======
    static void Add(SkTypeface*, const SkFontStyle& requested);
>>>>>>> miniblink49
    static SkTypeface* FindByProcAndRef(FindProc proc, void* ctx);
    static void PurgeAll();

    /**
     *  Debugging only: dumps the status of the typefaces in the cache
     */
    static void Dump();

private:
    static SkTypefaceCache& Get();

    void purge(int count);

<<<<<<< HEAD
    SkTArray<sk_sp<SkTypeface>> fTypefaces;
=======
    struct Rec {
        SkTypeface* fFace;
        SkFontStyle fRequestedStyle;
    };
    SkTDArray<Rec> fArray;
>>>>>>> miniblink49
};

#endif
