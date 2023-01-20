/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkFontConfigInterface.h"
#include "SkFontConfigTypeface.h"
<<<<<<< HEAD
#include "SkFontDescriptor.h"
#include "SkFontMgr.h"
#include "SkFontStyle.h"
#include "SkMutex.h"
#include "SkResourceCache.h"
#include "SkString.h"
#include "SkTypeface.h"
#include "SkTypefaceCache.h"

SkStreamAsset* SkTypeface_FCI::onOpenStream(int* ttcIndex) const
{
    *ttcIndex = this->getIdentity().fTTCIndex;

    SkStreamAsset* stream = this->getLocalStream();
    if (stream) {
        return stream->duplicate();
    }

    return fFCI->openStream(this->getIdentity());
}

void SkTypeface_FCI::onGetFontDescriptor(SkFontDescriptor* desc, bool* isLocalStream) const
{
    SkString name;
    this->getFamilyName(&name);
    desc->setFamilyName(name.c_str());
    *isLocalStream = SkToBool(this->getLocalStream());
}

///////////////////////////////////////////////////////////////////////////////

class SkFontStyleSet_FCI : public SkFontStyleSet {
public:
    SkFontStyleSet_FCI() { }

    int count() override { return 0; }
    void getStyle(int index, SkFontStyle*, SkString* style) override { SkASSERT(false); }
    SkTypeface* createTypeface(int index) override
    {
        SkASSERT(false);
        return nullptr;
    }
    SkTypeface* matchStyle(const SkFontStyle& pattern) override { return nullptr; }
};

///////////////////////////////////////////////////////////////////////////////

class SkFontRequestCache {
public:
    struct Request : public SkResourceCache::Key {
    private:
        Request(const char* name, size_t nameLen, const SkFontStyle& style)
            : fStyle(style)
        {
            /** Pointer to just after the last field of this class. */
            char* content = const_cast<char*>(SkTAfter<const char>(&this->fStyle));

            // No holes.
            SkASSERT(SkTAddOffset<char>(this, sizeof(SkResourceCache::Key) + keySize) == content);

            // Has a size divisible by size of uint32_t.
            SkASSERT((content - reinterpret_cast<char*>(this)) % sizeof(uint32_t) == 0);

            size_t contentLen = SkAlign4(nameLen);
            sk_careful_memcpy(content, name, nameLen);
            sk_bzero(content + nameLen, contentLen - nameLen);
            this->init(nullptr, 0, keySize + contentLen);
        }
        const SkFontStyle fStyle;
        /** The sum of the sizes of the fields of this class. */
        static const size_t keySize = sizeof(fStyle);

    public:
        static Request* Create(const char* name, const SkFontStyle& style)
        {
            size_t nameLen = name ? strlen(name) : 0;
            size_t contentLen = SkAlign4(nameLen);
            char* storage = new char[sizeof(Request) + contentLen];
            return new (storage) Request(name, nameLen, style);
        }
        void operator delete(void* storage)
        {
            delete[] reinterpret_cast<char*>(storage);
        }
    };

private:
    struct Result : public SkResourceCache::Rec {
        Result(Request* request, SkTypeface* typeface)
            : fRequest(request)
            , fFace(SkSafeRef(typeface))
        {
        }
        Result(Result&&) = default;
        Result& operator=(Result&&) = default;

        const Key& getKey() const override { return *fRequest; }
        size_t bytesUsed() const override { return fRequest->size() + sizeof(fFace); }
        const char* getCategory() const override { return "request_cache"; }
        SkDiscardableMemory* diagnostic_only_getDiscardable() const override { return nullptr; }

        SkAutoTDelete<Request> fRequest;
        SkAutoTUnref<SkTypeface> fFace;
    };

    SkResourceCache fCachedResults;

public:
    SkFontRequestCache(size_t maxSize)
        : fCachedResults(maxSize)
    {
    }

    /** Takes ownership of request. It will be deleted when no longer needed. */
    void add(SkTypeface* face, Request* request)
    {
        fCachedResults.add(new Result(request, face));
    }
    /** Does not take ownership of request. */
    SkTypeface* findAndRef(Request* request)
    {
        SkTypeface* face = nullptr;
        fCachedResults.find(
            *request, [](const SkResourceCache::Rec& rec, void* context) -> bool {
                const Result& result = static_cast<const Result&>(rec);
                SkTypeface** face = static_cast<SkTypeface**>(context);

                *face = result.fFace;
                return true;
            },
            &face);
        return SkSafeRef(face);
    }
};

///////////////////////////////////////////////////////////////////////////////

static bool find_by_FontIdentity(SkTypeface* cachedTypeface, void* ctx)
{
    typedef SkFontConfigInterface::FontIdentity FontIdentity;
    SkTypeface_FCI* cachedFCTypeface = static_cast<SkTypeface_FCI*>(cachedTypeface);
    FontIdentity* identity = static_cast<FontIdentity*>(ctx);

    return cachedFCTypeface->getIdentity() == *identity;
}

///////////////////////////////////////////////////////////////////////////////

class SkFontMgr_FCI : public SkFontMgr {
    SkAutoTUnref<SkFontConfigInterface> fFCI;
    SkAutoTUnref<SkDataTable> fFamilyNames;
    SkTypeface_FreeType::Scanner fScanner;

    mutable SkMutex fMutex;
    mutable SkTypefaceCache fTFCache;

    // The value of maxSize here is a compromise between cache hits and cache size.
    // See https://crbug.com/424082#63 for reason for current size.
    static const size_t kMaxSize = 1 << 15;
    mutable SkFontRequestCache fCache;

public:
    SkFontMgr_FCI(SkFontConfigInterface* fci)
        : fFCI(fci)
        , fFamilyNames(fFCI->getFamilyNames())
        , fCache(kMaxSize)
    {
    }

protected:
    int onCountFamilies() const override
    {
        return fFamilyNames->count();
    }

    void onGetFamilyName(int index, SkString* familyName) const override
    {
        familyName->set(fFamilyNames->atStr(index));
    }

    SkFontStyleSet* onCreateStyleSet(int index) const override
    {
        return this->onMatchFamily(fFamilyNames->atStr(index));
    }

    SkFontStyleSet* onMatchFamily(const char familyName[]) const override
    {
        return new SkFontStyleSet_FCI();
    }

    SkTypeface* onMatchFamilyStyle(const char familyName[],
        const SkFontStyle&) const override { return nullptr; }
    SkTypeface* onMatchFamilyStyleCharacter(const char familyName[], const SkFontStyle&,
        const char* bcp47[], int bcp47Count,
        SkUnichar character) const override
    {
        return nullptr;
    }
    SkTypeface* onMatchFaceStyle(const SkTypeface*,
        const SkFontStyle&) const override { return nullptr; }

    SkTypeface* onCreateFromData(SkData*, int ttcIndex) const override { return nullptr; }

    SkTypeface* onCreateFromStream(SkStreamAsset* bareStream, int ttcIndex) const override
    {
        SkAutoTDelete<SkStreamAsset> stream(bareStream);
        const size_t length = stream->getLength();
        if (!length) {
            return nullptr;
        }
        if (length >= 1024 * 1024 * 1024) {
            return nullptr; // don't accept too large fonts (>= 1GB) for safety.
=======
#include "SkFontMgr.h"
#include "SkFontStyle.h"
#include "SkMath.h"
#include "SkMutex.h"
#include "SkString.h"
#include "SkTDArray.h"

// for now we pull these in directly. eventually we will solely rely on the
// SkFontConfigInterface instance.
#include <fontconfig/fontconfig.h>
#include <unistd.h>

namespace {

// Fontconfig is not threadsafe before 2.10.91.  Before that, we lock with a global mutex.
// See skia:1497 for background.
SK_DECLARE_STATIC_MUTEX(gFCMutex);
static bool gFCSafeToUse;

struct FCLocker {
    FCLocker() {
        if (FcGetVersion() < 21091) {  // We assume FcGetVersion() has always been thread safe.
            gFCMutex.acquire();
            fUnlock = true;
        } else {
            fUnlock = false;
        }
        gFCSafeToUse = true;
    }

    ~FCLocker() {
        if (fUnlock) {
            gFCSafeToUse = false;
            gFCMutex.release();
        }
    }

private:
    bool fUnlock;
};

} // namespace

// borrow this global from SkFontHost_fontconfig. eventually that file should
// go away, and be replaced with this one.
extern SkFontConfigInterface* SkFontHost_fontconfig_ref_global();
static SkFontConfigInterface* RefFCI() {
    return SkFontHost_fontconfig_ref_global();
}

// look for the last substring after a '/' and return that, or return null.
static const char* find_just_name(const char* str) {
    const char* last = strrchr(str, '/');
    return last ? last + 1 : NULL;
}

static bool is_lower(char c) {
    return c >= 'a' && c <= 'z';
}

static int get_int(FcPattern* pattern, const char field[]) {
    SkASSERT(gFCSafeToUse);
    int value;
    if (FcPatternGetInteger(pattern, field, 0, &value) != FcResultMatch) {
        value = SK_MinS32;
    }
    return value;
}

static const char* get_name(FcPattern* pattern, const char field[]) {
    SkASSERT(gFCSafeToUse);
    const char* name;
    if (FcPatternGetString(pattern, field, 0, (FcChar8**)&name) != FcResultMatch) {
        name = "";
    }
    return name;
}

static bool valid_pattern(FcPattern* pattern) {
    SkASSERT(gFCSafeToUse);
    FcBool is_scalable;
    if (FcPatternGetBool(pattern, FC_SCALABLE, 0, &is_scalable) != FcResultMatch || !is_scalable) {
        return false;
    }

    // fontconfig can also return fonts which are unreadable
    const char* c_filename = get_name(pattern, FC_FILE);
    if (0 == *c_filename) {
        return false;
    }
    if (access(c_filename, R_OK) != 0) {
        return false;
    }
    return true;
}

static bool match_name(FcPattern* pattern, const char family_name[]) {
    return !strcasecmp(family_name, get_name(pattern, FC_FAMILY));
}

static FcPattern** MatchFont(FcFontSet* font_set,
                             const char post_config_family[],
                             int* count) {
  // Older versions of fontconfig have a bug where they cannot select
  // only scalable fonts so we have to manually filter the results.

    FcPattern** iter = font_set->fonts;
    FcPattern** stop = iter + font_set->nfont;
    // find the first good match
    for (; iter < stop; ++iter) {
        if (valid_pattern(*iter)) {
            break;
        }
    }

    if (iter == stop || !match_name(*iter, post_config_family)) {
        return NULL;
    }

    FcPattern** firstIter = iter++;
    for (; iter < stop; ++iter) {
        if (!valid_pattern(*iter) || !match_name(*iter, post_config_family)) {
            break;
        }
    }

    *count = iter - firstIter;
    return firstIter;
}

class SkFontStyleSet_FC : public SkFontStyleSet {
public:
    SkFontStyleSet_FC(FcPattern** matches, int count);
    virtual ~SkFontStyleSet_FC();

    int count() override { return fRecCount; }
    void getStyle(int index, SkFontStyle*, SkString* style) override;
    SkTypeface* createTypeface(int index) override;
    SkTypeface* matchStyle(const SkFontStyle& pattern) override;

private:
    struct Rec {
        SkString    fStyleName;
        SkString    fFileName;
        SkFontStyle fStyle;
    };
    Rec* fRecs;
    int  fRecCount;
};

static int map_range(int value,
                     int old_min, int old_max, int new_min, int new_max) {
    SkASSERT(old_min < old_max);
    SkASSERT(new_min < new_max);
    return new_min + SkMulDiv(value - old_min,
                              new_max - new_min, old_max - old_min);
}

static SkFontStyle make_fontconfig_style(FcPattern* match) {
    int weight = get_int(match, FC_WEIGHT);
    int width = get_int(match, FC_WIDTH);
    int slant = get_int(match, FC_SLANT);
//    SkDebugf("old weight %d new weight %d\n", weight, map_range(weight, 0, 80, 0, 400));

    // fontconfig weight seems to be 0..200 or so, so we remap it here
    weight = map_range(weight, 0, 80, 0, 400);
    width = map_range(width, 0, 200, 0, 9);
    return SkFontStyle(weight, width, slant > 0 ? SkFontStyle::kItalic_Slant
                                                : SkFontStyle::kUpright_Slant);
}

SkFontStyleSet_FC::SkFontStyleSet_FC(FcPattern** matches, int count) {
    fRecCount = count;
    fRecs = SkNEW_ARRAY(Rec, count);
    for (int i = 0; i < count; ++i) {
        fRecs[i].fStyleName.set(get_name(matches[i], FC_STYLE));
        fRecs[i].fFileName.set(get_name(matches[i], FC_FILE));
        fRecs[i].fStyle = make_fontconfig_style(matches[i]);
    }
}

SkFontStyleSet_FC::~SkFontStyleSet_FC() {
    SkDELETE_ARRAY(fRecs);
}

void SkFontStyleSet_FC::getStyle(int index, SkFontStyle* style,
                                 SkString* styleName) {
    SkASSERT((unsigned)index < (unsigned)fRecCount);
    if (style) {
        *style = fRecs[index].fStyle;
    }
    if (styleName) {
        *styleName = fRecs[index].fStyleName;
    }
}

SkTypeface* SkFontStyleSet_FC::createTypeface(int index) {
    return NULL;
}

SkTypeface* SkFontStyleSet_FC::matchStyle(const SkFontStyle& pattern) {
    return NULL;
}

class SkFontMgr_fontconfig : public SkFontMgr {
    SkAutoTUnref<SkFontConfigInterface> fFCI;
    SkDataTable* fFamilyNames;
    SkTypeface_FreeType::Scanner fScanner;

public:
    SkFontMgr_fontconfig(SkFontConfigInterface* fci)
        : fFCI(fci)
        , fFamilyNames(fFCI->getFamilyNames()) {}

    virtual ~SkFontMgr_fontconfig() {
        SkSafeUnref(fFamilyNames);
    }

protected:
    int onCountFamilies() const override {
        return fFamilyNames->count();
    }

    void onGetFamilyName(int index, SkString* familyName) const override {
        familyName->set(fFamilyNames->atStr(index));
    }

    SkFontStyleSet* onCreateStyleSet(int index) const override {
        return this->onMatchFamily(fFamilyNames->atStr(index));
    }

    SkFontStyleSet* onMatchFamily(const char familyName[]) const override {
        FCLocker lock;

        FcPattern* pattern = FcPatternCreate();

        FcPatternAddString(pattern, FC_FAMILY, (FcChar8*)familyName);
#if 0
        FcPatternAddBool(pattern, FC_SCALABLE, FcTrue);
#endif
        FcConfigSubstitute(NULL, pattern, FcMatchPattern);
        FcDefaultSubstitute(pattern);

        const char* post_config_family = get_name(pattern, FC_FAMILY);

        FcResult result;
        FcFontSet* font_set = FcFontSort(0, pattern, 0, 0, &result);
        if (!font_set) {
            FcPatternDestroy(pattern);
            return NULL;
        }

        int count;
        FcPattern** match = MatchFont(font_set, post_config_family, &count);
        if (!match) {
            FcPatternDestroy(pattern);
            FcFontSetDestroy(font_set);
            return NULL;
        }

        FcPatternDestroy(pattern);

        SkTDArray<FcPattern*> trimmedMatches;
        for (int i = 0; i < count; ++i) {
            const char* justName = find_just_name(get_name(match[i], FC_FILE));
            if (!is_lower(*justName)) {
                *trimmedMatches.append() = match[i];
            }
        }

        SkFontStyleSet_FC* sset = SkNEW_ARGS(SkFontStyleSet_FC,
                                             (trimmedMatches.begin(),
                                              trimmedMatches.count()));
        return sset;
    }

    SkTypeface* onMatchFamilyStyle(const char familyName[],
                                   const SkFontStyle&) const override { return NULL; }
    SkTypeface* onMatchFamilyStyleCharacter(const char familyName[], const SkFontStyle&,
                                            const char* bcp47[], int bcp47Count,
                                            SkUnichar character) const override {
        return NULL;
    }
    SkTypeface* onMatchFaceStyle(const SkTypeface*,
                                 const SkFontStyle&) const override { return NULL; }

    SkTypeface* onCreateFromData(SkData*, int ttcIndex) const override { return NULL; }

    SkTypeface* onCreateFromStream(SkStreamAsset* bareStream, int ttcIndex) const override {
        SkAutoTDelete<SkStreamAsset> stream(bareStream);
        const size_t length = stream->getLength();
        if (!length) {
            return NULL;
        }
        if (length >= 1024 * 1024 * 1024) {
            return NULL;  // don't accept too large fonts (>= 1GB) for safety.
>>>>>>> miniblink49
        }

        // TODO should the caller give us the style or should we get it from freetype?
        SkFontStyle style;
        bool isFixedWidth = false;
<<<<<<< HEAD
        if (!fScanner.scanFont(stream, 0, nullptr, &style, &isFixedWidth, nullptr)) {
            return nullptr;
        }

        return SkTypeface_FCI::Create(style, isFixedWidth, stream.release(), ttcIndex);
    }

    SkTypeface* onCreateFromFile(const char path[], int ttcIndex) const override
    {
        SkAutoTDelete<SkStreamAsset> stream(SkStream::NewFromFile(path));
        return stream.get() ? this->createFromStream(stream.release(), ttcIndex) : nullptr;
    }

    SkTypeface* onLegacyCreateTypeface(const char requestedFamilyName[],
        SkFontStyle requestedStyle) const override
    {
        SkAutoMutexAcquire ama(fMutex);

        // Check if this request is already in the request cache.
        using Request = SkFontRequestCache::Request;
        SkAutoTDelete<Request> request(Request::Create(requestedFamilyName, requestedStyle));
        SkTypeface* face = fCache.findAndRef(request);
        if (face) {
            return face;
        }

        SkFontConfigInterface::FontIdentity identity;
        SkString outFamilyName;
        SkFontStyle outStyle;
        if (!fFCI->matchFamilyName(requestedFamilyName, requestedStyle,
                &identity, &outFamilyName, &outStyle)) {
            return nullptr;
        }

        // Check if a typeface with this FontIdentity is already in the FontIdentity cache.
        face = fTFCache.findByProcAndRef(find_by_FontIdentity, &identity);
        if (!face) {
            face = SkTypeface_FCI::Create(fFCI, identity, outFamilyName, outStyle);
            // Add this FontIdentity to the FontIdentity cache.
            fTFCache.add(face);
        }
        // Add this request to the request cache.
        fCache.add(face, request.release());

        return face;
    }
};

SK_API SkFontMgr* SkFontMgr_New_FCI(SkFontConfigInterface* fci)
{
    SkASSERT(fci);
    return new SkFontMgr_FCI(fci);
=======
        if (!fScanner.scanFont(stream, 0, NULL, &style, &isFixedWidth, NULL)) {
            return NULL;
        }

        SkTypeface* face = FontConfigTypeface::Create(style, isFixedWidth, stream.detach());
        return face;
    }

    SkTypeface* onCreateFromFile(const char path[], int ttcIndex) const override {
        SkAutoTDelete<SkStreamAsset> stream(SkStream::NewFromFile(path));
        return stream.get() ? this->createFromStream(stream.detach(), ttcIndex) : NULL;
    }

    SkTypeface* onLegacyCreateTypeface(const char familyName[],
                                       unsigned styleBits) const override {
        FCLocker lock;
        return FontConfigTypeface::LegacyCreateTypeface(familyName, (SkTypeface::Style)styleBits);
    }
};

SkFontMgr* SkFontMgr::Factory() {
    SkFontConfigInterface* fci = RefFCI();
    return fci ? SkNEW_ARGS(SkFontMgr_fontconfig, (fci)) : NULL;
>>>>>>> miniblink49
}
