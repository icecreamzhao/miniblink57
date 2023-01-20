/*
 * Copyright (C) 2013 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef FontDataCache_h
#define FontDataCache_h

#include "platform/fonts/FontCache.h"
#include "platform/fonts/FontPlatformData.h"
#include "wtf/HashMap.h"
#include "wtf/ListHashSet.h"

namespace blink {

class SimpleFontData;

struct FontDataCacheKeyHash {
<<<<<<< HEAD
    STATIC_ONLY(FontDataCacheKeyHash);
    static unsigned hash(const FontPlatformData* platformData)
    {
        return platformData->hash();
    }

    static bool equal(const FontPlatformData* a, const FontPlatformData* b)
    {
        const FontPlatformData* emptyValue = reinterpret_cast<FontPlatformData*>(-1);

        if (a == emptyValue)
            return b == emptyValue;
        if (b == emptyValue)
            return a == emptyValue;

        if (!a || !b)
            return a == b;

        CHECK(a && b);

        return *a == *b;
=======
    static unsigned hash(const FontPlatformData& platformData)
    {
        return platformData.hash();
    }

    static bool equal(const FontPlatformData& a, const FontPlatformData& b)
    {
        return a == b;
>>>>>>> miniblink49
    }

    static const bool safeToCompareToEmptyOrDeleted = true;
};

<<<<<<< HEAD
class FontDataCache {
    USING_FAST_MALLOC(FontDataCache);
    WTF_MAKE_NONCOPYABLE(FontDataCache);

public:
    FontDataCache() { }

=======
struct FontDataCacheKeyTraits : WTF::GenericHashTraits<FontPlatformData> {
    static const bool emptyValueIsZero = true;
    static const FontPlatformData& emptyValue()
    {
        DEFINE_STATIC_LOCAL(FontPlatformData, key, (0.f, false, false));
        return key;
    }
    static void constructDeletedValue(FontPlatformData& slot, bool)
    {
        new (NotNull, &slot) FontPlatformData(WTF::HashTableDeletedValue);
    }
    static bool isDeletedValue(const FontPlatformData& value)
    {
        return value.isHashTableDeletedValue();
    }
};

class FontDataCache {
public:
>>>>>>> miniblink49
    PassRefPtr<SimpleFontData> get(const FontPlatformData*, ShouldRetain = Retain);
    bool contains(const FontPlatformData*) const;
    void release(const SimpleFontData*);

    // This is used by FontVerticalDataCache to mark all items with vertical data
    // that are currently in cache as "in cache", which is later used to sweep the FontVerticalDataCache.
    void markAllVerticalData();

    // Purges items in FontDataCache according to provided severity.
    // Returns true if any removal of cache items actually occurred.
    bool purge(PurgeSeverity);

private:
    bool purgeLeastRecentlyUsed(int count);

<<<<<<< HEAD
    typedef HashMap<const FontPlatformData*, std::pair<RefPtr<SimpleFontData>, unsigned>, FontDataCacheKeyHash> Cache;
=======
    typedef HashMap<FontPlatformData, pair<RefPtr<SimpleFontData>, unsigned>, FontDataCacheKeyHash, FontDataCacheKeyTraits> Cache;
>>>>>>> miniblink49
    Cache m_cache;
    ListHashSet<RefPtr<SimpleFontData>> m_inactiveFontData;
};

} // namespace blink

#endif
