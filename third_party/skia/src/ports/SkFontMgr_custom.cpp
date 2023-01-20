/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkFontMgr_custom.h"
#include "SkFontDescriptor.h"
#include "SkFontHost_FreeType_common.h"
#include "SkFontMgr.h"
#include "SkFontStyle.h"
#include "SkOSFile.h"
#include "SkRefCnt.h"
#include "SkStream.h"
#include "SkString.h"
#include "SkTArray.h"
#include "SkTemplates.h"
#include "SkTypeface.h"
#include "SkTypefaceCache.h"
#include "SkTypes.h"

#include "third_party/fontconfig/src/fontconfig/fontconfig.h"
#include <limits>
#include <memory>

class SkData;
=======
#include "SkFontHost_FreeType_common.h"
#include "SkFontDescriptor.h"
#include "SkFontMgr.h"
#include "SkFontMgr_custom.h"
#include "SkDescriptor.h"
#include "SkOSFile.h"
#include "SkPaint.h"
#include "SkRTConf.h"
#include "SkString.h"
#include "SkStream.h"
#include "SkTSearch.h"
#include "SkTypefaceCache.h"
#include "SkTArray.h"

#include <limits>
>>>>>>> miniblink49

/** The base SkTypeface implementation for the custom font manager. */
class SkTypeface_Custom : public SkTypeface_FreeType {
public:
    SkTypeface_Custom(const SkFontStyle& style, bool isFixedPitch,
<<<<<<< HEAD
        bool sysFont, const SkString familyName, int index)
        : INHERITED(style, SkTypefaceCache::NewFontID(), isFixedPitch)
        , fIsSysFont(sysFont)
        , fFamilyName(familyName)
        , fIndex(index)
    {
    }
=======
                      bool sysFont, const SkString familyName, int index)
        : INHERITED(style, SkTypefaceCache::NewFontID(), isFixedPitch)
        , fIsSysFont(sysFont), fFamilyName(familyName), fIndex(index)
    { }
>>>>>>> miniblink49

    bool isSysFont() const { return fIsSysFont; }

protected:
<<<<<<< HEAD
    void onGetFamilyName(SkString* familyName) const override
    {
        *familyName = fFamilyName;
    }

    void onGetFontDescriptor(SkFontDescriptor* desc, bool* isLocal) const override
    {
=======
    void onGetFamilyName(SkString* familyName) const override {
        *familyName = fFamilyName;
    }

    void onGetFontDescriptor(SkFontDescriptor* desc, bool* isLocal) const override {
>>>>>>> miniblink49
        desc->setFamilyName(fFamilyName.c_str());
        *isLocal = !this->isSysFont();
    }

    int getIndex() const { return fIndex; }

private:
    const bool fIsSysFont;
    const SkString fFamilyName;
    const int fIndex;

    typedef SkTypeface_FreeType INHERITED;
};

/** The empty SkTypeface implementation for the custom font manager.
 *  Used as the last resort fallback typeface.
 */
class SkTypeface_Empty : public SkTypeface_Custom {
public:
<<<<<<< HEAD
    SkTypeface_Empty()
        : INHERITED(SkFontStyle(), false, true, SkString(), 0)
    {
    }

protected:
    SkStreamAsset* onOpenStream(int*) const override { return nullptr; }
=======
    SkTypeface_Empty() : INHERITED(SkFontStyle(), false, true, SkString(), 0) {}

protected:
    SkStreamAsset* onOpenStream(int*) const override { return NULL; }
>>>>>>> miniblink49

private:
    typedef SkTypeface_Custom INHERITED;
};

/** The stream SkTypeface implementation for the custom font manager. */
class SkTypeface_Stream : public SkTypeface_Custom {
public:
<<<<<<< HEAD
    SkTypeface_Stream(std::unique_ptr<SkFontData> fontData,
        const SkFontStyle& style, bool isFixedPitch, bool sysFont,
        const SkString familyName)
        : INHERITED(style, isFixedPitch, sysFont, familyName, fontData->getIndex())
        , fData(std::move(fontData))
    {
    }

protected:
    SkStreamAsset* onOpenStream(int* ttcIndex) const override
    {
        *ttcIndex = fData->getIndex();
        return fData->duplicateStream();
    }

    SkFontData* onCreateFontData() const override
    {
        return new SkFontData(*fData.get());
    }

private:
    std::unique_ptr<const SkFontData> fData;
=======
    SkTypeface_Stream(const SkFontStyle& style, bool isFixedPitch, bool sysFont,
                      const SkString familyName, SkStreamAsset* stream, int index)
        : INHERITED(style, isFixedPitch, sysFont, familyName, index)
        , fStream(stream)
    { }

protected:
    SkStreamAsset* onOpenStream(int* ttcIndex) const override {
        *ttcIndex = this->getIndex();
        return fStream->duplicate();
    }

private:
    const SkAutoTDelete<const SkStreamAsset> fStream;
>>>>>>> miniblink49

    typedef SkTypeface_Custom INHERITED;
};

/** The file SkTypeface implementation for the custom font manager. */
class SkTypeface_File : public SkTypeface_Custom {
public:
    SkTypeface_File(const SkFontStyle& style, bool isFixedPitch, bool sysFont,
<<<<<<< HEAD
        const SkString familyName, const char path[], int index)
        : INHERITED(style, isFixedPitch, sysFont, familyName, index)
        , fPath(path)
    {
    }

protected:
    SkStreamAsset* onOpenStream(int* ttcIndex) const override
    {
=======
                    const SkString familyName, const char path[], int index)
        : INHERITED(style, isFixedPitch, sysFont, familyName, index)
        , fPath(path)
    { }

protected:
    SkStreamAsset* onOpenStream(int* ttcIndex) const override {
>>>>>>> miniblink49
        *ttcIndex = this->getIndex();
        return SkStream::NewFromFile(fPath.c_str());
    }

private:
    SkString fPath;

    typedef SkTypeface_Custom INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

/**
 *  SkFontStyleSet_Custom
 *
 *  This class is used by SkFontMgr_Custom to hold SkTypeface_Custom families.
 */
class SkFontStyleSet_Custom : public SkFontStyleSet {
public:
<<<<<<< HEAD
    explicit SkFontStyleSet_Custom(const SkString familyName)
        : fFamilyName(familyName)
    {
    }

    /** Should only be called during the inital build phase. */
    void appendTypeface(sk_sp<SkTypeface_Custom> typeface)
    {
        fStyles.emplace_back(std::move(typeface));
    }

    int count() override
    {
        return fStyles.count();
    }

    void getStyle(int index, SkFontStyle* style, SkString* name) override
    {
        SkASSERT(index < fStyles.count());
        if (style) {
            *style = fStyles[index]->fontStyle();
        }
        if (name) {
            name->reset();
        }
    }

    SkTypeface* createTypeface(int index) override
    {
=======
    explicit SkFontStyleSet_Custom(const SkString familyName) : fFamilyName(familyName) { }

    /** Should only be called during the inital build phase. */
    void appendTypeface(SkTypeface_Custom* typeface) {
        fStyles.push_back().reset(typeface);
    }

    int count() override {
        return fStyles.count();
    }

    void getStyle(int index, SkFontStyle* style, SkString* name) override {
        SkASSERT(index < fStyles.count());
        bool bold = fStyles[index]->isBold();
        bool italic = fStyles[index]->isItalic();
        *style = SkFontStyle(bold ? SkFontStyle::kBold_Weight : SkFontStyle::kNormal_Weight,
                             SkFontStyle::kNormal_Width,
                             italic ? SkFontStyle::kItalic_Slant : SkFontStyle::kUpright_Slant);
        name->reset();
    }

    SkTypeface* createTypeface(int index) override {
>>>>>>> miniblink49
        SkASSERT(index < fStyles.count());
        return SkRef(fStyles[index].get());
    }

<<<<<<< HEAD
    SkTypeface* matchStyle(const SkFontStyle& pattern) override
    {
        return this->matchStyleCSS3(pattern);
=======
    static int match_score(const SkFontStyle& pattern, const SkFontStyle& candidate) {
        int score = 0;
        score += (pattern.width() - candidate.width()) * 100;
        score += (pattern.isItalic() == candidate.isItalic()) ? 0 : 1000;
        score += pattern.weight() - candidate.weight();
        return score;
    }

    SkTypeface* matchStyle(const SkFontStyle& pattern) override {
        if (0 == fStyles.count()) {
            return NULL;
        }

        SkTypeface_Custom* closest = fStyles[0];
        int minScore = std::numeric_limits<int>::max();
        for (int i = 0; i < fStyles.count(); ++i) {
            bool bold = fStyles[i]->isBold();
            bool italic = fStyles[i]->isItalic();
            SkFontStyle style = SkFontStyle(bold ? SkFontStyle::kBold_Weight
                                                 : SkFontStyle::kNormal_Weight,
                                            SkFontStyle::kNormal_Width,
                                            italic ? SkFontStyle::kItalic_Slant
                                                   : SkFontStyle::kUpright_Slant);

            int score = match_score(pattern, style);
            if (score < minScore) {
                closest = fStyles[i];
                minScore = score;
            }
        }
        return SkRef(closest);
>>>>>>> miniblink49
    }

    SkString getFamilyName() { return fFamilyName; }

private:
<<<<<<< HEAD
    SkTArray<sk_sp<SkTypeface_Custom>> fStyles;
=======
    SkTArray<SkAutoTUnref<SkTypeface_Custom>, true> fStyles;
>>>>>>> miniblink49
    SkString fFamilyName;

    friend class SkFontMgr_Custom;
};

/**
 *  SkFontMgr_Custom
 *
 *  This class is essentially a collection of SkFontStyleSet_Custom,
 *  one SkFontStyleSet_Custom for each family. This class may be modified
 *  to load fonts from any source by changing the initialization.
 */
class SkFontMgr_Custom : public SkFontMgr {
public:
<<<<<<< HEAD
    typedef SkTArray<sk_sp<SkFontStyleSet_Custom>> Families;
=======
    typedef SkTArray<SkAutoTUnref<SkFontStyleSet_Custom>, true> Families;
>>>>>>> miniblink49
    class SystemFontLoader {
    public:
        virtual ~SystemFontLoader() { }
        virtual void loadSystemFonts(const SkTypeface_FreeType::Scanner&, Families*) const = 0;
    };
<<<<<<< HEAD
    explicit SkFontMgr_Custom(const SystemFontLoader& loader)
        : fDefaultFamily(nullptr)
    {
=======
    explicit SkFontMgr_Custom(const SystemFontLoader& loader) : fDefaultFamily(NULL) {
>>>>>>> miniblink49
        loader.loadSystemFonts(fScanner, &fFamilies);

        // Try to pick a default font.
        static const char* defaultNames[] = {
<<<<<<< HEAD
            "Arial", "Verdana", "Times New Roman", "Droid Sans", nullptr
        };
        for (size_t i = 0; i < SK_ARRAY_COUNT(defaultNames); ++i) {
            sk_sp<SkFontStyleSet_Custom> set(this->onMatchFamily(defaultNames[i]));
            if (nullptr == set) {
                continue;
            }

            sk_sp<SkTypeface> tf(set->matchStyle(SkFontStyle(SkFontStyle::kNormal_Weight,
                SkFontStyle::kNormal_Width,
                SkFontStyle::kUpright_Slant)));
            if (nullptr == tf) {
                continue;
            }

            fDefaultFamily = set.get();
            break;
        }
        if (nullptr == fDefaultFamily) {
            fDefaultFamily = fFamilies[0].get();
=======
            "Arial", "Verdana", "Times New Roman", "Droid Sans", NULL
        };
        for (size_t i = 0; i < SK_ARRAY_COUNT(defaultNames); ++i) {
            SkFontStyleSet_Custom* set = this->onMatchFamily(defaultNames[i]);
            if (NULL == set) {
                continue;
            }

            SkTypeface* tf = set->matchStyle(SkFontStyle(SkFontStyle::kNormal_Weight,
                                                         SkFontStyle::kNormal_Width,
                                                         SkFontStyle::kUpright_Slant));
            if (NULL == tf) {
                continue;
            }

            fDefaultFamily = set;
            break;
        }
        if (NULL == fDefaultFamily) {
            fDefaultFamily = fFamilies[0];
>>>>>>> miniblink49
        }
    }

protected:
<<<<<<< HEAD
    int onCountFamilies() const override
    {
        return fFamilies.count();
    }

    void onGetFamilyName(int index, SkString* familyName) const override
    {
=======
    int onCountFamilies() const override {
        return fFamilies.count();
    }

    void onGetFamilyName(int index, SkString* familyName) const override {
>>>>>>> miniblink49
        SkASSERT(index < fFamilies.count());
        familyName->set(fFamilies[index]->getFamilyName());
    }

<<<<<<< HEAD
    SkFontStyleSet_Custom* onCreateStyleSet(int index) const override
    {
=======
    SkFontStyleSet_Custom* onCreateStyleSet(int index) const override {
>>>>>>> miniblink49
        SkASSERT(index < fFamilies.count());
        return SkRef(fFamilies[index].get());
    }

<<<<<<< HEAD
    SkFontStyleSet_Custom* onMatchFamily(const char familyName[]) const override
    {
        for (int i = 0; i < fFamilies.count(); ++i) {
            if (fFamilies[i]->getFamilyName().equals(familyName))
                return SkRef(fFamilies[i].get());
        }
        return nullptr;
    }

    SkTypeface* onMatchFamilyStyle(const char familyName[],
        const SkFontStyle& fontStyle) const override
=======
    SkFontStyleSet_Custom* onMatchFamily(const char familyName[]) const override {
        for (int i = 0; i < fFamilies.count(); ++i) {
            if (fFamilies[i]->getFamilyName().equals(familyName)) {
                return SkRef(fFamilies[i].get());
            }
        }
        return NULL;
    }

    SkTypeface* onMatchFamilyStyle(const char familyName[],
                                   const SkFontStyle& fontStyle) const override
>>>>>>> miniblink49
    {
        SkAutoTUnref<SkFontStyleSet> sset(this->matchFamily(familyName));
        return sset->matchStyle(fontStyle);
    }

    SkTypeface* onMatchFamilyStyleCharacter(const char familyName[], const SkFontStyle&,
<<<<<<< HEAD
        const char* bcp47[], int bcp47Count,
        SkUnichar character) const override
    {
        return nullptr;
    }

    SkTypeface* onMatchFaceStyle(const SkTypeface* familyMember,
        const SkFontStyle& fontStyle) const override
    {
        for (int i = 0; i < fFamilies.count(); ++i) {
            for (int j = 0; j < fFamilies[i]->fStyles.count(); ++j) {
                if (fFamilies[i]->fStyles[j].get() == familyMember) {
=======
                                            const char* bcp47[], int bcp47Count,
                                            SkUnichar character) const override
    {
        return NULL;
    }

    SkTypeface* onMatchFaceStyle(const SkTypeface* familyMember,
                                 const SkFontStyle& fontStyle) const override
    {
        for (int i = 0; i < fFamilies.count(); ++i) {
            for (int j = 0; j < fFamilies[i]->fStyles.count(); ++j) {
                if (fFamilies[i]->fStyles[j] == familyMember) {
>>>>>>> miniblink49
                    return fFamilies[i]->matchStyle(fontStyle);
                }
            }
        }
<<<<<<< HEAD
        return nullptr;
    }

    SkTypeface* onCreateFromData(SkData* data, int ttcIndex) const override
    {
        return this->createFromStream(new SkMemoryStream(data), ttcIndex);
    }

    SkTypeface* onCreateFromStream(SkStreamAsset* bareStream, int ttcIndex) const override
    {
        return this->createFromStream(bareStream, FontParameters().setCollectionIndex(ttcIndex));
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

        std::unique_ptr<SkFontData> data(new SkFontData(stream.release(),
            params.getCollectionIndex(),
            axisValues.get(), axisDefinitions.count()));
        return new SkTypeface_Stream(std::move(data), style, isFixedPitch, false, name);
    }

    SkTypeface* onCreateFromFontData(SkFontData* data) const override
    {
        bool isFixedPitch;
        SkFontStyle style;
        SkString name;
        if (!fScanner.scanFont(data->getStream(), data->getIndex(),
                &name, &style, &isFixedPitch, nullptr)) {
            return nullptr;
        }
        std::unique_ptr<SkFontData> unique_data(data);
        return new SkTypeface_Stream(std::move(unique_data), style, isFixedPitch, false, name);
    }

    SkTypeface* onCreateFromFile(const char path[], int ttcIndex) const override
    {
        SkAutoTDelete<SkStreamAsset> stream(SkStream::NewFromFile(path));
        return stream.get() ? this->createFromStream(stream.release(), ttcIndex) : nullptr;
    }

    SkTypeface* onLegacyCreateTypeface(const char familyName[], SkFontStyle style) const override
    {
        SkTypeface* tf = nullptr;
=======
        return NULL;
    }

    SkTypeface* onCreateFromData(SkData* data, int ttcIndex) const override {
        return this->createFromStream(new SkMemoryStream(data), ttcIndex);
    }

    SkTypeface* onCreateFromStream(SkStreamAsset* bareStream, int ttcIndex) const override {
        SkAutoTDelete<SkStreamAsset> stream(bareStream);
        if (NULL == stream || stream->getLength() <= 0) {
            return NULL;
        }

        bool isFixedPitch;
        SkFontStyle style;
        SkString name;
        if (fScanner.scanFont(stream, ttcIndex, &name, &style, &isFixedPitch, NULL)) {
            return SkNEW_ARGS(SkTypeface_Stream, (style, isFixedPitch, false, name,
                                                  stream.detach(), ttcIndex));
        } else {
            return NULL;
        }
    }

    SkTypeface* onCreateFromFile(const char path[], int ttcIndex) const override {
        SkAutoTDelete<SkStreamAsset> stream(SkStream::NewFromFile(path));
        return stream.get() ? this->createFromStream(stream.detach(), ttcIndex) : NULL;
    }

    SkTypeface* onLegacyCreateTypeface(const char familyName[], unsigned styleBits) const override {
        SkTypeface::Style oldStyle = (SkTypeface::Style)styleBits;
        SkFontStyle style = SkFontStyle(oldStyle & SkTypeface::kBold
                                                 ? SkFontStyle::kBold_Weight
                                                 : SkFontStyle::kNormal_Weight,
                                        SkFontStyle::kNormal_Width,
                                        oldStyle & SkTypeface::kItalic
                                                 ? SkFontStyle::kItalic_Slant
                                                 : SkFontStyle::kUpright_Slant);
        SkTypeface* tf = NULL;
>>>>>>> miniblink49

        if (familyName) {
            tf = this->onMatchFamilyStyle(familyName, style);
        }

<<<<<<< HEAD
        if (nullptr == tf) {
            tf = fDefaultFamily->matchStyle(style);
        }

        return tf;
=======
        if (NULL == tf) {
            tf = fDefaultFamily->matchStyle(style);
        }

        return SkSafeRef(tf);
>>>>>>> miniblink49
    }

private:
    Families fFamilies;
    SkFontStyleSet_Custom* fDefaultFamily;
    SkTypeface_FreeType::Scanner fScanner;
};

///////////////////////////////////////////////////////////////////////////////

class DirectorySystemFontLoader : public SkFontMgr_Custom::SystemFontLoader {
public:
<<<<<<< HEAD
    DirectorySystemFontLoader(const char* dir)
        : fBaseDirectory(dir)
    {
    }

    void loadSystemFonts(const SkTypeface_FreeType::Scanner& scanner,
        SkFontMgr_Custom::Families* families) const override
=======
    DirectorySystemFontLoader(const char* dir) : fBaseDirectory(dir) { }

    void loadSystemFonts(const SkTypeface_FreeType::Scanner& scanner,
                         SkFontMgr_Custom::Families* families) const override
>>>>>>> miniblink49
    {
        load_directory_fonts(scanner, fBaseDirectory, ".ttf", families);
        load_directory_fonts(scanner, fBaseDirectory, ".ttc", families);
        load_directory_fonts(scanner, fBaseDirectory, ".otf", families);
        load_directory_fonts(scanner, fBaseDirectory, ".pfb", families);

        if (families->empty()) {
            SkFontStyleSet_Custom* family = new SkFontStyleSet_Custom(SkString());
            families->push_back().reset(family);
<<<<<<< HEAD
            family->appendTypeface(sk_make_sp<SkTypeface_Empty>());
=======
            family->appendTypeface(SkNEW(SkTypeface_Empty));
>>>>>>> miniblink49
        }
    }

private:
    static SkFontStyleSet_Custom* find_family(SkFontMgr_Custom::Families& families,
<<<<<<< HEAD
        const char familyName[])
    {
        for (int i = 0; i < families.count(); ++i) {
=======
                                              const char familyName[])
    {
       for (int i = 0; i < families.count(); ++i) {
>>>>>>> miniblink49
            if (families[i]->getFamilyName().equals(familyName)) {
                return families[i].get();
            }
        }
<<<<<<< HEAD
        return nullptr;
    }

    static void load_directory_fonts(const SkTypeface_FreeType::Scanner& scanner,
        const SkString& directory, const char* suffix,
        SkFontMgr_Custom::Families* families)
=======
        return NULL;
    }

    static void load_directory_fonts(const SkTypeface_FreeType::Scanner& scanner,
                                     const SkString& directory, const char* suffix,
                                     SkFontMgr_Custom::Families* families)
>>>>>>> miniblink49
    {
        SkOSFile::Iter iter(directory.c_str(), suffix);
        SkString name;

        while (iter.next(&name, false)) {
            SkString filename(SkOSPath::Join(directory.c_str(), name.c_str()));
            SkAutoTDelete<SkStream> stream(SkStream::NewFromFile(filename.c_str()));
            if (!stream.get()) {
                SkDebugf("---- failed to open <%s>\n", filename.c_str());
                continue;
            }

            int numFaces;
            if (!scanner.recognizedFont(stream, &numFaces)) {
                SkDebugf("---- failed to open <%s> as a font\n", filename.c_str());
                continue;
            }

            for (int faceIndex = 0; faceIndex < numFaces; ++faceIndex) {
                bool isFixedPitch;
                SkString realname;
                SkFontStyle style = SkFontStyle(); // avoid uninitialized warning
<<<<<<< HEAD
                if (!scanner.scanFont(stream, faceIndex, &realname, &style, &isFixedPitch, nullptr)) {
                    SkDebugf("---- failed to open <%s> <%d> as a font\n", filename.c_str(), faceIndex);
                    continue;
                }                

                SkFontStyleSet_Custom* addTo = find_family(*families, realname.c_str());
                //printf("load_directory_fonts: %p, %s\n", addTo, realname.c_str());
                if (nullptr == addTo) {
                    addTo = new SkFontStyleSet_Custom(realname);
                    families->push_back().reset(addTo);
                }
                addTo->appendTypeface(sk_make_sp<SkTypeface_File>(style, isFixedPitch, true,
                    realname, filename.c_str(),
                    faceIndex));
=======
                if (!scanner.scanFont(stream, faceIndex, &realname, &style, &isFixedPitch, NULL)) {
                    SkDebugf("---- failed to open <%s> <%d> as a font\n",
                             filename.c_str(), faceIndex);
                    continue;
                }

                SkTypeface_Custom* tf = SkNEW_ARGS(SkTypeface_File, (
                                                    style,
                                                    isFixedPitch,
                                                    true,  // system-font (cannot delete)
                                                    realname,
                                                    filename.c_str(),
                                                    faceIndex));

                SkFontStyleSet_Custom* addTo = find_family(*families, realname.c_str());
                if (NULL == addTo) {
                    addTo = new SkFontStyleSet_Custom(realname);
                    families->push_back().reset(addTo);
                }
                addTo->appendTypeface(tf);
>>>>>>> miniblink49
            }
        }

        SkOSFile::Iter dirIter(directory.c_str());
        while (dirIter.next(&name, true)) {
            if (name.startsWith(".")) {
                continue;
            }
            SkString dirname(SkOSPath::Join(directory.c_str(), name.c_str()));
            load_directory_fonts(scanner, dirname, suffix, families);
        }
    }

    SkString fBaseDirectory;
};

<<<<<<< HEAD
void getFontList3()
{
    FcInit();
    FcConfig* config = FcInitLoadConfigAndFonts();
    FcPattern* pat = FcPatternCreate();
    FcObjectSet* os = FcObjectSetBuild(FC_FAMILY, FC_STYLE, FC_LANG, FC_FILE, (char*)0);
    FcFontSet* fs = FcFontList(config, pat, os);

    printf("Total matching fonts: %d\n", fs->nfont);
    for (int i = 0; fs && i < fs->nfont; ++i) {
        FcPattern* font = fs->fonts[i];
        FcChar8* file, * style, * family;
        if (FcPatternGetString(font, FC_FILE, 0, &file) == FcResultMatch &&
            FcPatternGetString(font, FC_FAMILY, 0, &family) == FcResultMatch &&
            FcPatternGetString(font, FC_STYLE, 0, &style) == FcResultMatch) {
            printf("Filename: %s (family %s, style %s)\n", file, family, style);
        }
    }
    if (fs) FcFontSetDestroy(fs);
}

void getFontList2()
{
    FcPattern* pat;
    FcFontSet* fs;
    FcObjectSet* os;
    FcChar8* s, * file;
    FcConfig* config;
    FcBool result;
    int i;

    result = FcInit();
    config = FcConfigGetCurrent();
    FcConfigSetRescanInterval(config, 0);

    // show the fonts (debugging)
    pat = FcPatternCreate();
    os = FcObjectSetBuild(FC_FAMILY, FC_STYLE, FC_LANG, (char*)0);
    fs = FcFontList(config, pat, os);

    printf("Total fonts: %d\n", fs->nfont);

    for (i = 0; fs && i < fs->nfont; i++) {
        FcPattern* font = fs->fonts[i];//FcFontSetFont(fs, i);
        //FcPatternPrint(font);
        FcChar8* str = FcNameUnparse(font);
        if (FcPatternGetString(font, FC_FILE, 0, &file) == FcResultMatch) {
            printf("Filename: [%s]\n", file);
        }

        FcChar8* lang;
        if (FcPatternGetString(font, FC_LANG, 0, &lang) == FcResultMatch)
            printf("(lang: %s)\n", lang);

        printf("Font: [%s]\n", str);
        free(str);
    }
    if (fs)
        FcFontSetDestroy(fs);
}

void getFontList()
{
    const FcChar8* format = NULL;
    int			nfont = 0;
    int			i;
    FcObjectSet* os = 0;
    FcFontSet* fs;
    FcPattern* pat;

    FcInit();
    FcConfig* fc = FcInitLoadConfigAndFonts();
    pat = FcNameParse((FcChar8*)"lang=zh");

    if (!pat) {
        printf("Unable to parse the pattern\n");
        return;
    }

    os = FcObjectSetBuild(FC_FAMILY, FC_STYLE, FC_FILE, (char*)0);
    format = (const FcChar8*)"%{=fclist}\n";

    fs = FcFontList(fc, pat, os);
    if (os)
        FcObjectSetDestroy(os);
    if (pat)
        FcPatternDestroy(pat);

    printf("getFontList: %d %d\n", fs->nfont, fs->sfont);

    int	j;
    for (j = 0; j < fs->nfont; j++) {
        FcChar8* s;
        s = FcPatternFormat(fs->fonts[j], format);
        if (s) {
            printf("%s", s);
            FcStrFree(s);
        }
    }

    if (fs) {
        nfont = fs->nfont;
        FcFontSetDestroy(fs);
    }

    FcFini();

    __debugbreak();
}


SK_API SkFontMgr* SkFontMgr_New_Custom_Directory(const char* dir)
{
    //getFontList2();
=======
SK_API SkFontMgr* SkFontMgr_New_Custom_Directory(const char* dir) {
>>>>>>> miniblink49
    return new SkFontMgr_Custom(DirectorySystemFontLoader(dir));
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
struct SkEmbeddedResource {
    const uint8_t* data;
    size_t size;
};
struct SkEmbeddedResourceHeader {
    const SkEmbeddedResource* entries;
    int count;
};

class EmbeddedSystemFontLoader : public SkFontMgr_Custom::SystemFontLoader {
public:
    EmbeddedSystemFontLoader(const SkEmbeddedResourceHeader* header)
        : fHeader(header)
    {
    }

    void loadSystemFonts(const SkTypeface_FreeType::Scanner& scanner,
        SkFontMgr_Custom::Families* families) const override
=======
struct SkEmbeddedResource { const uint8_t* data; size_t size; };
struct SkEmbeddedResourceHeader { const SkEmbeddedResource* entries; int count; };

class EmbeddedSystemFontLoader : public SkFontMgr_Custom::SystemFontLoader {
public:
    EmbeddedSystemFontLoader(const SkEmbeddedResourceHeader* header) : fHeader(header) { }

    void loadSystemFonts(const SkTypeface_FreeType::Scanner& scanner,
                         SkFontMgr_Custom::Families* families) const override
>>>>>>> miniblink49
    {
        for (int i = 0; i < fHeader->count; ++i) {
            const SkEmbeddedResource& fontEntry = fHeader->entries[i];
            load_embedded_font(scanner, fontEntry.data, fontEntry.size, i, families);
        }

        if (families->empty()) {
            SkFontStyleSet_Custom* family = new SkFontStyleSet_Custom(SkString());
            families->push_back().reset(family);
<<<<<<< HEAD
            family->appendTypeface(sk_make_sp<SkTypeface_Empty>());
=======
            family->appendTypeface(SkNEW(SkTypeface_Empty));
>>>>>>> miniblink49
        }
    }

private:
    static SkFontStyleSet_Custom* find_family(SkFontMgr_Custom::Families& families,
<<<<<<< HEAD
        const char familyName[])
    {
        for (int i = 0; i < families.count(); ++i) {
=======
                                              const char familyName[])
    {
       for (int i = 0; i < families.count(); ++i) {
>>>>>>> miniblink49
            if (families[i]->getFamilyName().equals(familyName)) {
                return families[i].get();
            }
        }
<<<<<<< HEAD
        return nullptr;
    }

    static void load_embedded_font(const SkTypeface_FreeType::Scanner& scanner,
        const uint8_t* data, size_t size, int index,
        SkFontMgr_Custom::Families* families)
=======
        return NULL;
    }

    static void load_embedded_font(const SkTypeface_FreeType::Scanner& scanner,
                                   const uint8_t* data, size_t size, int index,
                                   SkFontMgr_Custom::Families* families)
>>>>>>> miniblink49
    {
        SkAutoTDelete<SkMemoryStream> stream(new SkMemoryStream(data, size, false));

        int numFaces;
        if (!scanner.recognizedFont(stream, &numFaces)) {
            SkDebugf("---- failed to open <%d> as a font\n", index);
            return;
        }

        for (int faceIndex = 0; faceIndex < numFaces; ++faceIndex) {
            bool isFixedPitch;
            SkString realname;
            SkFontStyle style = SkFontStyle(); // avoid uninitialized warning
<<<<<<< HEAD
            if (!scanner.scanFont(stream, faceIndex, &realname, &style, &isFixedPitch, nullptr)) {
=======
            if (!scanner.scanFont(stream, faceIndex, &realname, &style, &isFixedPitch, NULL)) {
>>>>>>> miniblink49
                SkDebugf("---- failed to open <%d> <%d> as a font\n", index, faceIndex);
                return;
            }

<<<<<<< HEAD
            SkFontStyleSet_Custom* addTo = find_family(*families, realname.c_str());
            if (nullptr == addTo) {
                addTo = new SkFontStyleSet_Custom(realname);
                families->push_back().reset(addTo);
            }
            std::unique_ptr<SkFontData> data(
                new SkFontData(stream.release(), faceIndex, nullptr, 0));
            addTo->appendTypeface(sk_make_sp<SkTypeface_Stream>(std::move(data),
                style, isFixedPitch,
                true, realname));
=======
            SkTypeface_Custom* tf = SkNEW_ARGS(SkTypeface_Stream, (
                                                style,
                                                isFixedPitch,
                                                true,  // system-font (cannot delete)
                                                realname,
                                                stream.detach(),
                                                faceIndex));

            SkFontStyleSet_Custom* addTo = find_family(*families, realname.c_str());
            if (NULL == addTo) {
                addTo = new SkFontStyleSet_Custom(realname);
                families->push_back().reset(addTo);
            }
            addTo->appendTypeface(tf);
>>>>>>> miniblink49
        }
    }

    const SkEmbeddedResourceHeader* fHeader;
};

<<<<<<< HEAD
SkFontMgr* SkFontMgr_New_Custom_Embedded(const SkEmbeddedResourceHeader* header)
{
    return new SkFontMgr_Custom(EmbeddedSystemFontLoader(header));
}

///////////////////////////////////////////////////////////////////////////////

class EmptyFontLoader : public SkFontMgr_Custom::SystemFontLoader {
public:
    EmptyFontLoader() { }

    void loadSystemFonts(const SkTypeface_FreeType::Scanner& scanner,
        SkFontMgr_Custom::Families* families) const override
    {
        SkFontStyleSet_Custom* family = new SkFontStyleSet_Custom(SkString());
        families->push_back().reset(family);
        family->appendTypeface(sk_make_sp<SkTypeface_Empty>());
    }
};

SK_API SkFontMgr* SkFontMgr_New_Custom_Empty()
{
    return new SkFontMgr_Custom(EmptyFontLoader());
}
=======
SkFontMgr* SkFontMgr_New_Custom_Embedded(const SkEmbeddedResourceHeader* header) {
    return new SkFontMgr_Custom(EmbeddedSystemFontLoader(header));
}
>>>>>>> miniblink49
