/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkTestScalerContext_DEFINED
#define SkTestScalerContext_DEFINED

<<<<<<< HEAD
#include "SkFixed.h"
=======
>>>>>>> miniblink49
#include "SkPaint.h"
#include "SkPath.h"
#include "SkRefCnt.h"
#include "SkTDArray.h"
#include "SkTypeface.h"

class SkTestFont;

struct SkTestFontData {
    const SkScalar* fPoints;
    const unsigned char* fVerbs;
    const unsigned* fCharCodes;
    const size_t fCharCodesCount;
    const SkFixed* fWidths;
    const SkPaint::FontMetrics& fMetrics;
    const char* fName;
    SkTypeface::Style fStyle;
    SkTestFont* fFontCache;
};

class SkTestFont : public SkRefCnt {
public:
<<<<<<< HEAD
    SkTestFont(const SkTestFontData&);
    virtual ~SkTestFont();
    int codeToIndex(SkUnichar charCode) const;
    void init(const SkScalar* pts, const unsigned char* verbs);
#ifdef SK_DEBUG // detect missing test font data
    mutable unsigned char fDebugBits[16];
    mutable SkUnichar fDebugOverage[8];
    const char* fDebugName;
    SkFontStyle fDebugStyle;
=======
    

    SkTestFont(const SkTestFontData& );
    virtual ~SkTestFont();
    int codeToIndex(SkUnichar charCode) const;
    void init(const SkScalar* pts, const unsigned char* verbs);
#ifdef SK_DEBUG  // detect missing test font data
    mutable unsigned char fDebugBits[16];
    mutable SkUnichar fDebugOverage[8];
    const char* fDebugName;
    SkTypeface::Style fDebugStyle;
>>>>>>> miniblink49
    const char* debugFontName() const { return fName; }
#endif
private:
    const unsigned* fCharCodes;
    const size_t fCharCodesCount;
    const SkFixed* fWidths;
    const SkPaint::FontMetrics& fMetrics;
    const char* fName;
    SkPath** fPaths;
    friend class SkTestTypeface;
    typedef SkRefCnt INHERITED;
};

<<<<<<< HEAD
class SkTestTypeface : public SkTypeface {
public:
    SkTestTypeface(SkTestFont*, const SkFontStyle& style);
    virtual ~SkTestTypeface()
    {
=======

class SkTestTypeface : public SkTypeface {
public:
    SkTestTypeface(SkTestFont*, const SkFontStyle& style);
    virtual ~SkTestTypeface() {
>>>>>>> miniblink49
        SkSafeUnref(fTestFont);
    }
    void getAdvance(SkGlyph* glyph);
    void getFontMetrics(SkPaint::FontMetrics* metrics);
    void getMetrics(SkGlyph* glyph);
    void getPath(const SkGlyph& glyph, SkPath* path);
<<<<<<< HEAD

protected:
    SkScalerContext* onCreateScalerContext(const SkScalerContextEffects&,
        const SkDescriptor* desc) const override;
=======
protected:
    SkScalerContext* onCreateScalerContext(const SkDescriptor* desc) const override;
>>>>>>> miniblink49
    void onFilterRec(SkScalerContextRec* rec) const override;
    SkAdvancedTypefaceMetrics* onGetAdvancedTypefaceMetrics(
        PerGlyphInfo,
        const uint32_t* glyphIDs,
        uint32_t glyphIDsCount) const override;

<<<<<<< HEAD
    SkStreamAsset* onOpenStream(int* ttcIndex) const override
    {
        return nullptr;
=======
    SkStreamAsset* onOpenStream(int* ttcIndex) const override {
        return NULL;
>>>>>>> miniblink49
    }

    void onGetFontDescriptor(SkFontDescriptor* desc, bool* isLocal) const override;

    int onCharsToGlyphs(const void* chars, Encoding encoding,
<<<<<<< HEAD
        uint16_t glyphs[], int glyphCount) const override;

    int onCountGlyphs() const override
    {
        return (int)fTestFont->fCharCodesCount;
    }

    int onGetUPEM() const override
    {
        SkASSERT(0); // don't expect to get here
=======
                        uint16_t glyphs[], int glyphCount) const override;

    int onCountGlyphs() const override {
        return (int) fTestFont->fCharCodesCount;
    }

    int onGetUPEM() const override {
        SkASSERT(0);  // don't expect to get here
>>>>>>> miniblink49
        return 1;
    }

    void onGetFamilyName(SkString* familyName) const override;
    SkTypeface::LocalizedStrings* onCreateFamilyNameIterator() const override;

<<<<<<< HEAD
    int onGetTableTags(SkFontTableTag tags[]) const override
    {
=======
    int onGetTableTags(SkFontTableTag tags[]) const override {
>>>>>>> miniblink49
        return 0;
    }

    size_t onGetTableData(SkFontTableTag tag, size_t offset,
<<<<<<< HEAD
        size_t length, void* data) const override
    {
        return 0;
    }

=======
                          size_t length, void* data) const override {
        return 0;
    }
>>>>>>> miniblink49
private:
    SkTestFont* fTestFont;
    friend class SkTestScalerContext;
};

SkTypeface* CreateTestTypeface(const char* name, SkTypeface::Style style);

#endif
