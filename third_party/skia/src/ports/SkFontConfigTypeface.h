/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkFontConfigInterface.h"
#include "SkFontHost_FreeType_common.h"
#include "SkStream.h"
#include "SkTypefaceCache.h"

class SkFontDescriptor;

<<<<<<< HEAD
class SkTypeface_FCI : public SkTypeface_FreeType {
    SkAutoTUnref<SkFontConfigInterface> fFCI;
=======
class FontConfigTypeface : public SkTypeface_FreeType {
>>>>>>> miniblink49
    SkFontConfigInterface::FontIdentity fIdentity;
    SkString fFamilyName;
    SkAutoTDelete<SkStreamAsset> fLocalStream;

public:
<<<<<<< HEAD
    static SkTypeface_FCI* Create(SkFontConfigInterface* fci,
        const SkFontConfigInterface::FontIdentity& fi,
        const SkString& familyName,
        const SkFontStyle& style)
    {
        return new SkTypeface_FCI(fci, fi, familyName, style);
    }

    static SkTypeface_FCI* Create(const SkFontStyle& style, bool fixedWidth,
        SkStreamAsset* localStream, int index)
    {
        return new SkTypeface_FCI(style, fixedWidth, localStream, index);
    }

    const SkFontConfigInterface::FontIdentity& getIdentity() const
    {
        return fIdentity;
    }

    SkStreamAsset* getLocalStream() const
    {
        return fLocalStream.get();
    }

    bool isFamilyName(const char* name) const
    {
        return fFamilyName.equals(name);
    }

protected:
    SkTypeface_FCI(SkFontConfigInterface* fci,
        const SkFontConfigInterface::FontIdentity& fi,
        const SkString& familyName,
        const SkFontStyle& style)
        : INHERITED(style, SkTypefaceCache::NewFontID(), false)
        , fFCI(SkRef(fci))
        , fIdentity(fi)
        , fFamilyName(familyName)
        , fLocalStream(nullptr)
    {
    }

    SkTypeface_FCI(const SkFontStyle& style, bool fixedWidth, SkStreamAsset* localStream, int index)
        : INHERITED(style, SkTypefaceCache::NewFontID(), fixedWidth)
        , fLocalStream(localStream)
    {
        fIdentity.fTTCIndex = index;
    }

    void onGetFamilyName(SkString* familyName) const override { *familyName = fFamilyName; }
=======
    static FontConfigTypeface* Create(const SkFontStyle& style,
                                      const SkFontConfigInterface::FontIdentity& fi,
                                      const SkString& familyName) {
        return SkNEW_ARGS(FontConfigTypeface, (style, fi, familyName));
    }

    static FontConfigTypeface* Create(const SkFontStyle& style, bool fixedWidth,
                                      SkStreamAsset* localStream) {
        return SkNEW_ARGS(FontConfigTypeface, (style, fixedWidth, localStream));
    }

    const SkFontConfigInterface::FontIdentity& getIdentity() const {
        return fIdentity;
    }

    SkStreamAsset* getLocalStream() const { return fLocalStream.get(); }

    bool isFamilyName(const char* name) const {
        return fFamilyName.equals(name);
    }

    static SkTypeface* LegacyCreateTypeface(const char familyName[], SkTypeface::Style);

protected:
    FontConfigTypeface(const SkFontStyle& style,
                       const SkFontConfigInterface::FontIdentity& fi,
                       const SkString& familyName)
            : INHERITED(style, SkTypefaceCache::NewFontID(), false)
            , fIdentity(fi)
            , fFamilyName(familyName)
            , fLocalStream(NULL) {}

    FontConfigTypeface(const SkFontStyle& style, bool fixedWidth, SkStreamAsset* localStream)
            : INHERITED(style, SkTypefaceCache::NewFontID(), fixedWidth)
            , fLocalStream(localStream) {
        // we default to empty fFamilyName and fIdentity
    }

    void onGetFamilyName(SkString* familyName) const override;
>>>>>>> miniblink49
    void onGetFontDescriptor(SkFontDescriptor*, bool*) const override;
    SkStreamAsset* onOpenStream(int* ttcIndex) const override;

private:
    typedef SkTypeface_FreeType INHERITED;
};
