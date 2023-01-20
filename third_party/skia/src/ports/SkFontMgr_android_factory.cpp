/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD
#include "SkTypes.h"
#if defined(SK_BUILD_FOR_ANDROID)
=======
>>>>>>> miniblink49

#include "SkFontMgr.h"
#include "SkFontMgr_android.h"

// For test only.
<<<<<<< HEAD
static const char* gTestFontsXml = nullptr;
static const char* gTestFallbackFontsXml = nullptr;
static const char* gTestBasePath = nullptr;

void SkUseTestFontConfigFile(const char* fontsXml, const char* fallbackFontsXml,
    const char* basePath)
=======
static const char* gTestFontsXml = NULL;
static const char* gTestFallbackFontsXml = NULL;
static const char* gTestBasePath = NULL;

void SkUseTestFontConfigFile(const char* fontsXml, const char* fallbackFontsXml,
                             const char* basePath)
>>>>>>> miniblink49
{
    gTestFontsXml = fontsXml;
    gTestFallbackFontsXml = fallbackFontsXml;
    gTestBasePath = basePath;
    SkASSERT(gTestFontsXml);
    SkASSERT(gTestFallbackFontsXml);
    SkASSERT(gTestBasePath);
    SkDEBUGF(("Test BasePath: %s Fonts: %s FallbackFonts: %s\n",
<<<<<<< HEAD
        gTestBasePath, gTestFontsXml, gTestFallbackFontsXml));
}

SkFontMgr* SkFontMgr::Factory()
{
=======
              gTestBasePath, gTestFontsXml, gTestFallbackFontsXml));
}

SkFontMgr* SkFontMgr::Factory() {
>>>>>>> miniblink49
    // These globals exist so that Chromium can override the environment.
    // TODO: these globals need to be removed, and Chromium use SkFontMgr_New_Android instead.
    if ((gTestFontsXml || gTestFallbackFontsXml) && gTestBasePath) {
        SkFontMgr_Android_CustomFonts custom = {
            SkFontMgr_Android_CustomFonts::kOnlyCustom,
            gTestBasePath,
            gTestFontsXml,
<<<<<<< HEAD
            gTestFallbackFontsXml,
            false /* fIsolated */
=======
            gTestFallbackFontsXml
>>>>>>> miniblink49
        };
        return SkFontMgr_New_Android(&custom);
    }

<<<<<<< HEAD
    return SkFontMgr_New_Android(nullptr);
}

#endif //defined(SK_BUILD_FOR_ANDROID)
=======
    return SkFontMgr_New_Android(NULL);
}
>>>>>>> miniblink49
