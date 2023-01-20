/*
 * Copyright (c) 2006, 2007, 2008, 2009 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "SkFontMgr.h"
#include "SkStream.h"
#include "SkTypeface.h"
#include "platform/Language.h"
#include "platform/fonts/AcceptLanguagesResolver.h"
#include "platform/fonts/AlternateFontFamily.h"
#include "platform/fonts/FontCache.h"
#include "platform/fonts/FontDescription.h"
#include "platform/fonts/FontFaceCreationParams.h"
#include "platform/fonts/SimpleFontData.h"
#include "platform/graphics/skia/SkiaUtils.h"
#include "public/platform/Platform.h"
#include "public/platform/linux/WebSandboxSupport.h"
#include "wtf/Assertions.h"
#include "wtf/PtrUtil.h"
#include "wtf/text/AtomicString.h"
#include "wtf/text/CString.h"
#include <memory>
#include "third_party/fontconfig/src/fontconfig/fontconfig.h"
//#include <unicode/locid.h>

#if !OS(WIN) && !OS(ANDROID)
#include "SkFontConfigInterface.h"

static PassRefPtr<SkTypeface> typefaceForFontconfigInterfaceIdAndTtcIndex(int fontconfigInterfaceId, int ttcIndex)
{
    SkAutoTUnref<SkFontConfigInterface> fci(SkFontConfigInterface::RefGlobal());
    SkFontConfigInterface::FontIdentity fontIdentity;
    fontIdentity.fID = fontconfigInterfaceId;
    fontIdentity.fTTCIndex = ttcIndex;
    return blink::fromSkSp(fci->makeTypeface(fontIdentity));
}
#endif

namespace blink {

#if OS(ANDROID) || OS(LINUX)
// Android special locale for retrieving the color emoji font
// based on the proposed changes in UTR #51 for introducing
// an Emoji script code:
// http://www.unicode.org/reports/tr51/proposed.html#Emoji_Script
static const char* kAndroidColorEmojiLocale = "und-Zsye";

// This function is called on android or when we are emulating android fonts on linux and the
// embedder has overriden the default fontManager with WebFontRendering::setSkiaFontMgr.
// static
AtomicString FontCache::getFamilyNameForCharacter(SkFontMgr* fm, UChar32 c, const FontDescription& fontDescription, FontFallbackPriority fallbackPriority)
{
    ASSERT(fm);

    const size_t kMaxLocales = 4;
    const char* bcp47Locales[kMaxLocales];
    size_t localeCount = 0;

    if (fallbackPriority == FontFallbackPriority::EmojiEmoji) {
        bcp47Locales[localeCount++] = kAndroidColorEmojiLocale;
    }
    if (const char* hanLocale = AcceptLanguagesResolver::preferredHanSkFontMgrLocale())
        bcp47Locales[localeCount++] = hanLocale;
    CString defaultLocale = toSkFontMgrLocale(defaultLanguage());
    bcp47Locales[localeCount++] = defaultLocale.data();
    CString fontLocale;

    if (!fontDescription.locale()->localeString().isEmpty()) {
        fontLocale = toSkFontMgrLocale(fontDescription.locale()->localeString());
        bcp47Locales[localeCount++] = fontLocale.data();
    }
    ASSERT_WITH_SECURITY_IMPLICATION(localeCount < kMaxLocales);
    RefPtr<SkTypeface> typeface = adoptRef(fm->matchFamilyStyleCharacter(0, SkFontStyle(), bcp47Locales, localeCount, c));
    if (!typeface)
        return emptyAtom;

    SkString skiaFamilyName;
    typeface->getFamilyName(&skiaFamilyName);
    return skiaFamilyName.c_str();
}
#endif

void FontCache::platformInit()
{
}

PassRefPtr<SimpleFontData> FontCache::fallbackOnStandardFontStyle(
    const FontDescription& fontDescription, UChar32 character)
{
    FontDescription substituteDescription(fontDescription);
    substituteDescription.setStyle(FontStyleNormal);
    substituteDescription.setWeight(FontWeightNormal);

    FontFaceCreationParams creationParams(substituteDescription.family().family());
    FontPlatformData* substitutePlatformData = getFontPlatformData(substituteDescription, creationParams);
    if (substitutePlatformData && substitutePlatformData->fontContainsCharacter(character)) {
        FontPlatformData platformData = FontPlatformData(*substitutePlatformData);
        platformData.setSyntheticBold(fontDescription.weight() >= FontWeight600);
        platformData.setSyntheticItalic(fontDescription.style() == FontStyleItalic || fontDescription.style() == FontStyleOblique);
        return fontDataFromFontPlatformData(&platformData, DoNotRetain);
    }

    return nullptr;
}

static String getDefaultFontList()
{
    String defaultFont;

    FcBool result = FcInit();
    FcConfig* config = FcConfigGetCurrent();
    FcConfigSetRescanInterval(config, 0);

    // show the fonts (debugging)
    FcPattern* pat = FcPatternCreate();
    FcObjectSet* os = FcObjectSetBuild(FC_FAMILY, FC_STYLE, FC_LANG, (char*)0);
    FcFontSet* fs = FcFontList(config, pat, os);

    printf("Total fonts: %d\n", fs->nfont);

    for (int i = 0; fs && i < fs->nfont; i++) {
        FcPattern* font = fs->fonts[i];
        FcChar8* str = FcNameUnparse(font);

        // Noto Sans CJK TC,Noto Sans CJK TC Bold:style=Regular,normal:lang=aa|ay
        //printf("Font: %d, [%s]\n", i, str);

        String fontStr(str, strlen((const char*)str));
        free(str);
        Vector<String> spli;
        fontStr.split(u16(':'), false, spli);

        if (spli.size() != 3)
            continue;

        if (WTF::kNotFound == spli[1].find("normal") && WTF::kNotFound == spli[1].find("Regular"))
            continue;

        if (WTF::kNotFound != spli[2].find("zh-cn")) {
            defaultFont = spli[0];
            break;
        }        
    }
    if (fs)
        FcFontSetDestroy(fs);

    if (WTF::kNotFound == defaultFont.find(','))
        return defaultFont;

    Vector<String> spli;
    defaultFont.split(u16(','), false, spli);
    defaultFont = spli[0];

    printf("getDefaultFontList: %s\n", defaultFont.utf8().data());

    return defaultFont;
}

PassRefPtr<SimpleFontData> FontCache::getLastResortFallbackFont(const FontDescription& description, ShouldRetain shouldRetain)
{
    const FontFaceCreationParams fallbackCreationParams(getFallbackFontFamily(description));
    const FontPlatformData* fontPlatformData = getFontPlatformData(description, fallbackCreationParams);

#if !defined(WIN32)
    // /usr/share/fonts/opentype/noto

//     const char* defaultFonts[] = {
//         "Noto Sans CJK SC", "WenQuanYi Zen Hei", "FreeSerif", "Sarai", nullptr
//     };
//     for (int i = 0; defaultFonts[i]; ++i) {
//         FontFaceCreationParams params(AtomicString(defaultFonts[i]));
//         fontPlatformData = getFontPlatformData(description, params);
//         if (fontPlatformData)
//             break;
//     }
    if (!fontPlatformData) {
        String defaultFont = getDefaultFontList();
        if (!defaultFont.isEmpty()) {
            AtomicString family(defaultFont);
            FontFaceCreationParams params(family);
            fontPlatformData = getFontPlatformData(description, params);
            printf("FontCache::getLastResortFallbackFont~: %p\n", fontPlatformData);
        }
    }
#endif

    // We should at least have Sans or Arial which is the last resort fallback of SkFontHost ports.
    if (!fontPlatformData) {
        DEFINE_STATIC_LOCAL(const FontFaceCreationParams, sansCreationParams, (AtomicString("Sans")));
        fontPlatformData = getFontPlatformData(description, sansCreationParams);
    }
    if (!fontPlatformData) {
        DEFINE_STATIC_LOCAL(const FontFaceCreationParams, arialCreationParams, (AtomicString("Arial")));
        fontPlatformData = getFontPlatformData(description, arialCreationParams);
    }
#if OS(WIN)
    // Try some more Windows-specific fallbacks.
    if (!fontPlatformData) {
        DEFINE_STATIC_LOCAL(const FontFaceCreationParams, msuigothicCreationParams, (AtomicString("MS UI Gothic")));
        fontPlatformData = getFontPlatformData(description, msuigothicCreationParams);
    }
    if (!fontPlatformData) {
        DEFINE_STATIC_LOCAL(const FontFaceCreationParams, mssansserifCreationParams, (AtomicString("Microsoft Sans Serif")));
        fontPlatformData = getFontPlatformData(description, mssansserifCreationParams);
    }
#endif

    ASSERT(fontPlatformData);
    return fontDataFromFontPlatformData(fontPlatformData, shouldRetain);
}

PassRefPtr<SkTypeface> FontCache::createTypeface(const FontDescription& fontDescription, const FontFaceCreationParams& creationParams, CString& name)
{
#if !OS(WIN) && !OS(ANDROID)
    if (creationParams.creationType() == CreateFontByFciIdAndTtcIndex) {
        if (Platform::current()->sandboxSupport())
            return typefaceForFontconfigInterfaceIdAndTtcIndex(creationParams.fontconfigInterfaceId(), creationParams.ttcIndex());
        return fromSkSp(SkTypeface::MakeFromFile(creationParams.filename().data(), creationParams.ttcIndex()));
    }
#endif

    AtomicString family = creationParams.family();
    // If we're creating a fallback font (e.g. "-webkit-monospace"), convert the name into
    // the fallback name (like "monospace") that fontconfig understands.
    if (!family.length() || family.startsWith("-webkit-")) {
        name = getFallbackFontFamily(fontDescription).getString().utf8();
    } else {
        // convert the name to utf8
        name = family.utf8();
    }

#if OS(WIN)
    if (s_sideloadedFonts) {
        HashMap<String, RefPtr<SkTypeface>>::iterator sideloadedFont = s_sideloadedFonts->find(name.data());
        if (sideloadedFont != s_sideloadedFonts->end())
            return sideloadedFont->value;
    }
#endif

#if OS(LINUX) || OS(WIN)
    // On linux if the fontManager has been overridden then we should be calling the embedder
    // provided font Manager rather than calling SkTypeface::CreateFromName which may redirect the
    // call to the default font Manager.
    // On Windows the font manager is always present.
    if (m_fontManager)
        return adoptRef(m_fontManager->matchFamilyStyle(name.data(), fontDescription.skiaFontStyle()));
#endif

    // FIXME: Use m_fontManager, matchFamilyStyle instead of
    // legacyCreateTypeface on all platforms.
    RefPtr<SkFontMgr> fm = adoptRef(SkFontMgr::RefDefault());
    return adoptRef(fm->legacyCreateTypeface(name.data(),
        fontDescription.skiaFontStyle()));
}

#if !OS(WIN)
std::unique_ptr<FontPlatformData> FontCache::createFontPlatformData(const FontDescription& fontDescription,
    const FontFaceCreationParams& creationParams, float fontSize)
{
    CString name;
    RefPtr<SkTypeface> tf(createTypeface(fontDescription, creationParams, name));
    if (!tf)
        return nullptr;

    return WTF::wrapUnique(new FontPlatformData(tf,
        name.data(),
        fontSize,
        (fontDescription.weight() > 200 + tf->fontStyle().weight()) || fontDescription.isSyntheticBold(),
        ((fontDescription.style() == FontStyleItalic || fontDescription.style() == FontStyleOblique) && !tf->isItalic()) || fontDescription.isSyntheticItalic(),
        fontDescription.orientation()));
}
#endif // !OS(WIN)

} // namespace blink
