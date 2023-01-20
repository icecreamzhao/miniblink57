/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD
#include "SkTypes.h"
#if defined(SK_BUILD_FOR_WIN32)
=======
>>>>>>> miniblink49

#include "SkDWrite.h"
#include "SkDWriteFontFileStream.h"
#include "SkDataTable.h"
#include "SkHRESULT.h"
#include "SkMutex.h"
#include "SkRemotableFontMgr.h"
#include "SkStream.h"
#include "SkString.h"
#include "SkTArray.h"
#include "SkTScopedComPtr.h"
<<<<<<< HEAD
#include "SkTypeface_win_dw.h"
=======
#include "SkTypeface_win.h"
>>>>>>> miniblink49
#include "SkTypes.h"
#include "SkUtils.h"

#include <dwrite.h>

class SK_API SkRemotableFontMgr_DirectWrite : public SkRemotableFontMgr {
private:
    struct DataId {
<<<<<<< HEAD
        IUnknown* fLoader; // In COM only IUnknown pointers may be safely used for identity.
=======
        IUnknown* fLoader;  // In COM only IUnknown pointers may be safely used for identity.
>>>>>>> miniblink49
        void* fKey;
        UINT32 fKeySize;

        DataId() { }

<<<<<<< HEAD
        DataId(DataId&& that)
            : fLoader(that.fLoader)
            , fKey(that.fKey)
            , fKeySize(that.fKeySize)
        {
            that.fLoader = nullptr;
            that.fKey = nullptr;
            SkDEBUGCODE(that.fKeySize = 0xFFFFFFFF;)
        }

        ~DataId()
        {
=======
        // This is actually a move!!!
        explicit DataId(DataId& that)
            : fLoader(that.fLoader), fKey(that.fKey), fKeySize(that.fKeySize)
        {
            that.fLoader = NULL;
            that.fKey = NULL;
            SkDEBUGCODE(that.fKeySize = 0xFFFFFFFF;)
        }

        ~DataId() {
>>>>>>> miniblink49
            if (fLoader) {
                fLoader->Release();
            }
            sk_free(fKey);
        }
    };

    mutable SkTArray<DataId> fDataIdCache;
    mutable SkMutex fDataIdCacheMutex;

    int FindOrAdd(IDWriteFontFileLoader* fontFileLoader,
<<<<<<< HEAD
        const void* refKey, UINT32 refKeySize) const
    {
        SkTScopedComPtr<IUnknown> fontFileLoaderId;
        HR_GENERAL(fontFileLoader->QueryInterface(&fontFileLoaderId),
            "Failed to re-convert to IDWriteFontFileLoader.",
            SkFontIdentity::kInvalidDataId);
=======
                  const void* refKey, UINT32 refKeySize) const
    {
        SkTScopedComPtr<IUnknown> fontFileLoaderId;
        HR_GENERAL(fontFileLoader->QueryInterface(&fontFileLoaderId),
                   "Failed to re-convert to IDWriteFontFileLoader.",
                   SkFontIdentity::kInvalidDataId);
>>>>>>> miniblink49

        SkAutoMutexAcquire ama(fDataIdCacheMutex);
        int count = fDataIdCache.count();
        int i;
        for (i = 0; i < count; ++i) {
            const DataId& current = fDataIdCache[i];
<<<<<<< HEAD
            if (fontFileLoaderId.get() == current.fLoader && refKeySize == current.fKeySize && 0 == memcmp(refKey, current.fKey, refKeySize)) {
=======
            if (fontFileLoaderId.get() == current.fLoader &&
                refKeySize == current.fKeySize &&
                0 == memcmp(refKey, current.fKey, refKeySize))
            {
>>>>>>> miniblink49
                return i;
            }
        }
        DataId& added = fDataIdCache.push_back();
<<<<<<< HEAD
        added.fLoader = fontFileLoaderId.release(); // Ref is passed.
=======
        added.fLoader = fontFileLoaderId.release();  // Ref is passed.
>>>>>>> miniblink49
        added.fKey = sk_malloc_throw(refKeySize);
        memcpy(added.fKey, refKey, refKeySize);
        added.fKeySize = refKeySize;

        return i;
    }

public:
<<<<<<< HEAD
    /** localeNameLength must include the null terminator. */
    SkRemotableFontMgr_DirectWrite(IDWriteFontCollection* fontCollection,
        WCHAR* localeName, int localeNameLength)
=======


    /** localeNameLength must include the null terminator. */
    SkRemotableFontMgr_DirectWrite(IDWriteFontCollection* fontCollection,
                                   WCHAR* localeName, int localeNameLength)
>>>>>>> miniblink49
        : fFontCollection(SkRefComPtr(fontCollection))
        , fLocaleName(localeNameLength)
    {
        memcpy(fLocaleName.get(), localeName, localeNameLength * sizeof(WCHAR));
    }

<<<<<<< HEAD
    SkDataTable* getFamilyNames() const override
    {
=======
    SkDataTable* getFamilyNames() const override {
>>>>>>> miniblink49
        int count = fFontCollection->GetFontFamilyCount();

        SkDataTableBuilder names(1024);
        for (int index = 0; index < count; ++index) {
            SkTScopedComPtr<IDWriteFontFamily> fontFamily;
            HRNM(fFontCollection->GetFontFamily(index, &fontFamily),
<<<<<<< HEAD
                "Could not get requested family.");
=======
                 "Could not get requested family.");
>>>>>>> miniblink49

            SkTScopedComPtr<IDWriteLocalizedStrings> familyNames;
            HRNM(fontFamily->GetFamilyNames(&familyNames), "Could not get family names.");

            SkString familyName;
            sk_get_locale_string(familyNames.get(), fLocaleName.get(), &familyName);

            names.appendString(familyName);
        }
        return names.detachDataTable();
    }

<<<<<<< HEAD
    HRESULT FontToIdentity(IDWriteFont* font, SkFontIdentity* fontId) const
    {
=======
    HRESULT FontToIdentity(IDWriteFont* font, SkFontIdentity* fontId) const {
>>>>>>> miniblink49
        SkTScopedComPtr<IDWriteFontFace> fontFace;
        HRM(font->CreateFontFace(&fontFace), "Could not create font face.");

        UINT32 numFiles;
<<<<<<< HEAD
        HR(fontFace->GetFiles(&numFiles, nullptr));
=======
        HR(fontFace->GetFiles(&numFiles, NULL));
>>>>>>> miniblink49
        if (numFiles > 1) {
            return E_FAIL;
        }

        // data id
        SkTScopedComPtr<IDWriteFontFile> fontFile;
        HR(fontFace->GetFiles(&numFiles, &fontFile));

        SkTScopedComPtr<IDWriteFontFileLoader> fontFileLoader;
        HR(fontFile->GetLoader(&fontFileLoader));

        const void* refKey;
        UINT32 refKeySize;
        HR(fontFile->GetReferenceKey(&refKey, &refKeySize));

        fontId->fDataId = FindOrAdd(fontFileLoader.get(), refKey, refKeySize);

        // index
        fontId->fTtcIndex = fontFace->GetIndex();

        // style
<<<<<<< HEAD
        fontId->fFontStyle = get_style(font);
        return S_OK;
    }

    SkRemotableFontIdentitySet* getIndex(int familyIndex) const override
    {
        SkTScopedComPtr<IDWriteFontFamily> fontFamily;
        HRNM(fFontCollection->GetFontFamily(familyIndex, &fontFamily),
            "Could not get requested family.");
=======
        SkFontStyle::Slant slant;
        switch (font->GetStyle()) {
        case DWRITE_FONT_STYLE_NORMAL:
            slant = SkFontStyle::kUpright_Slant;
            break;
        case DWRITE_FONT_STYLE_OBLIQUE:
        case DWRITE_FONT_STYLE_ITALIC:
            slant = SkFontStyle::kItalic_Slant;
            break;
        default:
            SkASSERT(false);
        }

        int weight = font->GetWeight();
        int width = font->GetStretch();

        fontId->fFontStyle = SkFontStyle(weight, width, slant);
        return S_OK;
    }

    SkRemotableFontIdentitySet* getIndex(int familyIndex) const override {
        SkTScopedComPtr<IDWriteFontFamily> fontFamily;
        HRNM(fFontCollection->GetFontFamily(familyIndex, &fontFamily),
             "Could not get requested family.");
>>>>>>> miniblink49

        int count = fontFamily->GetFontCount();
        SkFontIdentity* fontIds;
        SkAutoTUnref<SkRemotableFontIdentitySet> fontIdSet(
            new SkRemotableFontIdentitySet(count, &fontIds));
        for (int fontIndex = 0; fontIndex < count; ++fontIndex) {
            SkTScopedComPtr<IDWriteFont> font;
            HRNM(fontFamily->GetFont(fontIndex, &font), "Could not get font.");

            HRN(FontToIdentity(font.get(), &fontIds[fontIndex]));
        }
<<<<<<< HEAD
        return fontIdSet.release();
    }

    virtual SkFontIdentity matchIndexStyle(int familyIndex,
        const SkFontStyle& pattern) const override
=======
        return fontIdSet.detach();
    }

    virtual SkFontIdentity matchIndexStyle(int familyIndex,
                                           const SkFontStyle& pattern) const override
>>>>>>> miniblink49
    {
        SkFontIdentity identity = { SkFontIdentity::kInvalidDataId };

        SkTScopedComPtr<IDWriteFontFamily> fontFamily;
        HR_GENERAL(fFontCollection->GetFontFamily(familyIndex, &fontFamily),
<<<<<<< HEAD
            "Could not get requested family.",
            identity);
=======
                   "Could not get requested family.",
                   identity);
>>>>>>> miniblink49

        const DWriteStyle dwStyle(pattern);
        SkTScopedComPtr<IDWriteFont> font;
        HR_GENERAL(fontFamily->GetFirstMatchingFont(dwStyle.fWeight, dwStyle.fWidth,
<<<<<<< HEAD
                       dwStyle.fSlant, &font),
            "Could not match font in family.",
            identity);

        HR_GENERAL(FontToIdentity(font.get(), &identity), nullptr, identity);
=======
                                                    dwStyle.fSlant, &font),
                   "Could not match font in family.",
                   identity);

        HR_GENERAL(FontToIdentity(font.get(), &identity), NULL, identity);
>>>>>>> miniblink49

        return identity;
    }

<<<<<<< HEAD
    static HRESULT getDefaultFontFamilyName(SkSMallocWCHAR* name)
    {
        NONCLIENTMETRICSW metrics;
        metrics.cbSize = sizeof(metrics);
        if (0 == SystemParametersInfoW(SPI_GETNONCLIENTMETRICS, sizeof(metrics), &metrics, 0)) {
=======
    static HRESULT getDefaultFontFamilyName(SkSMallocWCHAR* name) {
        NONCLIENTMETRICSW metrics;
        metrics.cbSize = sizeof(metrics);
        if (0 == SystemParametersInfoW(SPI_GETNONCLIENTMETRICS,
                                       sizeof(metrics),
                                       &metrics,
                                       0)) {
>>>>>>> miniblink49
            return E_UNEXPECTED;
        }

        size_t len = wcsnlen_s(metrics.lfMessageFont.lfFaceName, LF_FACESIZE) + 1;
        if (0 != wcsncpy_s(name->reset(len), len, metrics.lfMessageFont.lfFaceName, _TRUNCATE)) {
            return E_UNEXPECTED;
        }

        return S_OK;
    }

<<<<<<< HEAD
    SkRemotableFontIdentitySet* matchName(const char familyName[]) const override
    {
        SkSMallocWCHAR dwFamilyName;
        if (nullptr == familyName) {
            HR_GENERAL(getDefaultFontFamilyName(&dwFamilyName),
                nullptr, SkRemotableFontIdentitySet::NewEmpty());
        } else {
            HR_GENERAL(sk_cstring_to_wchar(familyName, &dwFamilyName),
                nullptr, SkRemotableFontIdentitySet::NewEmpty());
=======
    SkRemotableFontIdentitySet* matchName(const char familyName[]) const override {
        SkSMallocWCHAR dwFamilyName;
        if (NULL == familyName) {
            HR_GENERAL(getDefaultFontFamilyName(&dwFamilyName),
                       NULL, SkRemotableFontIdentitySet::NewEmpty());
        } else {
            HR_GENERAL(sk_cstring_to_wchar(familyName, &dwFamilyName),
                       NULL, SkRemotableFontIdentitySet::NewEmpty());
>>>>>>> miniblink49
        }

        UINT32 index;
        BOOL exists;
        HR_GENERAL(fFontCollection->FindFamilyName(dwFamilyName.get(), &index, &exists),
<<<<<<< HEAD
            "Failed while finding family by name.",
            SkRemotableFontIdentitySet::NewEmpty());
=======
                   "Failed while finding family by name.",
                   SkRemotableFontIdentitySet::NewEmpty());
>>>>>>> miniblink49
        if (!exists) {
            return SkRemotableFontIdentitySet::NewEmpty();
        }

        return this->getIndex(index);
    }

    virtual SkFontIdentity matchNameStyle(const char familyName[],
<<<<<<< HEAD
        const SkFontStyle& style) const override
=======
                                          const SkFontStyle& style) const override
>>>>>>> miniblink49
    {
        SkFontIdentity identity = { SkFontIdentity::kInvalidDataId };

        SkSMallocWCHAR dwFamilyName;
<<<<<<< HEAD
        if (nullptr == familyName) {
            HR_GENERAL(getDefaultFontFamilyName(&dwFamilyName), nullptr, identity);
        } else {
            HR_GENERAL(sk_cstring_to_wchar(familyName, &dwFamilyName), nullptr, identity);
=======
        if (NULL == familyName) {
            HR_GENERAL(getDefaultFontFamilyName(&dwFamilyName), NULL, identity);
        } else {
            HR_GENERAL(sk_cstring_to_wchar(familyName, &dwFamilyName), NULL, identity);
>>>>>>> miniblink49
        }

        UINT32 index;
        BOOL exists;
        HR_GENERAL(fFontCollection->FindFamilyName(dwFamilyName.get(), &index, &exists),
<<<<<<< HEAD
            "Failed while finding family by name.",
            identity);
=======
                   "Failed while finding family by name.",
                   identity);
>>>>>>> miniblink49
        if (!exists) {
            return identity;
        }

        return this->matchIndexStyle(index, style);
    }

    class FontFallbackRenderer : public IDWriteTextRenderer {
    public:
        FontFallbackRenderer(const SkRemotableFontMgr_DirectWrite* outer, UINT32 character)
<<<<<<< HEAD
            : fRefCount(1)
            , fOuter(SkSafeRef(outer))
            , fCharacter(character)
        {
            fIdentity.fDataId = SkFontIdentity::kInvalidDataId;
=======
            : fRefCount(1), fOuter(SkSafeRef(outer)), fCharacter(character) {
          fIdentity.fDataId = SkFontIdentity::kInvalidDataId;
>>>>>>> miniblink49
        }

        virtual ~FontFallbackRenderer() { }

        // IDWriteTextRenderer methods
        virtual HRESULT STDMETHODCALLTYPE DrawGlyphRun(
            void* clientDrawingContext,
            FLOAT baselineOriginX,
            FLOAT baselineOriginY,
            DWRITE_MEASURING_MODE measuringMode,
            DWRITE_GLYPH_RUN const* glyphRun,
            DWRITE_GLYPH_RUN_DESCRIPTION const* glyphRunDescription,
            IUnknown* clientDrawingEffect) override
        {
            SkTScopedComPtr<IDWriteFont> font;
            HRM(fOuter->fFontCollection->GetFontFromFontFace(glyphRun->fontFace, &font),
                "Could not get font from font face.");

            // It is possible that the font passed does not actually have the requested character,
            // due to no font being found and getting the fallback font.
            // Check that the font actually contains the requested character.
            BOOL exists;
            HRM(font->HasCharacter(fCharacter, &exists), "Could not find character.");

            if (exists) {
                HR(fOuter->FontToIdentity(font.get(), &fIdentity));
            }

            return S_OK;
        }

        virtual HRESULT STDMETHODCALLTYPE DrawUnderline(
            void* clientDrawingContext,
            FLOAT baselineOriginX,
            FLOAT baselineOriginY,
            DWRITE_UNDERLINE const* underline,
            IUnknown* clientDrawingEffect) override
<<<<<<< HEAD
        {
            return E_NOTIMPL;
        }
=======
        { return E_NOTIMPL; }
>>>>>>> miniblink49

        virtual HRESULT STDMETHODCALLTYPE DrawStrikethrough(
            void* clientDrawingContext,
            FLOAT baselineOriginX,
            FLOAT baselineOriginY,
            DWRITE_STRIKETHROUGH const* strikethrough,
            IUnknown* clientDrawingEffect) override
<<<<<<< HEAD
        {
            return E_NOTIMPL;
        }
=======
        { return E_NOTIMPL; }
>>>>>>> miniblink49

        virtual HRESULT STDMETHODCALLTYPE DrawInlineObject(
            void* clientDrawingContext,
            FLOAT originX,
            FLOAT originY,
            IDWriteInlineObject* inlineObject,
            BOOL isSideways,
            BOOL isRightToLeft,
            IUnknown* clientDrawingEffect) override
<<<<<<< HEAD
        {
            return E_NOTIMPL;
        }
=======
        { return E_NOTIMPL; }
>>>>>>> miniblink49

        // IDWritePixelSnapping methods
        virtual HRESULT STDMETHODCALLTYPE IsPixelSnappingDisabled(
            void* clientDrawingContext,
            BOOL* isDisabled) override
        {
            *isDisabled = FALSE;
            return S_OK;
        }

        virtual HRESULT STDMETHODCALLTYPE GetCurrentTransform(
            void* clientDrawingContext,
            DWRITE_MATRIX* transform) override
        {
<<<<<<< HEAD
            const DWRITE_MATRIX ident = { 1.0, 0.0, 0.0, 1.0, 0.0, 0.0 };
=======
            const DWRITE_MATRIX ident = {1.0, 0.0, 0.0, 1.0, 0.0, 0.0};
>>>>>>> miniblink49
            *transform = ident;
            return S_OK;
        }

        virtual HRESULT STDMETHODCALLTYPE GetPixelsPerDip(
            void* clientDrawingContext,
            FLOAT* pixelsPerDip) override
        {
            *pixelsPerDip = 1.0f;
            return S_OK;
        }

        // IUnknown methods
<<<<<<< HEAD
        ULONG STDMETHODCALLTYPE AddRef() override
        {
            return InterlockedIncrement(&fRefCount);
        }

        ULONG STDMETHODCALLTYPE Release() override
        {
=======
        ULONG STDMETHODCALLTYPE AddRef() override {
            return InterlockedIncrement(&fRefCount);
        }

        ULONG STDMETHODCALLTYPE Release() override {
>>>>>>> miniblink49
            ULONG newCount = InterlockedDecrement(&fRefCount);
            if (0 == newCount) {
                delete this;
            }
            return newCount;
        }

        virtual HRESULT STDMETHODCALLTYPE QueryInterface(
            IID const& riid, void** ppvObject) override
        {
<<<<<<< HEAD
            if (__uuidof(IUnknown) == riid || __uuidof(IDWritePixelSnapping) == riid || __uuidof(IDWriteTextRenderer) == riid) {
=======
            if (__uuidof(IUnknown) == riid ||
                __uuidof(IDWritePixelSnapping) == riid ||
                __uuidof(IDWriteTextRenderer) == riid)
            {
>>>>>>> miniblink49
                *ppvObject = this;
                this->AddRef();
                return S_OK;
            }
<<<<<<< HEAD
            *ppvObject = nullptr;
=======
            *ppvObject = NULL;
>>>>>>> miniblink49
            return E_FAIL;
        }

        const SkFontIdentity FallbackIdentity() { return fIdentity; }

    protected:
        ULONG fRefCount;
        SkAutoTUnref<const SkRemotableFontMgr_DirectWrite> fOuter;
        UINT32 fCharacter;
        SkFontIdentity fIdentity;
    };

    virtual SkFontIdentity matchNameStyleCharacter(const char familyName[],
<<<<<<< HEAD
        const SkFontStyle& pattern,
        const char* bcp47[], int bcp47Count,
        SkUnichar character) const override
=======
                                                   const SkFontStyle& pattern,
                                                   const char* bcp47[], int bcp47Count,
                                                   SkUnichar character) const override
>>>>>>> miniblink49
    {
        SkFontIdentity identity = { SkFontIdentity::kInvalidDataId };

        IDWriteFactory* dwFactory = sk_get_dwrite_factory();
<<<<<<< HEAD
        if (nullptr == dwFactory) {
=======
        if (NULL == dwFactory) {
>>>>>>> miniblink49
            return identity;
        }

        // TODO: use IDWriteFactory2::GetSystemFontFallback when available.

        const DWriteStyle dwStyle(pattern);

        SkSMallocWCHAR dwFamilyName;
<<<<<<< HEAD
        if (nullptr == familyName) {
            HR_GENERAL(getDefaultFontFamilyName(&dwFamilyName), nullptr, identity);
        } else {
            HR_GENERAL(sk_cstring_to_wchar(familyName, &dwFamilyName), nullptr, identity);
=======
        if (NULL == familyName) {
            HR_GENERAL(getDefaultFontFamilyName(&dwFamilyName), NULL, identity);
        } else {
            HR_GENERAL(sk_cstring_to_wchar(familyName, &dwFamilyName), NULL, identity);
>>>>>>> miniblink49
        }

        const SkSMallocWCHAR* dwBcp47;
        SkSMallocWCHAR dwBcp47Local;
        if (bcp47Count < 1) {
            dwBcp47 = &fLocaleName;
        } else {
            //TODO: support fallback stack.
<<<<<<< HEAD
            HR_GENERAL(sk_cstring_to_wchar(bcp47[bcp47Count - 1], &dwBcp47Local), nullptr, identity);
=======
            HR_GENERAL(sk_cstring_to_wchar(bcp47[bcp47Count-1], &dwBcp47Local), NULL, identity);
>>>>>>> miniblink49
            dwBcp47 = &dwBcp47Local;
        }

        SkTScopedComPtr<IDWriteTextFormat> fallbackFormat;
        HR_GENERAL(dwFactory->CreateTextFormat(dwFamilyName,
<<<<<<< HEAD
                       fFontCollection.get(),
                       dwStyle.fWeight,
                       dwStyle.fSlant,
                       dwStyle.fWidth,
                       72.0f,
                       *dwBcp47,
                       &fallbackFormat),
            "Could not create text format.",
            identity);
=======
                                               fFontCollection.get(),
                                               dwStyle.fWeight,
                                               dwStyle.fSlant,
                                               dwStyle.fWidth,
                                               72.0f,
                                               *dwBcp47,
                                               &fallbackFormat),
                   "Could not create text format.",
                   identity);
>>>>>>> miniblink49

        WCHAR str[16];
        UINT32 strLen = static_cast<UINT32>(
            SkUTF16_FromUnichar(character, reinterpret_cast<uint16_t*>(str)));
        SkTScopedComPtr<IDWriteTextLayout> fallbackLayout;
        HR_GENERAL(dwFactory->CreateTextLayout(str, strLen, fallbackFormat.get(),
<<<<<<< HEAD
                       200.0f, 200.0f,
                       &fallbackLayout),
            "Could not create text layout.",
            identity);
=======
                                               200.0f, 200.0f,
                                               &fallbackLayout),
                   "Could not create text layout.",
                   identity);
>>>>>>> miniblink49

        SkTScopedComPtr<FontFallbackRenderer> fontFallbackRenderer(
            new FontFallbackRenderer(this, character));

<<<<<<< HEAD
        HR_GENERAL(fallbackLayout->Draw(nullptr, fontFallbackRenderer.get(), 50.0f, 50.0f),
            "Could not draw layout with renderer.",
            identity);
=======
        HR_GENERAL(fallbackLayout->Draw(NULL, fontFallbackRenderer.get(), 50.0f, 50.0f),
                   "Could not draw layout with renderer.",
                   identity);
>>>>>>> miniblink49

        return fontFallbackRenderer->FallbackIdentity();
    }

<<<<<<< HEAD
    SkStreamAsset* getData(int dataId) const override
    {
        SkAutoMutexAcquire ama(fDataIdCacheMutex);
        if (dataId >= fDataIdCache.count()) {
            return nullptr;
=======
    SkStreamAsset* getData(int dataId) const override {
        SkAutoMutexAcquire ama(fDataIdCacheMutex);
        if (dataId >= fDataIdCache.count()) {
            return NULL;
>>>>>>> miniblink49
        }
        const DataId& id = fDataIdCache[dataId];

        SkTScopedComPtr<IDWriteFontFileLoader> loader;
        HRNM(id.fLoader->QueryInterface(&loader), "QuerryInterface IDWriteFontFileLoader failed");

        SkTScopedComPtr<IDWriteFontFileStream> fontFileStream;
        HRNM(loader->CreateStreamFromKey(id.fKey, id.fKeySize, &fontFileStream),
<<<<<<< HEAD
            "Could not create font file stream.");

        return new SkDWriteFontFileStream(fontFileStream.get());
=======
             "Could not create font file stream.");

        return SkNEW_ARGS(SkDWriteFontFileStream, (fontFileStream.get()));
>>>>>>> miniblink49
    }

private:
    SkTScopedComPtr<IDWriteFontCollection> fFontCollection;
    SkSMallocWCHAR fLocaleName;

    typedef SkRemotableFontMgr INHERITED;
};

<<<<<<< HEAD
SkRemotableFontMgr* SkRemotableFontMgr_New_DirectWrite()
{
    IDWriteFactory* factory = sk_get_dwrite_factory();
    if (nullptr == factory) {
        return nullptr;
=======
SkRemotableFontMgr* SkRemotableFontMgr_New_DirectWrite() {
    IDWriteFactory* factory = sk_get_dwrite_factory();
    if (NULL == factory) {
        return NULL;
>>>>>>> miniblink49
    }

    SkTScopedComPtr<IDWriteFontCollection> sysFontCollection;
    HRNM(factory->GetSystemFontCollection(&sysFontCollection, FALSE),
<<<<<<< HEAD
        "Could not get system font collection.");

    WCHAR localeNameStorage[LOCALE_NAME_MAX_LENGTH];
    WCHAR* localeName = nullptr;
    int localeNameLen = 0;

    // Dynamically load GetUserDefaultLocaleName function, as it is not available on XP.
    SkGetUserDefaultLocaleNameProc getUserDefaultLocaleNameProc = nullptr;
    HRESULT hr = SkGetGetUserDefaultLocaleNameProc(&getUserDefaultLocaleNameProc);
    if (nullptr == getUserDefaultLocaleNameProc) {
=======
         "Could not get system font collection.");

    WCHAR localeNameStorage[LOCALE_NAME_MAX_LENGTH];
    WCHAR* localeName = NULL;
    int localeNameLen = 0;

    // Dynamically load GetUserDefaultLocaleName function, as it is not available on XP.
    SkGetUserDefaultLocaleNameProc getUserDefaultLocaleNameProc = NULL;
    HRESULT hr = SkGetGetUserDefaultLocaleNameProc(&getUserDefaultLocaleNameProc);
    if (NULL == getUserDefaultLocaleNameProc) {
>>>>>>> miniblink49
        SK_TRACEHR(hr, "Could not get GetUserDefaultLocaleName.");
    } else {
        localeNameLen = getUserDefaultLocaleNameProc(localeNameStorage, LOCALE_NAME_MAX_LENGTH);
        if (localeNameLen) {
            localeName = localeNameStorage;
        };
    }

<<<<<<< HEAD
    return new SkRemotableFontMgr_DirectWrite(sysFontCollection.get(), localeName, localeNameLen);
}
#endif //defined(SK_BUILD_FOR_WIN32)
=======
    return SkNEW_ARGS(SkRemotableFontMgr_DirectWrite, (sysFontCollection.get(),
                                                       localeName, localeNameLen));
}
>>>>>>> miniblink49
