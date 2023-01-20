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
=======


>>>>>>> miniblink49
#include "SkTypefaceCache.h"
#include "SkAtomics.h"
#include "SkMutex.h"

<<<<<<< HEAD
#define TYPEFACE_CACHE_LIMIT 1024

SkTypefaceCache::SkTypefaceCache() { }

void SkTypefaceCache::add(SkTypeface* face)
{
    if (fTypefaces.count() >= TYPEFACE_CACHE_LIMIT) {
        this->purge(TYPEFACE_CACHE_LIMIT >> 2);
    }

    fTypefaces.emplace_back(SkRef(face));
}

SkTypeface* SkTypefaceCache::findByProcAndRef(FindProc proc, void* ctx) const
{
    for (const sk_sp<SkTypeface>& typeface : fTypefaces) {
        if (proc(typeface.get(), ctx)) {
            return SkRef(typeface.get());
        }
    }
    return nullptr;
}

void SkTypefaceCache::purge(int numToPurge)
{
    int count = fTypefaces.count();
    int i = 0;
    while (i < count) {
        if (fTypefaces[i]->unique()) {
            fTypefaces.removeShuffle(i);
=======
#define TYPEFACE_CACHE_LIMIT    1024

SkTypefaceCache::SkTypefaceCache() {}

SkTypefaceCache::~SkTypefaceCache() {
    const Rec* curr = fArray.begin();
    const Rec* stop = fArray.end();
    while (curr < stop) {
        curr->fFace->unref();
        curr += 1;
    }
}

void SkTypefaceCache::add(SkTypeface* face, const SkFontStyle& requestedStyle) {
    if (fArray.count() >= TYPEFACE_CACHE_LIMIT) {
        this->purge(TYPEFACE_CACHE_LIMIT >> 2);
    }

    Rec* rec = fArray.append();
    rec->fFace = SkRef(face);
    rec->fRequestedStyle = requestedStyle;
}

SkTypeface* SkTypefaceCache::findByProcAndRef(FindProc proc, void* ctx) const {
    const Rec* curr = fArray.begin();
    const Rec* stop = fArray.end();
    while (curr < stop) {
        SkTypeface* currFace = curr->fFace;
        if (proc(currFace, curr->fRequestedStyle, ctx)) {
            return SkRef(currFace);
        }
        curr += 1;
    }
    return NULL;
}

void SkTypefaceCache::purge(int numToPurge) {
    int count = fArray.count();
    int i = 0;
    while (i < count) {
        SkTypeface* face = fArray[i].fFace;
        if (face->unique()) {
            face->unref();
            fArray.remove(i);
>>>>>>> miniblink49
            --count;
            if (--numToPurge == 0) {
                return;
            }
        } else {
            ++i;
        }
    }
}

<<<<<<< HEAD
void SkTypefaceCache::purgeAll()
{
    this->purge(fTypefaces.count());
=======
void SkTypefaceCache::purgeAll() {
    this->purge(fArray.count());
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkTypefaceCache& SkTypefaceCache::Get()
{
=======
SkTypefaceCache& SkTypefaceCache::Get() {
>>>>>>> miniblink49
    static SkTypefaceCache gCache;
    return gCache;
}

<<<<<<< HEAD
SkFontID SkTypefaceCache::NewFontID()
{
=======
SkFontID SkTypefaceCache::NewFontID() {
>>>>>>> miniblink49
    static int32_t gFontID;
    return sk_atomic_inc(&gFontID) + 1;
}

SK_DECLARE_STATIC_MUTEX(gMutex);

<<<<<<< HEAD
void SkTypefaceCache::Add(SkTypeface* face)
{
    SkAutoMutexAcquire ama(gMutex);
    Get().add(face);
}

SkTypeface* SkTypefaceCache::FindByProcAndRef(FindProc proc, void* ctx)
{
    SkAutoMutexAcquire ama(gMutex);
    return Get().findByProcAndRef(proc, ctx);
}

void SkTypefaceCache::PurgeAll()
{
=======
void SkTypefaceCache::Add(SkTypeface* face, const SkFontStyle& requestedStyle) {
    SkAutoMutexAcquire ama(gMutex);
    Get().add(face, requestedStyle);
}

SkTypeface* SkTypefaceCache::FindByProcAndRef(FindProc proc, void* ctx) {
    SkAutoMutexAcquire ama(gMutex);
    SkTypeface* typeface = Get().findByProcAndRef(proc, ctx);
    return typeface;
}

void SkTypefaceCache::PurgeAll() {
>>>>>>> miniblink49
    SkAutoMutexAcquire ama(gMutex);
    Get().purgeAll();
}

///////////////////////////////////////////////////////////////////////////////

#ifdef SK_DEBUG
<<<<<<< HEAD
static bool DumpProc(SkTypeface* face, void* ctx)
{
    SkString n;
    face->getFamilyName(&n);
    SkFontStyle s = face->fontStyle();
    SkFontID id = face->uniqueID();
    SkDebugf("SkTypefaceCache: face %p fontID %d weight %d width %d style %d refcnt %d name %s\n",
        face, id, s.weight(), s.width(), s.slant(), face->getRefCnt(), n.c_str());
=======
static bool DumpProc(SkTypeface* face, const SkFontStyle& s, void* ctx) {
    SkDebugf("SkTypefaceCache: face %p fontID %d weight %d width %d style %d refcnt %d\n",
             face, face->uniqueID(), s.weight(), s.width(), s.slant(), face->getRefCnt());
>>>>>>> miniblink49
    return false;
}
#endif

<<<<<<< HEAD
void SkTypefaceCache::Dump()
{
#ifdef SK_DEBUG
    (void)Get().findByProcAndRef(DumpProc, nullptr);
=======
void SkTypefaceCache::Dump() {
#ifdef SK_DEBUG
    SkAutoMutexAcquire ama(gMutex);
    (void)Get().findByProcAndRef(DumpProc, NULL);
>>>>>>> miniblink49
#endif
}
