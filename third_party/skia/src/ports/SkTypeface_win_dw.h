/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkTypeface_win_dw_DEFINED
#define SkTypeface_win_dw_DEFINED

#include "SkAdvancedTypefaceMetrics.h"
#include "SkDWrite.h"
#include "SkHRESULT.h"
<<<<<<< HEAD
#include "SkLeanWindows.h"
#include "SkTScopedComPtr.h"
#include "SkTypeface.h"
#include "SkTypefaceCache.h"

#include <dwrite.h>
#if SK_HAS_DWRITE_1_H
#include <dwrite_1.h>
=======
#include "SkTScopedComPtr.h"
#include "SkTypeface.h"
#include "SkTypefaceCache.h"
#include "SkTypes.h"

#include <dwrite.h>
#if SK_HAS_DWRITE_1_H
#  include <dwrite_1.h>
>>>>>>> miniblink49
#endif

class SkFontDescriptor;
struct SkScalerContextRec;

<<<<<<< HEAD
static SkFontStyle get_style(IDWriteFont* font)
{
    int weight = font->GetWeight();
    int width = font->GetStretch();
    SkFontStyle::Slant slant = SkFontStyle::kUpright_Slant;
    switch (font->GetStyle()) {
    case DWRITE_FONT_STYLE_NORMAL:
        slant = SkFontStyle::kUpright_Slant;
        break;
    case DWRITE_FONT_STYLE_OBLIQUE:
        slant = SkFontStyle::kOblique_Slant;
        break;
    case DWRITE_FONT_STYLE_ITALIC:
        slant = SkFontStyle::kItalic_Slant;
        break;
    default:
        SkASSERT(false);
        break;
    }
    return SkFontStyle(weight, width, slant);
=======
static SkFontStyle get_style(IDWriteFont* font) {
    DWRITE_FONT_STYLE dwStyle = font->GetStyle();
    return SkFontStyle(font->GetWeight(),
                       font->GetStretch(),
                       (DWRITE_FONT_STYLE_OBLIQUE == dwStyle ||
                        DWRITE_FONT_STYLE_ITALIC  == dwStyle)
                                                   ? SkFontStyle::kItalic_Slant
                                                   : SkFontStyle::kUpright_Slant);
>>>>>>> miniblink49
}

class DWriteFontTypeface : public SkTypeface {
private:
    DWriteFontTypeface(const SkFontStyle& style, SkFontID fontID,
<<<<<<< HEAD
        IDWriteFactory* factory,
        IDWriteFontFace* fontFace,
        IDWriteFont* font,
        IDWriteFontFamily* fontFamily,
        IDWriteFontFileLoader* fontFileLoader = nullptr,
        IDWriteFontCollectionLoader* fontCollectionLoader = nullptr)
=======
                       IDWriteFactory* factory,
                       IDWriteFontFace* fontFace,
                       IDWriteFont* font,
                       IDWriteFontFamily* fontFamily,
                       IDWriteFontFileLoader* fontFileLoader = NULL,
                       IDWriteFontCollectionLoader* fontCollectionLoader = NULL)
>>>>>>> miniblink49
        : SkTypeface(style, fontID, false)
        , fFactory(SkRefComPtr(factory))
        , fDWriteFontCollectionLoader(SkSafeRefComPtr(fontCollectionLoader))
        , fDWriteFontFileLoader(SkSafeRefComPtr(fontFileLoader))
        , fDWriteFontFamily(SkRefComPtr(fontFamily))
        , fDWriteFont(SkRefComPtr(font))
        , fDWriteFontFace(SkRefComPtr(fontFace))
    {
#if SK_HAS_DWRITE_1_H
        if (!SUCCEEDED(fDWriteFontFace->QueryInterface(&fDWriteFontFace1))) {
<<<<<<< HEAD
            // IUnknown::QueryInterface states that if it fails, punk will be set to nullptr.
            // http://blogs.msdn.com/b/oldnewthing/archive/2004/03/26/96777.aspx
            SkASSERT_RELEASE(nullptr == fDWriteFontFace1.get());
=======
            // IUnknown::QueryInterface states that if it fails, punk will be set to NULL.
            // http://blogs.msdn.com/b/oldnewthing/archive/2004/03/26/96777.aspx
            SK_ALWAYSBREAK(NULL == fDWriteFontFace1.get());
>>>>>>> miniblink49
        }
#endif
    }

public:
    SkTScopedComPtr<IDWriteFactory> fFactory;
    SkTScopedComPtr<IDWriteFontCollectionLoader> fDWriteFontCollectionLoader;
    SkTScopedComPtr<IDWriteFontFileLoader> fDWriteFontFileLoader;
    SkTScopedComPtr<IDWriteFontFamily> fDWriteFontFamily;
    SkTScopedComPtr<IDWriteFont> fDWriteFont;
    SkTScopedComPtr<IDWriteFontFace> fDWriteFontFace;
#if SK_HAS_DWRITE_1_H
    SkTScopedComPtr<IDWriteFontFace1> fDWriteFontFace1;
#endif

    static DWriteFontTypeface* Create(IDWriteFactory* factory,
<<<<<<< HEAD
        IDWriteFontFace* fontFace,
        IDWriteFont* font,
        IDWriteFontFamily* fontFamily,
        IDWriteFontFileLoader* fontFileLoader = nullptr,
        IDWriteFontCollectionLoader* fontCollectionLoader = nullptr)
    {
        SkFontID fontID = SkTypefaceCache::NewFontID();
        return new DWriteFontTypeface(get_style(font), fontID, factory, fontFace, font, fontFamily,
            fontFileLoader, fontCollectionLoader);
    }

protected:
    void weak_dispose() const override
    {
=======
                                      IDWriteFontFace* fontFace,
                                      IDWriteFont* font,
                                      IDWriteFontFamily* fontFamily,
                                      IDWriteFontFileLoader* fontFileLoader = NULL,
                                      IDWriteFontCollectionLoader* fontCollectionLoader = NULL) {
        SkFontID fontID = SkTypefaceCache::NewFontID();
        return SkNEW_ARGS(DWriteFontTypeface, (get_style(font), fontID,
                                               factory, fontFace, font, fontFamily,
                                               fontFileLoader, fontCollectionLoader));
    }

protected:
    void weak_dispose() const override {
>>>>>>> miniblink49
        if (fDWriteFontCollectionLoader.get()) {
            HRV(fFactory->UnregisterFontCollectionLoader(fDWriteFontCollectionLoader.get()));
        }
        if (fDWriteFontFileLoader.get()) {
            HRV(fFactory->UnregisterFontFileLoader(fDWriteFontFileLoader.get()));
        }

        //SkTypefaceCache::Remove(this);
        INHERITED::weak_dispose();
    }

    SkStreamAsset* onOpenStream(int* ttcIndex) const override;
<<<<<<< HEAD
    SkScalerContext* onCreateScalerContext(const SkScalerContextEffects&,
        const SkDescriptor*) const override;
    void onFilterRec(SkScalerContextRec*) const override;
    SkAdvancedTypefaceMetrics* onGetAdvancedTypefaceMetrics(
        PerGlyphInfo, const uint32_t*, uint32_t) const override;
    void onGetFontDescriptor(SkFontDescriptor*, bool*) const override;
    virtual int onCharsToGlyphs(const void* chars, Encoding encoding,
        uint16_t glyphs[], int glyphCount) const override;
=======
    SkScalerContext* onCreateScalerContext(const SkDescriptor*) const override;
    void onFilterRec(SkScalerContextRec*) const override;
    SkAdvancedTypefaceMetrics* onGetAdvancedTypefaceMetrics(
                                PerGlyphInfo, const uint32_t*, uint32_t) const override;
    void onGetFontDescriptor(SkFontDescriptor*, bool*) const override;
    virtual int onCharsToGlyphs(const void* chars, Encoding encoding,
                                uint16_t glyphs[], int glyphCount) const override;
>>>>>>> miniblink49
    int onCountGlyphs() const override;
    int onGetUPEM() const override;
    void onGetFamilyName(SkString* familyName) const override;
    SkTypeface::LocalizedStrings* onCreateFamilyNameIterator() const override;
    int onGetTableTags(SkFontTableTag tags[]) const override;
    virtual size_t onGetTableData(SkFontTableTag, size_t offset,
<<<<<<< HEAD
        size_t length, void* data) const override;
=======
                                  size_t length, void* data) const override;
>>>>>>> miniblink49

private:
    typedef SkTypeface INHERITED;
};

#endif
