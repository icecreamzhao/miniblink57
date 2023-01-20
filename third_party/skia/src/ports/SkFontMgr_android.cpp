/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkTypes.h"

#include "SkData.h"
#include "SkFixed.h"
=======
>>>>>>> miniblink49
#include "SkFontDescriptor.h"
#include "SkFontHost_FreeType_common.h"
#include "SkFontMgr.h"
#include "SkFontMgr_android.h"
#include "SkFontMgr_android_parser.h"
#include "SkFontStyle.h"
<<<<<<< HEAD
#include "SkOSFile.h"
#include "SkPaint.h"
#include "SkRefCnt.h"
#include "SkStream.h"
#include "SkString.h"
#include "SkTArray.h"
#include "SkTDArray.h"
#include "SkTSearch.h"
#include "SkTemplates.h"
=======
#include "SkStream.h"
#include "SkTDArray.h"
#include "SkTSearch.h"
#include "SkTypeface.h"
>>>>>>> miniblink49
#include "SkTypefaceCache.h"

#include <limits>

<<<<<<< HEAD
class SkData;

class SkTypeface_Android : public SkTypeface_FreeType {
public:
    SkTypeface_Android(const SkFontStyle& style,
        bool isFixedPitch,
        const SkString& familyName)
        : INHERITED(style, SkTypefaceCache::NewFontID(), isFixedPitch)
        , fFamilyName(familyName)
    {
    }

protected:
    void onGetFamilyName(SkString* familyName) const override
    {
=======
class SkTypeface_Android : public SkTypeface_FreeType {
public:
    SkTypeface_Android(const SkFontStyle& style,
                       bool isFixedPitch,
                       const SkString& familyName)
        : INHERITED(style, SkTypefaceCache::NewFontID(), isFixedPitch)
        , fFamilyName(familyName)
        { }

protected:
    void onGetFamilyName(SkString* familyName) const override {
>>>>>>> miniblink49
        *familyName = fFamilyName;
    }

    SkString fFamilyName;

private:
    typedef SkTypeface_FreeType INHERITED;
};

class SkTypeface_AndroidSystem : public SkTypeface_Android {
public:
    SkTypeface_AndroidSystem(const SkString& pathName,
<<<<<<< HEAD
        const bool cacheFontFiles,
        int index,
        const SkFixed* axes, int axesCount,
        const SkFontStyle& style,
        bool isFixedPitch,
        const SkString& familyName,
        const SkLanguage& lang,
        FontVariant variantStyle)
=======
                             int index,
                             const SkFixed* axes, int axesCount,
                             const SkFontStyle& style,
                             bool isFixedPitch,
                             const SkString& familyName,
                             const SkLanguage& lang,
                             FontVariant variantStyle)
>>>>>>> miniblink49
        : INHERITED(style, isFixedPitch, familyName)
        , fPathName(pathName)
        , fIndex(index)
        , fAxes(axes, axesCount)
        , fLang(lang)
<<<<<<< HEAD
        , fVariantStyle(variantStyle)
        , fFile(cacheFontFiles ? sk_fopen(fPathName.c_str(), kRead_SkFILE_Flag) : nullptr)
    {
        if (cacheFontFiles) {
            SkASSERT(fFile);
        }
    }

    SkStreamAsset* createStream() const
    {
        if (fFile) {
            SkData* data = SkData::NewFromFILE(fFile);
            return data ? new SkMemoryStream(data) : nullptr;
        }
        return SkStream::NewFromFile(fPathName.c_str());
    }

    virtual void onGetFontDescriptor(SkFontDescriptor* desc, bool* serialize) const override
    {
=======
        , fVariantStyle(variantStyle) { }

    virtual void onGetFontDescriptor(SkFontDescriptor* desc, bool* serialize) const override {
>>>>>>> miniblink49
        SkASSERT(desc);
        SkASSERT(serialize);
        desc->setFamilyName(fFamilyName.c_str());
        *serialize = false;
    }
<<<<<<< HEAD
    SkStreamAsset* onOpenStream(int* ttcIndex) const override
    {
        *ttcIndex = fIndex;
        return this->createStream();
    }
    SkFontData* onCreateFontData() const override
    {
        return new SkFontData(this->createStream(), fIndex, fAxes.begin(), fAxes.count());
=======
    SkStreamAsset* onOpenStream(int* ttcIndex) const override {
        *ttcIndex = fIndex;
        return SkStream::NewFromFile(fPathName.c_str());
    }
    SkFontData* onCreateFontData() const override {
        return new SkFontData(SkStream::NewFromFile(fPathName.c_str()), fIndex,
                              fAxes.begin(), fAxes.count());
>>>>>>> miniblink49
    }

    const SkString fPathName;
    int fIndex;
    const SkSTArray<4, SkFixed, true> fAxes;
    const SkLanguage fLang;
    const FontVariant fVariantStyle;
<<<<<<< HEAD
    SkAutoTCallVProc<FILE, sk_fclose> fFile;
=======
>>>>>>> miniblink49

    typedef SkTypeface_Android INHERITED;
};

class SkTypeface_AndroidStream : public SkTypeface_Android {
public:
    SkTypeface_AndroidStream(SkFontData* data,
<<<<<<< HEAD
        const SkFontStyle& style,
        bool isFixedPitch,
        const SkString& familyName)
        : INHERITED(style, isFixedPitch, familyName)
        , fData(data)
    {
    }

    virtual void onGetFontDescriptor(SkFontDescriptor* desc,
        bool* serialize) const override
    {
=======
                             const SkFontStyle& style,
                             bool isFixedPitch,
                             const SkString& familyName)
        : INHERITED(style, isFixedPitch, familyName)
        , fData(data)
    { }

    virtual void onGetFontDescriptor(SkFontDescriptor* desc,
                                     bool* serialize) const override {
>>>>>>> miniblink49
        SkASSERT(desc);
        SkASSERT(serialize);
        desc->setFamilyName(fFamilyName.c_str());
        *serialize = true;
    }

<<<<<<< HEAD
    SkStreamAsset* onOpenStream(int* ttcIndex) const override
    {
=======
    SkStreamAsset* onOpenStream(int* ttcIndex) const override {
>>>>>>> miniblink49
        *ttcIndex = fData->getIndex();
        return fData->duplicateStream();
    }

<<<<<<< HEAD
    SkFontData* onCreateFontData() const override
    {
=======
    SkFontData* onCreateFontData() const override {
>>>>>>> miniblink49
        return new SkFontData(*fData.get());
    }

private:
    const SkAutoTDelete<const SkFontData> fData;
    typedef SkTypeface_Android INHERITED;
};

class SkFontStyleSet_Android : public SkFontStyleSet {
    typedef SkTypeface_FreeType::Scanner Scanner;

public:
<<<<<<< HEAD
    explicit SkFontStyleSet_Android(const FontFamily& family, const Scanner& scanner,
        const bool cacheFontFiles)
    {
        const SkString* cannonicalFamilyName = nullptr;
=======
    explicit SkFontStyleSet_Android(const FontFamily& family, const Scanner& scanner) {
        const SkString* cannonicalFamilyName = NULL;
>>>>>>> miniblink49
        if (family.fNames.count() > 0) {
            cannonicalFamilyName = &family.fNames[0];
        }
        // TODO? make this lazy
        for (int i = 0; i < family.fFonts.count(); ++i) {
            const FontFileInfo& fontFile = family.fFonts[i];

            SkString pathName(family.fBasePath);
            pathName.append(fontFile.fFileName);

            SkAutoTDelete<SkStream> stream(SkStream::NewFromFile(pathName.c_str()));
            if (!stream.get()) {
                SkDEBUGF(("Requested font file %s does not exist or cannot be opened.\n",
<<<<<<< HEAD
                    pathName.c_str()));
=======
                          pathName.c_str()));
>>>>>>> miniblink49
                continue;
            }

            const int ttcIndex = fontFile.fIndex;
            SkString familyName;
            SkFontStyle style;
            bool isFixedWidth;
            Scanner::AxisDefinitions axisDefinitions;
            if (!scanner.scanFont(stream.get(), ttcIndex,
<<<<<<< HEAD
                    &familyName, &style, &isFixedWidth, &axisDefinitions)) {
                SkDEBUGF(("Requested font file %s exists, but is not a valid font.\n",
                    pathName.c_str()));
=======
                                  &familyName, &style, &isFixedWidth, &axisDefinitions))
            {
                SkDEBUGF(("Requested font file %s exists, but is not a valid font.\n",
                          pathName.c_str()));
>>>>>>> miniblink49
                continue;
            }

            int weight = fontFile.fWeight != 0 ? fontFile.fWeight : style.weight();
            SkFontStyle::Slant slant = style.slant();
            switch (fontFile.fStyle) {
<<<<<<< HEAD
            case FontFileInfo::Style::kAuto:
                slant = style.slant();
                break;
            case FontFileInfo::Style::kNormal:
                slant = SkFontStyle::kUpright_Slant;
                break;
            case FontFileInfo::Style::kItalic:
                slant = SkFontStyle::kItalic_Slant;
                break;
            default:
                SkASSERT(false);
                break;
=======
                case FontFileInfo::Style::kAuto: slant = style.slant(); break;
                case FontFileInfo::Style::kNormal: slant = SkFontStyle::kUpright_Slant; break;
                case FontFileInfo::Style::kItalic: slant = SkFontStyle::kItalic_Slant; break;
                default: SkASSERT(false); break;
>>>>>>> miniblink49
            }
            style = SkFontStyle(weight, style.width(), slant);

            const SkLanguage& lang = family.fLanguage;
            uint32_t variant = family.fVariant;
            if (kDefault_FontVariant == variant) {
                variant = kCompact_FontVariant | kElegant_FontVariant;
            }

            // The first specified family name overrides the family name found in the font.
            // TODO: SkTypeface_AndroidSystem::onCreateFamilyNameIterator should return
            // all of the specified family names in addition to the names found in the font.
<<<<<<< HEAD
            if (cannonicalFamilyName != nullptr) {
=======
            if (cannonicalFamilyName != NULL) {
>>>>>>> miniblink49
                familyName = *cannonicalFamilyName;
            }

            SkAutoSTMalloc<4, SkFixed> axisValues(axisDefinitions.count());
<<<<<<< HEAD
            Scanner::computeAxisValues(axisDefinitions,
                fontFile.fAxes.begin(), fontFile.fAxes.count(),
                axisValues, familyName);

            fStyles.push_back().reset(new SkTypeface_AndroidSystem(
                pathName, cacheFontFiles, ttcIndex, axisValues.get(), axisDefinitions.count(),
                style, isFixedWidth, familyName, lang, variant));
        }
    }

    int count() override
    {
        return fStyles.count();
    }
    void getStyle(int index, SkFontStyle* style, SkString* name) override
    {
=======
            for (int i = 0; i < axisDefinitions.count(); ++i) {
                const Scanner::AxisDefinition& axisDefinition = axisDefinitions[i];
                axisValues[i] = axisDefinition.fDefault;
                for (int j = 0; j < fontFile.fAxes.count(); ++j) {
                    const FontFileInfo::Axis& axisSpecified = fontFile.fAxes[j];
                    if (axisDefinition.fTag == axisSpecified.fTag) {
                        axisValues[i] = SkTPin(axisSpecified.fValue, axisDefinition.fMinimum,
                                                                     axisDefinition.fMaximum);
                        if (axisValues[i] != axisSpecified.fValue) {
                            SkDEBUGF(("Requested font axis value out of range: "
                                      "%s '%c%c%c%c' %f; pinned to %f.\n",
                                      familyName.c_str(),
                                      (axisDefinition.fTag >> 24) & 0xFF,
                                      (axisDefinition.fTag >> 16) & 0xFF,
                                      (axisDefinition.fTag >>  8) & 0xFF,
                                      (axisDefinition.fTag      ) & 0xFF,
                                      SkFixedToDouble(axisSpecified.fValue),
                                      SkFixedToDouble(axisValues[i])));
                        }
                        break;
                    }
                }
                // TODO: warn on defaulted axis?
            }

            SkDEBUGCODE (
                // Check for axis specified, but not matched in font.
                for (int i = 0; i < fontFile.fAxes.count(); ++i) {
                    SkFourByteTag skTag = fontFile.fAxes[i].fTag;
                    bool found = false;
                    for (int j = 0; j < axisDefinitions.count(); ++j) {
                        if (skTag == axisDefinitions[j].fTag) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        SkDEBUGF(("Requested font axis not found: %s '%c%c%c%c'\n",
                                  familyName.c_str(),
                                  (skTag >> 24) & 0xFF,
                                  (skTag >> 16) & 0xFF,
                                  (skTag >>  8) & 0xFF,
                                  (skTag      ) & 0xFF));
                    }
                }
            )

            fStyles.push_back().reset(SkNEW_ARGS(SkTypeface_AndroidSystem,
                                                 (pathName, ttcIndex,
                                                  axisValues.get(), axisDefinitions.count(),
                                                  style, isFixedWidth, familyName,
                                                  lang, variant)));
        }
    }

    int count() override {
        return fStyles.count();
    }
    void getStyle(int index, SkFontStyle* style, SkString* name) override {
>>>>>>> miniblink49
        if (index < 0 || fStyles.count() <= index) {
            return;
        }
        if (style) {
            *style = this->style(index);
        }
        if (name) {
            name->reset();
        }
    }
<<<<<<< HEAD
    SkTypeface_AndroidSystem* createTypeface(int index) override
    {
        if (index < 0 || fStyles.count() <= index) {
            return nullptr;
=======
    SkTypeface_AndroidSystem* createTypeface(int index) override {
        if (index < 0 || fStyles.count() <= index) {
            return NULL;
>>>>>>> miniblink49
        }
        return SkRef(fStyles[index].get());
    }

    /** Find the typeface in this style set that most closely matches the given pattern.
     *  TODO: consider replacing with SkStyleSet_Indirect::matchStyle();
     *  this simpler version using match_score() passes all our tests.
     */
<<<<<<< HEAD
    SkTypeface_AndroidSystem* matchStyle(const SkFontStyle& pattern) override
    {
        if (0 == fStyles.count()) {
            return nullptr;
=======
    SkTypeface_AndroidSystem* matchStyle(const SkFontStyle& pattern) override {
        if (0 == fStyles.count()) {
            return NULL;
>>>>>>> miniblink49
        }
        SkTypeface_AndroidSystem* closest = fStyles[0];
        int minScore = std::numeric_limits<int>::max();
        for (int i = 0; i < fStyles.count(); ++i) {
            SkFontStyle style = this->style(i);
            int score = match_score(pattern, style);
            if (score < minScore) {
                closest = fStyles[i];
                minScore = score;
            }
        }
        return SkRef(closest);
    }

private:
<<<<<<< HEAD
    SkFontStyle style(int index)
    {
        return fStyles[index]->fontStyle();
    }
    static int match_score(const SkFontStyle& pattern, const SkFontStyle& candidate)
    {
        int score = 0;
        score += SkTAbs((pattern.width() - candidate.width()) * 100);
        score += SkTAbs((pattern.slant() == candidate.slant()) ? 0 : 1000);
        score += SkTAbs(pattern.weight() - candidate.weight());
=======
    SkFontStyle style(int index) {
        return fStyles[index]->fontStyle();
    }
    static int match_score(const SkFontStyle& pattern, const SkFontStyle& candidate) {
        int score = 0;
        score += abs((pattern.width() - candidate.width()) * 100);
        score += abs((pattern.isItalic() == candidate.isItalic()) ? 0 : 1000);
        score += abs(pattern.weight() - candidate.weight());
>>>>>>> miniblink49
        return score;
    }

    SkTArray<SkAutoTUnref<SkTypeface_AndroidSystem>, true> fStyles;

    friend struct NameToFamily;
    friend class SkFontMgr_Android;

    typedef SkFontStyleSet INHERITED;
};

/** On Android a single family can have many names, but our API assumes unique names.
 *  Map names to the back end so that all names for a given family refer to the same
 *  (non-replicated) set of typefaces.
 *  SkTDict<> doesn't let us do index-based lookup, so we write our own mapping.
 */
struct NameToFamily {
    SkString name;
    SkFontStyleSet_Android* styleSet;
};

class SkFontMgr_Android : public SkFontMgr {
public:
<<<<<<< HEAD
    SkFontMgr_Android(const SkFontMgr_Android_CustomFonts* custom)
    {
=======
    SkFontMgr_Android(const SkFontMgr_Android_CustomFonts* custom) {
>>>>>>> miniblink49
        SkTDArray<FontFamily*> families;
        if (custom && SkFontMgr_Android_CustomFonts::kPreferSystem != custom->fSystemFontUse) {
            SkString base(custom->fBasePath);
            SkFontMgr_Android_Parser::GetCustomFontFamilies(
                families, base, custom->fFontsXml, custom->fFallbackFontsXml);
        }
<<<<<<< HEAD
        if (!custom || (custom && SkFontMgr_Android_CustomFonts::kOnlyCustom != custom->fSystemFontUse)) {
=======
        if (!custom ||
            (custom && SkFontMgr_Android_CustomFonts::kOnlyCustom != custom->fSystemFontUse))
        {
>>>>>>> miniblink49
            SkFontMgr_Android_Parser::GetSystemFontFamilies(families);
        }
        if (custom && SkFontMgr_Android_CustomFonts::kPreferSystem == custom->fSystemFontUse) {
            SkString base(custom->fBasePath);
            SkFontMgr_Android_Parser::GetCustomFontFamilies(
                families, base, custom->fFontsXml, custom->fFallbackFontsXml);
        }
<<<<<<< HEAD
        this->buildNameToFamilyMap(families, custom ? custom->fIsolated : false);
=======
        this->buildNameToFamilyMap(families);
>>>>>>> miniblink49
        this->findDefaultFont();
        families.deleteAll();
    }

protected:
    /** Returns not how many families we have, but how many unique names
     *  exist among the families.
     */
<<<<<<< HEAD
    int onCountFamilies() const override
    {
        return fNameToFamilyMap.count();
    }

    void onGetFamilyName(int index, SkString* familyName) const override
    {
=======
    int onCountFamilies() const override {
        return fNameToFamilyMap.count();
    }

    void onGetFamilyName(int index, SkString* familyName) const override {
>>>>>>> miniblink49
        if (index < 0 || fNameToFamilyMap.count() <= index) {
            familyName->reset();
            return;
        }
        familyName->set(fNameToFamilyMap[index].name);
    }

<<<<<<< HEAD
    SkFontStyleSet* onCreateStyleSet(int index) const override
    {
        if (index < 0 || fNameToFamilyMap.count() <= index) {
            return nullptr;
=======
    SkFontStyleSet* onCreateStyleSet(int index) const override {
        if (index < 0 || fNameToFamilyMap.count() <= index) {
            return NULL;
>>>>>>> miniblink49
        }
        return SkRef(fNameToFamilyMap[index].styleSet);
    }

<<<<<<< HEAD
    SkFontStyleSet* onMatchFamily(const char familyName[]) const override
    {
        if (!familyName) {
            return nullptr;
=======
    SkFontStyleSet* onMatchFamily(const char familyName[]) const override {
        if (!familyName) {
            return NULL;
>>>>>>> miniblink49
        }
        SkAutoAsciiToLC tolc(familyName);
        for (int i = 0; i < fNameToFamilyMap.count(); ++i) {
            if (fNameToFamilyMap[i].name.equals(tolc.lc())) {
                return SkRef(fNameToFamilyMap[i].styleSet);
            }
        }
        // TODO: eventually we should not need to name fallback families.
        for (int i = 0; i < fFallbackNameToFamilyMap.count(); ++i) {
            if (fFallbackNameToFamilyMap[i].name.equals(tolc.lc())) {
                return SkRef(fFallbackNameToFamilyMap[i].styleSet);
            }
        }
<<<<<<< HEAD
        return nullptr;
    }

    virtual SkTypeface* onMatchFamilyStyle(const char familyName[],
        const SkFontStyle& style) const override
    {
=======
        return NULL;
    }

    virtual SkTypeface* onMatchFamilyStyle(const char familyName[],
                                           const SkFontStyle& style) const override {
>>>>>>> miniblink49
        SkAutoTUnref<SkFontStyleSet> sset(this->matchFamily(familyName));
        return sset->matchStyle(style);
    }

    virtual SkTypeface* onMatchFaceStyle(const SkTypeface* typeface,
<<<<<<< HEAD
        const SkFontStyle& style) const override
    {
=======
                                         const SkFontStyle& style) const override {
>>>>>>> miniblink49
        for (int i = 0; i < fFontStyleSets.count(); ++i) {
            for (int j = 0; j < fFontStyleSets[i]->fStyles.count(); ++j) {
                if (fFontStyleSets[i]->fStyles[j] == typeface) {
                    return fFontStyleSets[i]->matchStyle(style);
                }
            }
        }
<<<<<<< HEAD
        return nullptr;
    }

    static sk_sp<SkTypeface_AndroidSystem> find_family_style_character(
        const SkTDArray<NameToFamily>& fallbackNameToFamilyMap,
        const SkFontStyle& style, bool elegant,
        const SkString& langTag, SkUnichar character)
    {
        for (int i = 0; i < fallbackNameToFamilyMap.count(); ++i) {
            SkFontStyleSet_Android* family = fallbackNameToFamilyMap[i].styleSet;
            sk_sp<SkTypeface_AndroidSystem> face(family->matchStyle(style));
=======
        return NULL;
    }

    static SkTypeface_AndroidSystem* find_family_style_character(
            const SkTDArray<NameToFamily>& fallbackNameToFamilyMap,
            const SkFontStyle& style, bool elegant,
            const SkString& langTag, SkUnichar character)
    {
        for (int i = 0; i < fallbackNameToFamilyMap.count(); ++i) {
            SkFontStyleSet_Android* family = fallbackNameToFamilyMap[i].styleSet;
            SkAutoTUnref<SkTypeface_AndroidSystem> face(family->matchStyle(style));
>>>>>>> miniblink49

            if (!langTag.isEmpty() && !face->fLang.getTag().startsWith(langTag.c_str())) {
                continue;
            }

            if (SkToBool(face->fVariantStyle & kElegant_FontVariant) != elegant) {
                continue;
            }

            SkPaint paint;
            paint.setTypeface(face);
            paint.setTextEncoding(SkPaint::kUTF32_TextEncoding);

            uint16_t glyphID;
            paint.textToGlyphs(&character, sizeof(character), &glyphID);
            if (glyphID != 0) {
<<<<<<< HEAD
                return face;
            }
        }
        return nullptr;
    }

    virtual SkTypeface* onMatchFamilyStyleCharacter(const char familyName[],
        const SkFontStyle& style,
        const char* bcp47[],
        int bcp47Count,
        SkUnichar character) const override
=======
                return face.detach();
            }
        }
        return NULL;
    }

    virtual SkTypeface* onMatchFamilyStyleCharacter(const char familyName[],
                                                    const SkFontStyle& style,
                                                    const char* bcp47[],
                                                    int bcp47Count,
                                                    SkUnichar character) const override
>>>>>>> miniblink49
    {
        // The variant 'elegant' is 'not squashed', 'compact' is 'stays in ascent/descent'.
        // The variant 'default' means 'compact and elegant'.
        // As a result, it is not possible to know the variant context from the font alone.
        // TODO: add 'is_elegant' and 'is_compact' bits to 'style' request.

        // The first time match anything elegant, second time anything not elegant.
<<<<<<< HEAD
        for (int elegant = 2; elegant-- > 0;) {
            for (int bcp47Index = bcp47Count; bcp47Index-- > 0;) {
                SkLanguage lang(bcp47[bcp47Index]);
                while (!lang.getTag().isEmpty()) {
                    sk_sp<SkTypeface_AndroidSystem> matchingTypeface = find_family_style_character(fFallbackNameToFamilyMap,
                        style, SkToBool(elegant),
                        lang.getTag(), character);
                    if (matchingTypeface) {
                        return matchingTypeface.release();
=======
        for (int elegant = 2; elegant --> 0;) {
            for (int bcp47Index = bcp47Count; bcp47Index --> 0;) {
                SkLanguage lang(bcp47[bcp47Index]);
                while (!lang.getTag().isEmpty()) {
                    SkTypeface_AndroidSystem* matchingTypeface =
                        find_family_style_character(fFallbackNameToFamilyMap,
                                                    style, SkToBool(elegant),
                                                    lang.getTag(), character);
                    if (matchingTypeface) {
                        return matchingTypeface;
>>>>>>> miniblink49
                    }

                    lang = lang.getParent();
                }
            }
<<<<<<< HEAD
            sk_sp<SkTypeface_AndroidSystem> matchingTypeface = find_family_style_character(fFallbackNameToFamilyMap,
                style, SkToBool(elegant),
                SkString(), character);
            if (matchingTypeface) {
                return matchingTypeface.release();
            }
        }
        return nullptr;
    }

    SkTypeface* onCreateFromData(SkData* data, int ttcIndex) const override
    {
        return this->createFromStream(new SkMemoryStream(data), ttcIndex);
    }

    SkTypeface* onCreateFromFile(const char path[], int ttcIndex) const override
    {
        SkAutoTDelete<SkStreamAsset> stream(SkStream::NewFromFile(path));
        return stream.get() ? this->createFromStream(stream.release(), ttcIndex) : nullptr;
    }

    SkTypeface* onCreateFromStream(SkStreamAsset* bareStream, int ttcIndex) const override
    {
=======
            SkTypeface_AndroidSystem* matchingTypeface =
                find_family_style_character(fFallbackNameToFamilyMap,
                                            style, SkToBool(elegant),
                                            SkString(), character);
            if (matchingTypeface) {
                return matchingTypeface;
            }
        }
        return NULL;
    }

    SkTypeface* onCreateFromData(SkData* data, int ttcIndex) const override {
        return this->createFromStream(new SkMemoryStream(data), ttcIndex);
    }

    SkTypeface* onCreateFromFile(const char path[], int ttcIndex) const override {
        SkAutoTDelete<SkStreamAsset> stream(SkStream::NewFromFile(path));
        return stream.get() ? this->createFromStream(stream.detach(), ttcIndex) : NULL;
    }

    SkTypeface* onCreateFromStream(SkStreamAsset* bareStream, int ttcIndex) const override {
>>>>>>> miniblink49
        SkAutoTDelete<SkStreamAsset> stream(bareStream);
        bool isFixedPitch;
        SkFontStyle style;
        SkString name;
<<<<<<< HEAD
        if (!fScanner.scanFont(stream, ttcIndex, &name, &style, &isFixedPitch, nullptr)) {
            return nullptr;
        }
        SkFontData* data(new SkFontData(stream.release(), ttcIndex, nullptr, 0));
        return new SkTypeface_AndroidStream(data, style, isFixedPitch, name);
    }

    SkTypeface* onCreateFromStream(SkStreamAsset* s, const FontParameters& params) const override
    {
        using Scanner = SkTypeface_FreeType::Scanner;
        SkAutoTDelete<SkStreamAsset> stream(s);
        bool isFixedPitch;
        SkFontStyle style;
        SkString name;
        Scanner::AxisDefinitions axisDefinitions;
        if (!fScanner.scanFont(stream, params.getCollectionIndex(), &name, &style, &isFixedPitch,
                &axisDefinitions)) {
            return nullptr;
        }

        int paramAxisCount;
        const FontParameters::Axis* paramAxes = params.getAxes(&paramAxisCount);
        SkAutoSTMalloc<4, SkFixed> axisValues(axisDefinitions.count());
        Scanner::computeAxisValues(axisDefinitions, paramAxes, paramAxisCount, axisValues, name);

        SkFontData* data(new SkFontData(stream.release(), params.getCollectionIndex(),
            axisValues.get(), axisDefinitions.count()));
        return new SkTypeface_AndroidStream(data, style, isFixedPitch, name);
    }

    SkTypeface* onCreateFromFontData(SkFontData* data) const override
    {
=======
        if (!fScanner.scanFont(stream, ttcIndex, &name, &style, &isFixedPitch, NULL)) {
            return NULL;
        }
        SkFontData* data(new SkFontData(stream.detach(), ttcIndex, NULL, 0));
        return SkNEW_ARGS(SkTypeface_AndroidStream, (data, style, isFixedPitch, name));
    }

    SkTypeface* onCreateFromFontData(SkFontData* data) const override {
>>>>>>> miniblink49
        SkStreamAsset* stream(data->getStream());
        bool isFixedPitch;
        SkFontStyle style;
        SkString name;
<<<<<<< HEAD
        if (!fScanner.scanFont(stream, data->getIndex(), &name, &style, &isFixedPitch, nullptr)) {
            return nullptr;
        }
        return new SkTypeface_AndroidStream(data, style, isFixedPitch, name);
    }

    SkTypeface* onLegacyCreateTypeface(const char familyName[], SkFontStyle style) const override
    {
        if (familyName) {
            // On Android, we must return nullptr when we can't find the requested
=======
        if (!fScanner.scanFont(stream, data->getIndex(), &name, &style, &isFixedPitch, NULL)) {
            return NULL;
        }
        return SkNEW_ARGS(SkTypeface_AndroidStream, (data, style, isFixedPitch, name));
    }


    virtual SkTypeface* onLegacyCreateTypeface(const char familyName[],
                                               unsigned styleBits) const override {
        SkFontStyle style = SkFontStyle(styleBits);

        if (familyName) {
            // On Android, we must return NULL when we can't find the requested
>>>>>>> miniblink49
            // named typeface so that the system/app can provide their own recovery
            // mechanism. On other platforms we'd provide a typeface from the
            // default family instead.
            return this->onMatchFamilyStyle(familyName, style);
        }
        return fDefaultFamily->matchStyle(style);
    }

<<<<<<< HEAD
private:
=======

private:

>>>>>>> miniblink49
    SkTypeface_FreeType::Scanner fScanner;

    SkTArray<SkAutoTUnref<SkFontStyleSet_Android>, true> fFontStyleSets;
    SkFontStyleSet* fDefaultFamily;
    SkTypeface* fDefaultTypeface;

    SkTDArray<NameToFamily> fNameToFamilyMap;
    SkTDArray<NameToFamily> fFallbackNameToFamilyMap;

<<<<<<< HEAD
    void buildNameToFamilyMap(SkTDArray<FontFamily*> families, const bool isolated)
    {
=======
    void buildNameToFamilyMap(SkTDArray<FontFamily*> families) {
>>>>>>> miniblink49
        for (int i = 0; i < families.count(); i++) {
            FontFamily& family = *families[i];

            SkTDArray<NameToFamily>* nameToFamily = &fNameToFamilyMap;
            if (family.fIsFallbackFont) {
                nameToFamily = &fFallbackNameToFamilyMap;

                if (0 == family.fNames.count()) {
                    SkString& fallbackName = family.fNames.push_back();
                    fallbackName.printf("%.2x##fallback", i);
                }
            }

<<<<<<< HEAD
            SkFontStyleSet_Android* newSet = new SkFontStyleSet_Android(family, fScanner, isolated);
            if (0 == newSet->count()) {
                delete newSet;
=======
            SkFontStyleSet_Android* newSet =
                SkNEW_ARGS(SkFontStyleSet_Android, (family, fScanner));
            if (0 == newSet->count()) {
                SkDELETE(newSet);
>>>>>>> miniblink49
                continue;
            }
            fFontStyleSets.push_back().reset(newSet);

            for (int j = 0; j < family.fNames.count(); j++) {
                NameToFamily* nextEntry = nameToFamily->append();
<<<<<<< HEAD
                new (&nextEntry->name) SkString(family.fNames[j]);
=======
                SkNEW_PLACEMENT_ARGS(&nextEntry->name, SkString, (family.fNames[j]));
>>>>>>> miniblink49
                nextEntry->styleSet = newSet;
            }
        }
    }

<<<<<<< HEAD
    void findDefaultFont()
    {
=======
    void findDefaultFont() {
>>>>>>> miniblink49
        SkASSERT(!fFontStyleSets.empty());

        static const char* gDefaultNames[] = { "sans-serif" };
        for (size_t i = 0; i < SK_ARRAY_COUNT(gDefaultNames); ++i) {
            SkFontStyleSet* set = this->onMatchFamily(gDefaultNames[i]);
<<<<<<< HEAD
            if (nullptr == set) {
                continue;
            }
            SkTypeface* tf = set->matchStyle(SkFontStyle());
            if (nullptr == tf) {
=======
            if (NULL == set) {
                continue;
            }
            SkTypeface* tf = set->matchStyle(SkFontStyle());
            if (NULL == tf) {
>>>>>>> miniblink49
                continue;
            }
            fDefaultFamily = set;
            fDefaultTypeface = tf;
            break;
        }
<<<<<<< HEAD
        if (nullptr == fDefaultTypeface) {
=======
        if (NULL == fDefaultTypeface) {
>>>>>>> miniblink49
            fDefaultFamily = fFontStyleSets[0];
            fDefaultTypeface = fDefaultFamily->createTypeface(0);
        }
        SkASSERT(fDefaultFamily);
        SkASSERT(fDefaultTypeface);
    }

    typedef SkFontMgr INHERITED;
};

#ifdef SK_DEBUG
<<<<<<< HEAD
static char const* const gSystemFontUseStrings[] = {
    "OnlyCustom", "PreferCustom", "PreferSystem"
};
#endif
SkFontMgr* SkFontMgr_New_Android(const SkFontMgr_Android_CustomFonts* custom)
{
=======
static char const * const gSystemFontUseStrings[] = {
    "OnlyCustom", "PreferCustom", "PreferSystem"
};
#endif
SkFontMgr* SkFontMgr_New_Android(const SkFontMgr_Android_CustomFonts* custom) {
>>>>>>> miniblink49
    if (custom) {
        SkASSERT(0 <= custom->fSystemFontUse);
        SkASSERT(custom->fSystemFontUse < SK_ARRAY_COUNT(gSystemFontUseStrings));
        SkDEBUGF(("SystemFontUse: %s BasePath: %s Fonts: %s FallbackFonts: %s\n",
<<<<<<< HEAD
            gSystemFontUseStrings[custom->fSystemFontUse],
            custom->fBasePath,
            custom->fFontsXml,
            custom->fFallbackFontsXml));
    }

    return new SkFontMgr_Android(custom);
=======
                  gSystemFontUseStrings[custom->fSystemFontUse],
                  custom->fBasePath,
                  custom->fFontsXml,
                  custom->fFallbackFontsXml));
    }

    return SkNEW_ARGS(SkFontMgr_Android, (custom));
>>>>>>> miniblink49
}
