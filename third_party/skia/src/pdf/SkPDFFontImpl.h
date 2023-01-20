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
#ifndef SkPDFFontImpl_DEFINED
#define SkPDFFontImpl_DEFINED

#include "SkPDFFont.h"

<<<<<<< HEAD
class SkPDFType0Font final : public SkPDFFont {
public:
    virtual ~SkPDFType0Font();
    bool multiByteGlyphs() const override { return true; }
    SkPDFFont* getFontSubset(const SkPDFGlyphSet* usage) override;
#ifdef SK_DEBUG
    void emitObject(SkWStream*,
        const SkPDFObjNumMap&,
        const SkPDFSubstituteMap&) const override;
#endif

private:
    friend class SkPDFFont; // to access the constructor
=======
class SkPDFType0Font : public SkPDFFont {
public:
    virtual ~SkPDFType0Font();
    virtual bool multiByteGlyphs() const { return true; }
    virtual SkPDFFont* getFontSubset(const SkPDFGlyphSet* usage);
#ifdef SK_DEBUG
    virtual void emitObject(SkWStream*,
                            const SkPDFObjNumMap&,
                            const SkPDFSubstituteMap&);
#endif

private:
    friend class SkPDFFont;  // to access the constructor
>>>>>>> miniblink49
#ifdef SK_DEBUG
    bool fPopulated;
    typedef SkPDFDict INHERITED;
#endif

    SkPDFType0Font(const SkAdvancedTypefaceMetrics* info,
<<<<<<< HEAD
        SkTypeface* typeface);
=======
                   SkTypeface* typeface);
>>>>>>> miniblink49

    bool populate(const SkPDFGlyphSet* subset);
};

<<<<<<< HEAD
class SkPDFCIDFont final : public SkPDFFont {
=======
class SkPDFCIDFont : public SkPDFFont {
>>>>>>> miniblink49
public:
    virtual ~SkPDFCIDFont();
    virtual bool multiByteGlyphs() const { return true; }

private:
<<<<<<< HEAD
    friend class SkPDFType0Font; // to access the constructor

    SkPDFCIDFont(const SkAdvancedTypefaceMetrics* info,
        SkTypeface* typeface,
        const SkPDFGlyphSet* subset);

    bool populate(const SkPDFGlyphSet* subset);
    bool addFontDescriptor(int16_t defaultWidth,
        const SkTDArray<uint32_t>* subset);
};

class SkPDFType1Font final : public SkPDFFont {
=======
    friend class SkPDFType0Font;  // to access the constructor

    SkPDFCIDFont(const SkAdvancedTypefaceMetrics* info,
                 SkTypeface* typeface,
                 const SkPDFGlyphSet* subset);

    bool populate(const SkPDFGlyphSet* subset);
    bool addFontDescriptor(int16_t defaultWidth,
                           const SkTDArray<uint32_t>* subset);
};

class SkPDFType1Font : public SkPDFFont {
>>>>>>> miniblink49
public:
    virtual ~SkPDFType1Font();
    virtual bool multiByteGlyphs() const { return false; }

private:
<<<<<<< HEAD
    friend class SkPDFFont; // to access the constructor

    SkPDFType1Font(const SkAdvancedTypefaceMetrics* info,
        SkTypeface* typeface,
        uint16_t glyphID,
        SkPDFDict* relatedFontDescriptor);
=======
    friend class SkPDFFont;  // to access the constructor

    SkPDFType1Font(const SkAdvancedTypefaceMetrics* info,
                   SkTypeface* typeface,
                   uint16_t glyphID,
                   SkPDFDict* relatedFontDescriptor);
>>>>>>> miniblink49

    bool populate(int16_t glyphID);
    bool addFontDescriptor(int16_t defaultWidth);
    void addWidthInfoFromRange(int16_t defaultWidth,
        const SkAdvancedTypefaceMetrics::WidthRange* widthRangeEntry);
};

<<<<<<< HEAD
class SkPDFType3Font final : public SkPDFFont {
=======
class SkPDFType3Font : public SkPDFFont {
>>>>>>> miniblink49
public:
    virtual ~SkPDFType3Font();
    virtual bool multiByteGlyphs() const { return false; }

private:
<<<<<<< HEAD
    friend class SkPDFFont; // to access the constructor

    SkPDFType3Font(const SkAdvancedTypefaceMetrics* info,
        SkTypeface* typeface,
        uint16_t glyphID);
=======
    friend class SkPDFFont;  // to access the constructor

    SkPDFType3Font(const SkAdvancedTypefaceMetrics* info,
                   SkTypeface* typeface,
                   uint16_t glyphID);
>>>>>>> miniblink49

    bool populate(uint16_t glyphID);
};

#endif
