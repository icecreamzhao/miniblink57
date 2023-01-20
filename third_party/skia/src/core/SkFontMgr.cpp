/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkFontMgr.h"
#include "SkFontDescriptor.h"
#include "SkOnce.h"
=======
#include "SkFontDescriptor.h"
#include "SkFontMgr.h"
#include "SkLazyPtr.h"
>>>>>>> miniblink49
#include "SkStream.h"
#include "SkTypes.h"

class SkFontStyle;
class SkTypeface;

class SkEmptyFontStyleSet : public SkFontStyleSet {
public:
    int count() override { return 0; }
<<<<<<< HEAD
    void getStyle(int, SkFontStyle*, SkString*) override
    {
        SkDEBUGFAIL("SkFontStyleSet::getStyle called on empty set");
    }
    SkTypeface* createTypeface(int index) override
    {
        SkDEBUGFAIL("SkFontStyleSet::createTypeface called on empty set");
        return nullptr;
    }
    SkTypeface* matchStyle(const SkFontStyle&) override
    {
        return nullptr;
    }
};

SkFontStyleSet* SkFontStyleSet::CreateEmpty() { return new SkEmptyFontStyleSet; }
=======
    void getStyle(int, SkFontStyle*, SkString*) override {
        SkDEBUGFAIL("SkFontStyleSet::getStyle called on empty set");
    }
    SkTypeface* createTypeface(int index) override {
        SkDEBUGFAIL("SkFontStyleSet::createTypeface called on empty set");
        return NULL;
    }
    SkTypeface* matchStyle(const SkFontStyle&) override {
        return NULL;
    }
};

SkFontStyleSet* SkFontStyleSet::CreateEmpty() {
    return SkNEW(SkEmptyFontStyleSet);
}
>>>>>>> miniblink49

///////////////////////////////////////////////////////////////////////////////

class SkEmptyFontMgr : public SkFontMgr {
protected:
<<<<<<< HEAD
    int onCountFamilies() const override
    {
        return 0;
    }
    void onGetFamilyName(int index, SkString* familyName) const override
    {
        SkDEBUGFAIL("onGetFamilyName called with bad index");
    }
    SkFontStyleSet* onCreateStyleSet(int index) const override
    {
        SkDEBUGFAIL("onCreateStyleSet called with bad index");
        return nullptr;
    }
    SkFontStyleSet* onMatchFamily(const char[]) const override
    {
=======
    int onCountFamilies() const override {
        return 0;
    }
    void onGetFamilyName(int index, SkString* familyName) const override {
        SkDEBUGFAIL("onGetFamilyName called with bad index");
    }
    SkFontStyleSet* onCreateStyleSet(int index) const override {
        SkDEBUGFAIL("onCreateStyleSet called with bad index");
        return NULL;
    }
    SkFontStyleSet* onMatchFamily(const char[]) const override {
>>>>>>> miniblink49
        return SkFontStyleSet::CreateEmpty();
    }

    virtual SkTypeface* onMatchFamilyStyle(const char[],
<<<<<<< HEAD
        const SkFontStyle&) const override
    {
        return nullptr;
    }
    virtual SkTypeface* onMatchFamilyStyleCharacter(const char familyName[],
        const SkFontStyle& style,
        const char* bcp47[],
        int bcp47Count,
        SkUnichar character) const override
    {
        return nullptr;
    }
    virtual SkTypeface* onMatchFaceStyle(const SkTypeface*,
        const SkFontStyle&) const override
    {
        return nullptr;
    }
    SkTypeface* onCreateFromData(SkData*, int) const override
    {
        return nullptr;
    }
    SkTypeface* onCreateFromStream(SkStreamAsset* stream, int) const override
    {
        delete stream;
        return nullptr;
    }
    SkTypeface* onCreateFromFile(const char[], int) const override
    {
        return nullptr;
    }
    SkTypeface* onLegacyCreateTypeface(const char[], SkFontStyle) const override
    {
        return nullptr;
    }
};

static SkFontStyleSet* emptyOnNull(SkFontStyleSet* fsset)
{
    if (nullptr == fsset) {
=======
                                           const SkFontStyle&) const override {
        return NULL;
    }
    virtual SkTypeface* onMatchFamilyStyleCharacter(const char familyName[],
                                                    const SkFontStyle& style,
                                                    const char* bcp47[],
                                                    int bcp47Count,
                                                    SkUnichar character) const override {
        return NULL;
    }
    virtual SkTypeface* onMatchFaceStyle(const SkTypeface*,
                                         const SkFontStyle&) const override {
        return NULL;
    }
    SkTypeface* onCreateFromData(SkData*, int) const override {
        return NULL;
    }
    SkTypeface* onCreateFromStream(SkStreamAsset* stream, int) const override {
        SkDELETE(stream);
        return NULL;
    }
    SkTypeface* onCreateFromFile(const char[], int) const override {
        return NULL;
    }
    SkTypeface* onLegacyCreateTypeface(const char [], unsigned) const override {
        return NULL;
    }
};

static SkFontStyleSet* emptyOnNull(SkFontStyleSet* fsset) {
    if (NULL == fsset) {
>>>>>>> miniblink49
        fsset = SkFontStyleSet::CreateEmpty();
    }
    return fsset;
}

<<<<<<< HEAD
int SkFontMgr::countFamilies() const
{
    return this->onCountFamilies();
}

void SkFontMgr::getFamilyName(int index, SkString* familyName) const
{
    this->onGetFamilyName(index, familyName);
}

SkFontStyleSet* SkFontMgr::createStyleSet(int index) const
{
    return emptyOnNull(this->onCreateStyleSet(index));
}

SkFontStyleSet* SkFontMgr::matchFamily(const char familyName[]) const
{
=======
int SkFontMgr::countFamilies() const {
    return this->onCountFamilies();
}

void SkFontMgr::getFamilyName(int index, SkString* familyName) const {
    this->onGetFamilyName(index, familyName);
}

SkFontStyleSet* SkFontMgr::createStyleSet(int index) const {
    return emptyOnNull(this->onCreateStyleSet(index));
}

SkFontStyleSet* SkFontMgr::matchFamily(const char familyName[]) const {
>>>>>>> miniblink49
    return emptyOnNull(this->onMatchFamily(familyName));
}

SkTypeface* SkFontMgr::matchFamilyStyle(const char familyName[],
<<<<<<< HEAD
    const SkFontStyle& fs) const
{
=======
                                        const SkFontStyle& fs) const {
>>>>>>> miniblink49
    return this->onMatchFamilyStyle(familyName, fs);
}

SkTypeface* SkFontMgr::matchFamilyStyleCharacter(const char familyName[], const SkFontStyle& style,
<<<<<<< HEAD
    const char* bcp47[], int bcp47Count,
    SkUnichar character) const
{
=======
                                                 const char* bcp47[], int bcp47Count,
                                                 SkUnichar character) const {
>>>>>>> miniblink49
    return this->onMatchFamilyStyleCharacter(familyName, style, bcp47, bcp47Count, character);
}

SkTypeface* SkFontMgr::matchFaceStyle(const SkTypeface* face,
<<<<<<< HEAD
    const SkFontStyle& fs) const
{
    return this->onMatchFaceStyle(face, fs);
}

SkTypeface* SkFontMgr::createFromData(SkData* data, int ttcIndex) const
{
    if (nullptr == data) {
        return nullptr;
=======
                                      const SkFontStyle& fs) const {
    return this->onMatchFaceStyle(face, fs);
}

SkTypeface* SkFontMgr::createFromData(SkData* data, int ttcIndex) const {
    if (NULL == data) {
        return NULL;
>>>>>>> miniblink49
    }
    return this->onCreateFromData(data, ttcIndex);
}

<<<<<<< HEAD
SkTypeface* SkFontMgr::createFromStream(SkStreamAsset* stream, int ttcIndex) const
{
    if (nullptr == stream) {
        return nullptr;
=======
SkTypeface* SkFontMgr::createFromStream(SkStreamAsset* stream, int ttcIndex) const {
    if (NULL == stream) {
        return NULL;
>>>>>>> miniblink49
    }
    return this->onCreateFromStream(stream, ttcIndex);
}

<<<<<<< HEAD
SkTypeface* SkFontMgr::createFromStream(SkStreamAsset* stream, const FontParameters& params) const
{
    if (nullptr == stream) {
        return nullptr;
    }
    return this->onCreateFromStream(stream, params);
}

SkTypeface* SkFontMgr::createFromFontData(SkFontData* data) const
{
    if (nullptr == data) {
        return nullptr;
=======
SkTypeface* SkFontMgr::createFromFontData(SkFontData* data) const {
    if (NULL == data) {
        return NULL;
>>>>>>> miniblink49
    }
    return this->onCreateFromFontData(data);
}

// This implementation is temporary until it can be made pure virtual.
<<<<<<< HEAD
SkTypeface* SkFontMgr::onCreateFromStream(SkStreamAsset* stream, const FontParameters& p) const
{
    return this->createFromStream(stream, p.getCollectionIndex());
}

// This implementation is temporary until it can be made pure virtual.
SkTypeface* SkFontMgr::onCreateFromFontData(SkFontData* data) const
{
=======
SkTypeface* SkFontMgr::onCreateFromFontData(SkFontData* data) const {
>>>>>>> miniblink49
    SkTypeface* ret = this->createFromStream(data->detachStream(), data->getIndex());
    delete data;
    return ret;
}

<<<<<<< HEAD
SkTypeface* SkFontMgr::createFromFile(const char path[], int ttcIndex) const
{
    if (nullptr == path) {
        return nullptr;
=======
SkTypeface* SkFontMgr::createFromFile(const char path[], int ttcIndex) const {
    if (NULL == path) {
        return NULL;
>>>>>>> miniblink49
    }
    return this->onCreateFromFile(path, ttcIndex);
}

<<<<<<< HEAD
SkTypeface* SkFontMgr::legacyCreateTypeface(const char familyName[], SkFontStyle style) const
{
    return this->onLegacyCreateTypeface(familyName, style);
}

SkFontMgr* SkFontMgr::RefDefault()
{
    static SkOnce once;
    static SkFontMgr* singleton;

    once([] {
        SkFontMgr* fm = SkFontMgr::Factory();
        singleton = fm ? fm : new SkEmptyFontMgr;
    });
    return SkRef(singleton);
}

/**
* Width has the greatest priority.
* If the value of pattern.width is 5 (normal) or less,
*    narrower width values are checked first, then wider values.
* If the value of pattern.width is greater than 5 (normal),
*    wider values are checked first, followed by narrower values.
*
* Italic/Oblique has the next highest priority.
* If italic requested and there is some italic font, use it.
* If oblique requested and there is some oblique font, use it.
* If italic requested and there is some oblique font, use it.
* If oblique requested and there is some italic font, use it.
*
* Exact match.
* If pattern.weight < 400, weights below pattern.weight are checked
*   in descending order followed by weights above pattern.weight
*   in ascending order until a match is found.
* If pattern.weight > 500, weights above pattern.weight are checked
*   in ascending order followed by weights below pattern.weight
*   in descending order until a match is found.
* If pattern.weight is 400, 500 is checked first
*   and then the rule for pattern.weight < 400 is used.
* If pattern.weight is 500, 400 is checked first
*   and then the rule for pattern.weight < 400 is used.
*/
SkTypeface* SkFontStyleSet::matchStyleCSS3(const SkFontStyle& pattern)
{
    int count = this->count();
    if (0 == count) {
        return nullptr;
    }

    struct Score {
        int score;
        int index;
        Score& operator+=(int rhs)
        {
            this->score += rhs;
            return *this;
        }
        Score& operator<<=(int rhs)
        {
            this->score <<= rhs;
            return *this;
        }
        bool operator<(const Score& that) { return this->score < that.score; }
    };

    Score maxScore = { 0, 0 };
    for (int i = 0; i < count; ++i) {
        SkFontStyle current;
        this->getStyle(i, &current, nullptr);
        Score currentScore = { 0, i };

        // CSS stretch / SkFontStyle::Width
        // Takes priority over everything else.
        if (pattern.width() <= SkFontStyle::kNormal_Width) {
            if (current.width() <= pattern.width()) {
                currentScore += 10 - pattern.width() + current.width();
            } else {
                currentScore += 10 - current.width();
            }
        } else {
            if (current.width() > pattern.width()) {
                currentScore += 10 + pattern.width() - current.width();
            } else {
                currentScore += current.width();
            }
        }
        currentScore <<= 8;

        // CSS style (normal, italic, oblique) / SkFontStyle::Slant (upright, italic, oblique)
        // Takes priority over all valid weights.
        static_assert(SkFontStyle::kUpright_Slant == 0 && SkFontStyle::kItalic_Slant == 1 && SkFontStyle::kOblique_Slant == 2,
            "SkFontStyle::Slant values not as required.");
        SkASSERT(0 <= pattern.slant() && pattern.slant() <= 2 && 0 <= current.slant() && current.slant() <= 2);
        static const int score[3][3] = {
            /*               Upright Italic Oblique  [current]*/
            /*   Upright */ { 3, 1, 2 },
            /*   Italic  */ { 1, 3, 2 },
            /*   Oblique */ { 1, 2, 3 },
            /* [pattern] */
        };
        currentScore += score[pattern.slant()][current.slant()];
        currentScore <<= 8;

        // Synthetics (weight, style) [no stretch synthetic?]

        // CSS weight / SkFontStyle::Weight
        // The 'closer' to the target weight, the higher the score.
        // 1000 is the 'heaviest' recognized weight
        if (pattern.weight() == current.weight()) {
            currentScore += 1000;
        } else if (pattern.weight() <= 500) {
            if (400 <= pattern.weight() && pattern.weight() < 450) {
                if (450 <= current.weight() && current.weight() <= 500) {
                    // Artificially boost the 500 weight.
                    // TODO: determine correct number to use.
                    currentScore += 500;
                }
            }
            if (current.weight() <= pattern.weight()) {
                currentScore += 1000 - pattern.weight() + current.weight();
            } else {
                currentScore += 1000 - current.weight();
            }
        } else if (pattern.weight() > 500) {
            if (current.weight() > pattern.weight()) {
                currentScore += 1000 + pattern.weight() - current.weight();
            } else {
                currentScore += current.weight();
            }
        }

        if (maxScore < currentScore) {
            maxScore = currentScore;
        }
    }

    return this->createTypeface(maxScore.index);
=======
SkTypeface* SkFontMgr::legacyCreateTypeface(const char familyName[],
                                            unsigned styleBits) const {
    return this->onLegacyCreateTypeface(familyName, styleBits);
}

// As a template argument this must have external linkage.
SkFontMgr* sk_fontmgr_create_default() {
    SkFontMgr* fm = SkFontMgr::Factory();
    return fm ? fm : SkNEW(SkEmptyFontMgr);
}

SK_DECLARE_STATIC_LAZY_PTR(SkFontMgr, singleton, sk_fontmgr_create_default);

SkFontMgr* SkFontMgr::RefDefault() {
    return SkRef(singleton.get());
>>>>>>> miniblink49
}
