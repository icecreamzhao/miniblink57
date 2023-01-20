/*
 * Copyright (C) 2006, 2010 Apple Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#ifndef FontFallbackList_h
#define FontFallbackList_h

<<<<<<< HEAD
#include "platform/fonts/FallbackListCompositeKey.h"
#include "platform/fonts/FontCache.h"
#include "platform/fonts/FontSelector.h"
#include "platform/fonts/SimpleFontData.h"
#include "platform/fonts/shaping/ShapeCache.h"
#include "wtf/Allocator.h"
#include "wtf/Forward.h"
#include "wtf/RefCounted.h"
#include "wtf/WeakPtr.h"
=======
#include "platform/fonts/FontSelector.h"
#include "platform/fonts/SimpleFontData.h"
#include "platform/fonts/shaping/CachingWordShaper.h"
#include "wtf/Forward.h"
#include "wtf/MainThread.h"
>>>>>>> miniblink49

namespace blink {

class GlyphPageTreeNodeBase;
class FontDescription;

const int cAllFamiliesScanned = -1;

class PLATFORM_EXPORT FontFallbackList : public RefCounted<FontFallbackList> {
    WTF_MAKE_NONCOPYABLE(FontFallbackList);
<<<<<<< HEAD

=======
>>>>>>> miniblink49
public:
    typedef HashMap<int, GlyphPageTreeNodeBase*, DefaultHash<int>::Hash> GlyphPages;

    class GlyphPagesStateSaver {
<<<<<<< HEAD
        STACK_ALLOCATED();

=======
>>>>>>> miniblink49
    public:
        GlyphPagesStateSaver(FontFallbackList& fallbackList)
            : m_fallbackList(fallbackList)
            , m_pages(fallbackList.m_pages)
            , m_pageZero(fallbackList.m_pageZero)
        {
        }

        ~GlyphPagesStateSaver()
        {
            m_fallbackList.m_pages = m_pages;
            m_fallbackList.m_pageZero = m_pageZero;
        }

    private:
        FontFallbackList& m_fallbackList;
        GlyphPages& m_pages;
        GlyphPageTreeNodeBase* m_pageZero;
    };

    static PassRefPtr<FontFallbackList> create() { return adoptRef(new FontFallbackList()); }

<<<<<<< HEAD
    ~FontFallbackList() { releaseFontData(); }
    bool isValid() const;
    void invalidate(FontSelector*);
=======
    ~FontFallbackList();
    bool isValid() const;
    void invalidate(PassRefPtrWillBeRawPtr<FontSelector>);
>>>>>>> miniblink49

    bool loadingCustomFonts() const;
    bool shouldSkipDrawing() const;

<<<<<<< HEAD
    FontSelector* getFontSelector() const { return m_fontSelector.get(); }
=======
    FontSelector* fontSelector() const { return m_fontSelector.get(); }
>>>>>>> miniblink49
    // FIXME: It should be possible to combine fontSelectorVersion and generation.
    unsigned fontSelectorVersion() const { return m_fontSelectorVersion; }
    unsigned generation() const { return m_generation; }

<<<<<<< HEAD
    ShapeCache* shapeCache(const FontDescription& fontDescription) const
    {
        if (!m_shapeCache) {
            FallbackListCompositeKey key = compositeKey(fontDescription);
            m_shapeCache = FontCache::fontCache()->getShapeCache(key)->weakPtr();
        }
        ASSERT(m_shapeCache);
        if (getFontSelector())
            m_shapeCache->clearIfVersionChanged(getFontSelector()->version());
        return m_shapeCache.get();
    }
=======
    CachingWordShaper& cachingWordShaper() const { return m_cachingWordShaper; }
>>>>>>> miniblink49

    const SimpleFontData* primarySimpleFontData(const FontDescription& fontDescription)
    {
        ASSERT(isMainThread());
<<<<<<< HEAD
        if (!m_cachedPrimarySimpleFontData) {
            m_cachedPrimarySimpleFontData = determinePrimarySimpleFontData(fontDescription);
            ASSERT(m_cachedPrimarySimpleFontData);
        }
=======
        if (!m_cachedPrimarySimpleFontData)
            m_cachedPrimarySimpleFontData = determinePrimarySimpleFontData(fontDescription);
>>>>>>> miniblink49
        return m_cachedPrimarySimpleFontData;
    }
    const FontData* fontDataAt(const FontDescription&, unsigned index) const;

    GlyphPageTreeNodeBase* getPageNode(unsigned pageNumber) const
    {
        return pageNumber ? m_pages.get(pageNumber) : m_pageZero;
    }

    void setPageNode(unsigned pageNumber, GlyphPageTreeNodeBase* node)
    {
        if (pageNumber)
            m_pages.set(pageNumber, node);
        else
            m_pageZero = node;
    }

<<<<<<< HEAD
    FallbackListCompositeKey compositeKey(const FontDescription&) const;

=======
>>>>>>> miniblink49
private:
    FontFallbackList();

    PassRefPtr<FontData> getFontData(const FontDescription&, int& familyIndex) const;

    const SimpleFontData* determinePrimarySimpleFontData(const FontDescription&) const;

    void releaseFontData();

    mutable Vector<RefPtr<FontData>, 1> m_fontList;
    GlyphPages m_pages;
    GlyphPageTreeNodeBase* m_pageZero;
    mutable const SimpleFontData* m_cachedPrimarySimpleFontData;
<<<<<<< HEAD
    Persistent<FontSelector> m_fontSelector;
=======
    RefPtrWillBePersistent<FontSelector> m_fontSelector;
    mutable CachingWordShaper m_cachingWordShaper;
>>>>>>> miniblink49
    unsigned m_fontSelectorVersion;
    mutable int m_familyIndex;
    unsigned short m_generation;
    mutable bool m_hasLoadingFallback : 1;
<<<<<<< HEAD
    mutable WeakPtr<ShapeCache> m_shapeCache;
=======
>>>>>>> miniblink49
};

} // namespace blink

#endif
