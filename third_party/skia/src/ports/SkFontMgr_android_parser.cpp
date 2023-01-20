/*
 * Copyright 2011 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
// Despite the name and location, this is portable code.

#include "SkFontMgr_android_parser.h"
#include "SkFixed.h"
#include "SkFontMgr.h"
#include "SkStream.h"
#include "SkTDArray.h"
#include "SkTLogic.h"
#include "SkTSearch.h"
#include "SkTemplates.h"

#include <dirent.h>
#include <expat.h>

#include <stdlib.h>
#include <string.h>
=======
#include "SkFontMgr_android_parser.h"
#include "SkStream.h"
#include "SkTDArray.h"
#include "SkTSearch.h"
#include "SkTypeface.h"

#include <expat.h>
#include <dirent.h>

#include <stdlib.h>
>>>>>>> miniblink49

#define LMP_SYSTEM_FONTS_FILE "/system/etc/fonts.xml"
#define OLD_SYSTEM_FONTS_FILE "/system/etc/system_fonts.xml"
#define FALLBACK_FONTS_FILE "/system/etc/fallback_fonts.xml"
#define VENDOR_FONTS_FILE "/vendor/etc/fallback_fonts.xml"

#define LOCALE_FALLBACK_FONTS_SYSTEM_DIR "/system/etc"
#define LOCALE_FALLBACK_FONTS_VENDOR_DIR "/vendor/etc"
#define LOCALE_FALLBACK_FONTS_PREFIX "fallback_fonts-"
#define LOCALE_FALLBACK_FONTS_SUFFIX ".xml"

#ifndef SK_FONT_FILE_PREFIX
<<<<<<< HEAD
#define SK_FONT_FILE_PREFIX "/fonts/"
=======
#    define SK_FONT_FILE_PREFIX "/fonts/"
>>>>>>> miniblink49
#endif

/**
 * This file contains TWO 'familyset' handlers:
 * One for JB and earlier which works with
 *   /system/etc/system_fonts.xml
 *   /system/etc/fallback_fonts.xml
 *   /vendor/etc/fallback_fonts.xml
 *   /system/etc/fallback_fonts-XX.xml
 *   /vendor/etc/fallback_fonts-XX.xml
 * and the other for LMP and later which works with
 *   /system/etc/fonts.xml
 *
 * If the 'familyset' 'version' attribute is 21 or higher the LMP parser is used, otherwise the JB.
 */

struct FamilyData;

struct TagHandler {
    /** Called at the start tag.
     *  Called immediately after the parent tag retuns this handler from a call to 'tag'.
     *  Allows setting up for handling the tag content and processing attributes.
<<<<<<< HEAD
     *  If nullptr, will not be called.
=======
     *  If NULL, will not be called.
>>>>>>> miniblink49
     */
    void (*start)(FamilyData* data, const char* tag, const char** attributes);

    /** Called at the end tag.
     *  Allows post-processing of any accumulated information.
     *  This will be the last call made in relation to the current tag.
<<<<<<< HEAD
     *  If nullptr, will not be called.
=======
     *  If NULL, will not be called.
>>>>>>> miniblink49
     */
    void (*end)(FamilyData* data, const char* tag);

    /** Called when a nested tag is encountered.
     *  This is responsible for determining how to handle the tag.
<<<<<<< HEAD
     *  If the tag is not recognized, return nullptr to skip the tag.
     *  If nullptr, all nested tags will be skipped.
=======
     *  If the tag is not recognized, return NULL to skip the tag.
     *  If NULL, all nested tags will be skipped.
>>>>>>> miniblink49
     */
    const TagHandler* (*tag)(FamilyData* data, const char* tag, const char** attributes);

    /** The character handler for this tag.
     *  This is only active for character data contained directly in this tag (not sub-tags).
     *  The first parameter will be castable to a FamilyData*.
<<<<<<< HEAD
     *  If nullptr, any character data in this tag will be ignored.
=======
     *  If NULL, any character data in this tag will be ignored.
>>>>>>> miniblink49
     */
    XML_CharacterDataHandler chars;
};

/** Represents the current parsing state. */
struct FamilyData {
    FamilyData(XML_Parser parser, SkTDArray<FontFamily*>& families,
<<<<<<< HEAD
        const SkString& basePath, bool isFallback, const char* filename,
        const TagHandler* topLevelHandler)
        : fParser(parser)
        , fFamilies(families)
        , fCurrentFamily(nullptr)
        , fCurrentFontInfo(nullptr)
=======
               const SkString& basePath, bool isFallback, const char* filename,
               const TagHandler* topLevelHandler)
        : fParser(parser)
        , fFamilies(families)
        , fCurrentFamily(NULL)
        , fCurrentFontInfo(NULL)
>>>>>>> miniblink49
        , fVersion(0)
        , fBasePath(basePath)
        , fIsFallback(isFallback)
        , fFilename(filename)
        , fDepth(1)
        , fSkip(0)
<<<<<<< HEAD
        , fHandler(&topLevelHandler, 1) {};

    XML_Parser fParser; // The expat parser doing the work, owned by caller
    SkTDArray<FontFamily*>& fFamilies; // The array to append families, owned by caller
    SkAutoTDelete<FontFamily> fCurrentFamily; // The family being created, owned by this
    FontFileInfo* fCurrentFontInfo; // The fontInfo being created, owned by fCurrentFamily
    int fVersion; // The version of the file parsed.
    const SkString& fBasePath; // The current base path.
    const bool fIsFallback; // Indicates the file being parsed is a fallback file
    const char* fFilename; // The name of the file currently being parsed.

    int fDepth; // The current element depth of the parse.
    int fSkip; // The depth to stop skipping, 0 if not skipping.
    SkTDArray<const TagHandler*> fHandler; // The stack of current tag handlers.
};

static bool memeq(const char* s1, const char* s2, size_t n1, size_t n2)
{
=======
        , fHandler(&topLevelHandler, 1)
    { };

    XML_Parser fParser;                       // The expat parser doing the work, owned by caller
    SkTDArray<FontFamily*>& fFamilies;        // The array to append families, owned by caller
    SkAutoTDelete<FontFamily> fCurrentFamily; // The family being created, owned by this
    FontFileInfo* fCurrentFontInfo;           // The fontInfo being created, owned by fCurrentFamily
    int fVersion;                             // The version of the file parsed.
    const SkString& fBasePath;                // The current base path.
    const bool fIsFallback;                   // Indicates the file being parsed is a fallback file
    const char* fFilename;                    // The name of the file currently being parsed.

    int fDepth;                               // The current element depth of the parse.
    int fSkip;                                // The depth to stop skipping, 0 if not skipping.
    SkTDArray<const TagHandler*> fHandler;    // The stack of current tag handlers.
};

static bool memeq(const char* s1, const char* s2, size_t n1, size_t n2) {
>>>>>>> miniblink49
    return n1 == n2 && 0 == memcmp(s1, s2, n1);
}
#define MEMEQ(c, s, n) memeq(c, s, sizeof(c) - 1, n)

<<<<<<< HEAD
#define ATTS_NON_NULL(a, i) (a[i] != nullptr && a[i + 1] != nullptr)

#define SK_FONTMGR_ANDROID_PARSER_PREFIX "[SkFontMgr Android Parser] "

#define SK_FONTCONFIGPARSER_WARNING(message, ...) SkDebugf(              \
    SK_FONTMGR_ANDROID_PARSER_PREFIX "%s:%d:%d: warning: " message "\n", \
    self->fFilename,                                                     \
    XML_GetCurrentLineNumber(self->fParser),                             \
    XML_GetCurrentColumnNumber(self->fParser),                           \
    ##__VA_ARGS__);

static bool is_whitespace(char c)
{
    return c == ' ' || c == '\n' || c == '\r' || c == '\t';
}

static void trim_string(SkString* s)
{
    char* str = s->writable_str();
    const char* start = str; // start is inclusive
    const char* end = start + s->size(); // end is exclusive
    while (is_whitespace(*start)) {
        ++start;
    }
    if (start != end) {
        --end; // make end inclusive
        while (is_whitespace(*end)) {
            --end;
        }
        ++end; // make end exclusive
=======
#define ATTS_NON_NULL(a, i) (a[i] != NULL && a[i+1] != NULL)

#define SK_FONTMGR_ANDROID_PARSER_PREFIX "[SkFontMgr Android Parser] "

#define SK_FONTCONFIGPARSER_WARNING(message, ...) SkDebugf( \
    SK_FONTMGR_ANDROID_PARSER_PREFIX "%s:%d:%d: warning: " message "\n", \
    self->fFilename, \
    XML_GetCurrentLineNumber(self->fParser), \
    XML_GetCurrentColumnNumber(self->fParser), \
    ##__VA_ARGS__);

static bool is_whitespace(char c) {
    return c == ' ' || c == '\n'|| c == '\r' || c == '\t';
}

static void trim_string(SkString* s) {
    char* str = s->writable_str();
    const char* start = str;  // start is inclusive
    const char* end = start + s->size();  // end is exclusive
    while (is_whitespace(*start)) { ++start; }
    if (start != end) {
        --end;  // make end inclusive
        while (is_whitespace(*end)) { --end; }
        ++end;  // make end exclusive
>>>>>>> miniblink49
    }
    size_t len = end - start;
    memmove(str, start, len);
    s->resize(len);
}

namespace lmpParser {

static const TagHandler axisHandler = {
<<<<<<< HEAD
    /*start*/ [](FamilyData* self, const char* tag, const char** attributes) {
        FontFileInfo& file = *self->fCurrentFontInfo;
        SkFourByteTag axisTag = SkSetFourByteTag('\0', '\0', '\0', '\0');
        SkFixed axisStyleValue = 0;
        bool axisTagIsValid = false;
        bool axisStyleValueIsValid = false;
        for (size_t i = 0; ATTS_NON_NULL(attributes, i); i += 2) {
            const char* name = attributes[i];
            const char* value = attributes[i + 1];
=======
    /*start*/[](FamilyData* self, const char* tag, const char** attributes) {
        FontFileInfo& file = *self->fCurrentFontInfo;
        FontFileInfo::Axis& axis = file.fAxes.push_back();
        for (size_t i = 0; ATTS_NON_NULL(attributes, i); i += 2) {
            const char* name = attributes[i];
            const char* value = attributes[i+1];
>>>>>>> miniblink49
            size_t nameLen = strlen(name);
            if (MEMEQ("tag", name, nameLen)) {
                size_t valueLen = strlen(value);
                if (valueLen == 4) {
<<<<<<< HEAD
                    axisTag = SkSetFourByteTag(value[0], value[1], value[2], value[3]);
                    axisTagIsValid = true;
                    for (int j = 0; j < file.fAxes.count() - 1; ++j) {
                        if (file.fAxes[j].fTag == axisTag) {
                            axisTagIsValid = false;
                            SK_FONTCONFIGPARSER_WARNING("'%c%c%c%c' axis specified more than once",
                                (axisTag >> 24) & 0xFF,
                                (axisTag >> 16) & 0xFF,
                                (axisTag >> 8) & 0xFF,
                                (axisTag)&0xFF);
                        }
                    }
=======
                    SkFourByteTag tag = SkSetFourByteTag(value[0], value[1], value[2], value[3]);
                    for (int j = 0; j < file.fAxes.count() - 1; ++j) {
                        if (file.fAxes[j].fTag == tag) {
                            SK_FONTCONFIGPARSER_WARNING("'%c%c%c%c' axis specified more than once",
                                                        (tag >> 24) & 0xFF,
                                                        (tag >> 16) & 0xFF,
                                                        (tag >>  8) & 0xFF,
                                                        (tag      ) & 0xFF);
                        }
                    }
                    axis.fTag = SkSetFourByteTag(value[0], value[1], value[2], value[3]);
>>>>>>> miniblink49
                } else {
                    SK_FONTCONFIGPARSER_WARNING("'%s' is an invalid axis tag", value);
                }
            } else if (MEMEQ("stylevalue", name, nameLen)) {
<<<<<<< HEAD
                if (parse_fixed<16>(value, &axisStyleValue)) {
                    axisStyleValueIsValid = true;
                } else {
=======
                if (!parse_fixed<16>(value, &axis.fValue)) {
>>>>>>> miniblink49
                    SK_FONTCONFIGPARSER_WARNING("'%s' is an invalid axis stylevalue", value);
                }
            }
        }
<<<<<<< HEAD
        if (axisTagIsValid && axisStyleValueIsValid) {
            SkFontMgr::FontParameters::Axis& axis = file.fAxes.push_back();
            axis.fTag = axisTag;
            axis.fStyleValue = SkFixedToScalar(axisStyleValue);
        }
    },
    /*end*/ nullptr,
    /*tag*/ nullptr,
    /*chars*/ nullptr,
};

static const TagHandler fontHandler = {
    /*start*/ [](FamilyData* self, const char* tag, const char** attributes) {
=======
    },
    /*end*/NULL,
    /*tag*/NULL,
    /*chars*/NULL,
};

static const TagHandler fontHandler = {
    /*start*/[](FamilyData* self, const char* tag, const char** attributes) {
>>>>>>> miniblink49
        // 'weight' (non-negative integer) [default 0]
        // 'style' ("normal", "italic") [default "auto"]
        // 'index' (non-negative integer) [default 0]
        // The character data should be a filename.
        FontFileInfo& file = self->fCurrentFamily->fFonts.push_back();
        self->fCurrentFontInfo = &file;
        for (size_t i = 0; ATTS_NON_NULL(attributes, i); i += 2) {
            const char* name = attributes[i];
<<<<<<< HEAD
            const char* value = attributes[i + 1];
=======
            const char* value = attributes[i+1];
>>>>>>> miniblink49
            size_t nameLen = strlen(name);
            if (MEMEQ("weight", name, nameLen)) {
                if (!parse_non_negative_integer(value, &file.fWeight)) {
                    SK_FONTCONFIGPARSER_WARNING("'%s' is an invalid weight", value);
                }
            } else if (MEMEQ("style", name, nameLen)) {
                size_t valueLen = strlen(value);
                if (MEMEQ("normal", value, valueLen)) {
                    file.fStyle = FontFileInfo::Style::kNormal;
                } else if (MEMEQ("italic", value, valueLen)) {
                    file.fStyle = FontFileInfo::Style::kItalic;
                }
            } else if (MEMEQ("index", name, nameLen)) {
                if (!parse_non_negative_integer(value, &file.fIndex)) {
                    SK_FONTCONFIGPARSER_WARNING("'%s' is an invalid index", value);
                }
            }
        }
    },
<<<<<<< HEAD
    /*end*/ [](FamilyData* self, const char* tag) { trim_string(&self->fCurrentFontInfo->fFileName); },
    /*tag*/ [](FamilyData* self, const char* tag, const char** attributes) -> const TagHandler* {
=======
    /*end*/[](FamilyData* self, const char* tag) {
        trim_string(&self->fCurrentFontInfo->fFileName);
    },
    /*tag*/[](FamilyData* self, const char* tag, const char** attributes) -> const TagHandler* {
>>>>>>> miniblink49
        size_t len = strlen(tag);
        if (MEMEQ("axis", tag, len)) {
            return &axisHandler;
        }
<<<<<<< HEAD
        return nullptr; },
    /*chars*/ [](void* data, const char* s, int len) {
        FamilyData* self = static_cast<FamilyData*>(data);
        self->fCurrentFontInfo->fFileName.append(s, len); }
};

static const TagHandler familyHandler = {
    /*start*/ [](FamilyData* self, const char* tag, const char** attributes) {
=======
        return NULL;
    },
    /*chars*/[](void* data, const char* s, int len) {
        FamilyData* self = static_cast<FamilyData*>(data);
        self->fCurrentFontInfo->fFileName.append(s, len);
    }
};

static const TagHandler familyHandler = {
    /*start*/[](FamilyData* self, const char* tag, const char** attributes) {
>>>>>>> miniblink49
        // 'name' (string) [optional]
        // 'lang' (string) [default ""]
        // 'variant' ("elegant", "compact") [default "default"]
        // If there is no name, this is a fallback only font.
        FontFamily* family = new FontFamily(self->fBasePath, true);
        self->fCurrentFamily.reset(family);
        for (size_t i = 0; ATTS_NON_NULL(attributes, i); i += 2) {
            const char* name = attributes[i];
<<<<<<< HEAD
            const char* value = attributes[i + 1];
=======
            const char* value = attributes[i+1];
>>>>>>> miniblink49
            size_t nameLen = strlen(name);
            size_t valueLen = strlen(value);
            if (MEMEQ("name", name, nameLen)) {
                SkAutoAsciiToLC tolc(value);
                family->fNames.push_back().set(tolc.lc());
                family->fIsFallbackFont = false;
            } else if (MEMEQ("lang", name, nameLen)) {
                family->fLanguage = SkLanguage(value, valueLen);
            } else if (MEMEQ("variant", name, nameLen)) {
                if (MEMEQ("elegant", value, valueLen)) {
                    family->fVariant = kElegant_FontVariant;
                } else if (MEMEQ("compact", value, valueLen)) {
                    family->fVariant = kCompact_FontVariant;
                }
            }
        }
    },
<<<<<<< HEAD
    /*end*/ [](FamilyData* self, const char* tag) { *self->fFamilies.append() = self->fCurrentFamily.release(); },
    /*tag*/ [](FamilyData* self, const char* tag, const char** attributes) -> const TagHandler* {
=======
    /*end*/[](FamilyData* self, const char* tag) {
        *self->fFamilies.append() = self->fCurrentFamily.detach();
    },
    /*tag*/[](FamilyData* self, const char* tag, const char** attributes) -> const TagHandler* {
>>>>>>> miniblink49
        size_t len = strlen(tag);
        if (MEMEQ("font", tag, len)) {
            return &fontHandler;
        }
<<<<<<< HEAD
        return nullptr; },
    /*chars*/ nullptr,
};

static FontFamily* find_family(FamilyData* self, const SkString& familyName)
{
=======
        return NULL;
    },
    /*chars*/NULL,
};

static FontFamily* find_family(FamilyData* self, const SkString& familyName) {
>>>>>>> miniblink49
    for (int i = 0; i < self->fFamilies.count(); i++) {
        FontFamily* candidate = self->fFamilies[i];
        for (int j = 0; j < candidate->fNames.count(); j++) {
            if (candidate->fNames[j] == familyName) {
                return candidate;
            }
        }
    }
<<<<<<< HEAD
    return nullptr;
}

static const TagHandler aliasHandler = {
    /*start*/ [](FamilyData* self, const char* tag, const char** attributes) {
=======
    return NULL;
}

static const TagHandler aliasHandler = {
    /*start*/[](FamilyData* self, const char* tag, const char** attributes) {
>>>>>>> miniblink49
        // 'name' (string) introduces a new family name.
        // 'to' (string) specifies which (previous) family to alias
        // 'weight' (non-negative integer) [optional]
        // If it *does not* have a weight, 'name' is an alias for the entire 'to' family.
        // If it *does* have a weight, 'name' is a new family consisting of
        // the font(s) with 'weight' from the 'to' family.

        SkString aliasName;
        SkString to;
        int weight = 0;
        for (size_t i = 0; ATTS_NON_NULL(attributes, i); i += 2) {
            const char* name = attributes[i];
<<<<<<< HEAD
            const char* value = attributes[i + 1];
=======
            const char* value = attributes[i+1];
>>>>>>> miniblink49
            size_t nameLen = strlen(name);
            if (MEMEQ("name", name, nameLen)) {
                SkAutoAsciiToLC tolc(value);
                aliasName.set(tolc.lc());
            } else if (MEMEQ("to", name, nameLen)) {
                to.set(value);
            } else if (MEMEQ("weight", name, nameLen)) {
                if (!parse_non_negative_integer(value, &weight)) {
                    SK_FONTCONFIGPARSER_WARNING("'%s' is an invalid weight", value);
                }
            }
        }

        // Assumes that the named family is already declared
        FontFamily* targetFamily = find_family(self, to);
        if (!targetFamily) {
            SK_FONTCONFIGPARSER_WARNING("'%s' alias target not found", to.c_str());
            return;
        }

        if (weight) {
            FontFamily* family = new FontFamily(targetFamily->fBasePath, self->fIsFallback);
            family->fNames.push_back().set(aliasName);

            for (int i = 0; i < targetFamily->fFonts.count(); i++) {
                if (targetFamily->fFonts[i].fWeight == weight) {
                    family->fFonts.push_back(targetFamily->fFonts[i]);
                }
            }
            *self->fFamilies.append() = family;
        } else {
            targetFamily->fNames.push_back().set(aliasName);
        }
    },
<<<<<<< HEAD
    /*end*/ nullptr,
    /*tag*/ nullptr,
    /*chars*/ nullptr,
};

static const TagHandler familySetHandler = {
    /*start*/ [](FamilyData* self, const char* tag, const char** attributes) {},
    /*end*/ nullptr,
    /*tag*/ [](FamilyData* self, const char* tag, const char** attributes) -> const TagHandler* {
=======
    /*end*/NULL,
    /*tag*/NULL,
    /*chars*/NULL,
};

static const TagHandler familySetHandler = {
    /*start*/[](FamilyData* self, const char* tag, const char** attributes) { },
    /*end*/NULL,
    /*tag*/[](FamilyData* self, const char* tag, const char** attributes) -> const TagHandler* {
>>>>>>> miniblink49
        size_t len = strlen(tag);
        if (MEMEQ("family", tag, len)) {
            return &familyHandler;
        } else if (MEMEQ("alias", tag, len)) {
            return &aliasHandler;
        }
<<<<<<< HEAD
        return nullptr; },
    /*chars*/ nullptr,
=======
        return NULL;
    },
    /*chars*/NULL,
>>>>>>> miniblink49
};

} // lmpParser

namespace jbParser {

static const TagHandler fileHandler = {
<<<<<<< HEAD
    /*start*/ [](FamilyData* self, const char* tag, const char** attributes) {
=======
    /*start*/[](FamilyData* self, const char* tag, const char** attributes) {
>>>>>>> miniblink49
        // 'variant' ("elegant", "compact") [default "default"]
        // 'lang' (string) [default ""]
        // 'index' (non-negative integer) [default 0]
        // The character data should be a filename.
        FontFamily& currentFamily = *self->fCurrentFamily.get();
        FontFileInfo& newFileInfo = currentFamily.fFonts.push_back();
        if (attributes) {
            for (size_t i = 0; ATTS_NON_NULL(attributes, i); i += 2) {
                const char* name = attributes[i];
<<<<<<< HEAD
                const char* value = attributes[i + 1];
=======
                const char* value = attributes[i+1];
>>>>>>> miniblink49
                size_t nameLen = strlen(name);
                size_t valueLen = strlen(value);
                if (MEMEQ("variant", name, nameLen)) {
                    const FontVariant prevVariant = currentFamily.fVariant;
                    if (MEMEQ("elegant", value, valueLen)) {
                        currentFamily.fVariant = kElegant_FontVariant;
                    } else if (MEMEQ("compact", value, valueLen)) {
                        currentFamily.fVariant = kCompact_FontVariant;
                    }
                    if (currentFamily.fFonts.count() > 1 && currentFamily.fVariant != prevVariant) {
                        SK_FONTCONFIGPARSER_WARNING("'%s' unexpected variant found\n"
<<<<<<< HEAD
                                                    "Note: Every font file within a family must have identical variants.",
=======
                            "Note: Every font file within a family must have identical variants.",
>>>>>>> miniblink49
                            value);
                    }

                } else if (MEMEQ("lang", name, nameLen)) {
                    SkLanguage prevLang = currentFamily.fLanguage;
                    currentFamily.fLanguage = SkLanguage(value, valueLen);
                    if (currentFamily.fFonts.count() > 1 && currentFamily.fLanguage != prevLang) {
                        SK_FONTCONFIGPARSER_WARNING("'%s' unexpected language found\n"
<<<<<<< HEAD
                                                    "Note: Every font file within a family must have identical languages.",
=======
                            "Note: Every font file within a family must have identical languages.",
>>>>>>> miniblink49
                            value);
                    }

                } else if (MEMEQ("index", name, nameLen)) {
                    if (!parse_non_negative_integer(value, &newFileInfo.fIndex)) {
                        SK_FONTCONFIGPARSER_WARNING("'%s' is an invalid index", value);
                    }
                }
            }
        }
        self->fCurrentFontInfo = &newFileInfo;
    },
<<<<<<< HEAD
    /*end*/ nullptr,
    /*tag*/ nullptr,
    /*chars*/ [](void* data, const char* s, int len) {
        FamilyData* self = static_cast<FamilyData*>(data);
        self->fCurrentFontInfo->fFileName.append(s, len); }
};

static const TagHandler fileSetHandler = {
    /*start*/ nullptr,
    /*end*/ nullptr,
    /*tag*/ [](FamilyData* self, const char* tag, const char** attributes) -> const TagHandler* {
=======
    /*end*/NULL,
    /*tag*/NULL,
    /*chars*/[](void* data, const char* s, int len) {
        FamilyData* self = static_cast<FamilyData*>(data);
        self->fCurrentFontInfo->fFileName.append(s, len);
    }
};

static const TagHandler fileSetHandler = {
    /*start*/NULL,
    /*end*/NULL,
    /*tag*/[](FamilyData* self, const char* tag, const char** attributes) -> const TagHandler* {
>>>>>>> miniblink49
        size_t len = strlen(tag);
        if (MEMEQ("file", tag, len)) {
            return &fileHandler;
        }
<<<<<<< HEAD
        return nullptr;
    },
    /*chars*/ nullptr,
};

static const TagHandler nameHandler = {
    /*start*/ [](FamilyData* self, const char* tag, const char** attributes) {
        // The character data should be a name for the font.
        self->fCurrentFamily->fNames.push_back();
    },
    /*end*/ nullptr,
    /*tag*/ nullptr,
    /*chars*/ [](void* data, const char* s, int len) {
        FamilyData* self = static_cast<FamilyData*>(data);
        SkAutoAsciiToLC tolc(s, len);
        self->fCurrentFamily->fNames.back().append(tolc.lc(), len); }
};

static const TagHandler nameSetHandler = {
    /*start*/ nullptr,
    /*end*/ nullptr,
    /*tag*/ [](FamilyData* self, const char* tag, const char** attributes) -> const TagHandler* {
=======
        return NULL;
    },
    /*chars*/NULL,
};

static const TagHandler nameHandler = {
    /*start*/[](FamilyData* self, const char* tag, const char** attributes) {
        // The character data should be a name for the font.
        self->fCurrentFamily->fNames.push_back();
    },
    /*end*/NULL,
    /*tag*/NULL,
    /*chars*/[](void* data, const char* s, int len) {
        FamilyData* self = static_cast<FamilyData*>(data);
        SkAutoAsciiToLC tolc(s, len);
        self->fCurrentFamily->fNames.back().append(tolc.lc(), len);
    }
};

static const TagHandler nameSetHandler = {
    /*start*/NULL,
    /*end*/NULL,
    /*tag*/[](FamilyData* self, const char* tag, const char** attributes) -> const TagHandler* {
>>>>>>> miniblink49
        size_t len = strlen(tag);
        if (MEMEQ("name", tag, len)) {
            return &nameHandler;
        }
<<<<<<< HEAD
        return nullptr;
    },
    /*chars*/ nullptr,
};

static const TagHandler familyHandler = {
    /*start*/ [](FamilyData* self, const char* tag, const char** attributes) {
        self->fCurrentFamily.reset(new FontFamily(self->fBasePath, self->fIsFallback));
        // 'order' (non-negative integer) [default -1]
        for (size_t i = 0; ATTS_NON_NULL(attributes, i); i += 2) {
            const char* value = attributes[i + 1];
            parse_non_negative_integer(value, &self->fCurrentFamily->fOrder);
        }
    },
    /*end*/ [](FamilyData* self, const char* tag) { *self->fFamilies.append() = self->fCurrentFamily.release(); },
    /*tag*/ [](FamilyData* self, const char* tag, const char** attributes) -> const TagHandler* {
=======
        return NULL;
    },
    /*chars*/NULL,
};

static const TagHandler familyHandler = {
    /*start*/[](FamilyData* self, const char* tag, const char** attributes) {
        self->fCurrentFamily.reset(new FontFamily(self->fBasePath, self->fIsFallback));
        // 'order' (non-negative integer) [default -1]
        for (size_t i = 0; ATTS_NON_NULL(attributes, i); i += 2) {
            const char* value = attributes[i+1];
            parse_non_negative_integer(value, &self->fCurrentFamily->fOrder);
        }
    },
    /*end*/[](FamilyData* self, const char* tag) {
        *self->fFamilies.append() = self->fCurrentFamily.detach();
    },
    /*tag*/[](FamilyData* self, const char* tag, const char** attributes) -> const TagHandler* {
>>>>>>> miniblink49
        size_t len = strlen(tag);
        if (MEMEQ("nameset", tag, len)) {
            return &nameSetHandler;
        } else if (MEMEQ("fileset", tag, len)) {
            return &fileSetHandler;
        }
<<<<<<< HEAD
        return nullptr; },
    /*chars*/ nullptr,
};

static const TagHandler familySetHandler = {
    /*start*/ nullptr,
    /*end*/ nullptr,
    /*tag*/ [](FamilyData* self, const char* tag, const char** attributes) -> const TagHandler* {
=======
        return NULL;
    },
    /*chars*/NULL,
};

static const TagHandler familySetHandler = {
    /*start*/NULL,
    /*end*/NULL,
    /*tag*/[](FamilyData* self, const char* tag, const char** attributes) -> const TagHandler* {
>>>>>>> miniblink49
        size_t len = strlen(tag);
        if (MEMEQ("family", tag, len)) {
            return &familyHandler;
        }
<<<<<<< HEAD
        return nullptr;
    },
    /*chars*/ nullptr,
=======
        return NULL;
    },
    /*chars*/NULL,
>>>>>>> miniblink49
};

} // namespace jbParser

static const TagHandler topLevelHandler = {
<<<<<<< HEAD
    /*start*/ nullptr,
    /*end*/ nullptr,
    /*tag*/ [](FamilyData* self, const char* tag, const char** attributes) -> const TagHandler* {
=======
    /*start*/NULL,
    /*end*/NULL,
    /*tag*/[](FamilyData* self, const char* tag, const char** attributes) -> const TagHandler* {
>>>>>>> miniblink49
        size_t len = strlen(tag);
        if (MEMEQ("familyset", tag, len)) {
            // 'version' (non-negative integer) [default 0]
            for (size_t i = 0; ATTS_NON_NULL(attributes, i); i += 2) {
                const char* name = attributes[i];
                size_t nameLen = strlen(name);
                if (MEMEQ("version", name, nameLen)) {
<<<<<<< HEAD
                    const char* value = attributes[i + 1];
=======
                    const char* value = attributes[i+1];
>>>>>>> miniblink49
                    if (parse_non_negative_integer(value, &self->fVersion)) {
                        if (self->fVersion >= 21) {
                            return &lmpParser::familySetHandler;
                        }
                    }
                }
            }
            return &jbParser::familySetHandler;
        }
<<<<<<< HEAD
        return nullptr;
    },
    /*chars*/ nullptr,
};

static void XMLCALL start_element_handler(void* data, const char* tag, const char** attributes)
{
=======
        return NULL;
    },
    /*chars*/NULL,
};

static void XMLCALL start_element_handler(void *data, const char *tag, const char **attributes) {
>>>>>>> miniblink49
    FamilyData* self = static_cast<FamilyData*>(data);

    if (!self->fSkip) {
        const TagHandler* parent = self->fHandler.top();
<<<<<<< HEAD
        const TagHandler* child = parent->tag ? parent->tag(self, tag, attributes) : nullptr;
=======
        const TagHandler* child = parent->tag ? parent->tag(self, tag, attributes) : NULL;
>>>>>>> miniblink49
        if (child) {
            if (child->start) {
                child->start(self, tag, attributes);
            }
            self->fHandler.push(child);
            XML_SetCharacterDataHandler(self->fParser, child->chars);
        } else {
            SK_FONTCONFIGPARSER_WARNING("'%s' tag not recognized, skipping", tag);
<<<<<<< HEAD
            XML_SetCharacterDataHandler(self->fParser, nullptr);
=======
            XML_SetCharacterDataHandler(self->fParser, NULL);
>>>>>>> miniblink49
            self->fSkip = self->fDepth;
        }
    }

    ++self->fDepth;
}

<<<<<<< HEAD
static void XMLCALL end_element_handler(void* data, const char* tag)
{
=======
static void XMLCALL end_element_handler(void* data, const char* tag) {
>>>>>>> miniblink49
    FamilyData* self = static_cast<FamilyData*>(data);
    --self->fDepth;

    if (!self->fSkip) {
        const TagHandler* child = self->fHandler.top();
        if (child->end) {
            child->end(self, tag);
        }
        self->fHandler.pop();
        const TagHandler* parent = self->fHandler.top();
        XML_SetCharacterDataHandler(self->fParser, parent->chars);
    }

    if (self->fSkip == self->fDepth) {
        self->fSkip = 0;
        const TagHandler* parent = self->fHandler.top();
        XML_SetCharacterDataHandler(self->fParser, parent->chars);
    }
}

<<<<<<< HEAD
static void XMLCALL xml_entity_decl_handler(void* data,
    const XML_Char* entityName,
    int is_parameter_entity,
    const XML_Char* value,
    int value_length,
    const XML_Char* base,
    const XML_Char* systemId,
    const XML_Char* publicId,
    const XML_Char* notationName)
=======
static void XMLCALL xml_entity_decl_handler(void *data,
                                            const XML_Char *entityName,
                                            int is_parameter_entity,
                                            const XML_Char *value,
                                            int value_length,
                                            const XML_Char *base,
                                            const XML_Char *systemId,
                                            const XML_Char *publicId,
                                            const XML_Char *notationName)
>>>>>>> miniblink49
{
    FamilyData* self = static_cast<FamilyData*>(data);
    SK_FONTCONFIGPARSER_WARNING("'%s' entity declaration found, stopping processing", entityName);
    XML_StopParser(self->fParser, XML_FALSE);
}

static const XML_Memory_Handling_Suite sk_XML_alloc = {
    sk_malloc_throw,
    sk_realloc_throw,
    sk_free
};

<<<<<<< HEAD
=======
template<typename T> struct remove_ptr {typedef T type;};
template<typename T> struct remove_ptr<T*> {typedef T type;};

>>>>>>> miniblink49
/**
 * This function parses the given filename and stores the results in the given
 * families array. Returns the version of the file, negative if the file does not exist.
 */
static int parse_config_file(const char* filename, SkTDArray<FontFamily*>& families,
<<<<<<< HEAD
    const SkString& basePath, bool isFallback)
=======
                             const SkString& basePath, bool isFallback)
>>>>>>> miniblink49
{
    SkFILEStream file(filename);

    // Some of the files we attempt to parse (in particular, /vendor/etc/fallback_fonts.xml)
    // are optional - failure here is okay because one of these optional files may not exist.
    if (!file.isValid()) {
        SkDebugf(SK_FONTMGR_ANDROID_PARSER_PREFIX "'%s' could not be opened\n", filename);
        return -1;
    }

<<<<<<< HEAD
    SkAutoTCallVProc<skstd::remove_pointer_t<XML_Parser>, XML_ParserFree> parser(
        XML_ParserCreate_MM(nullptr, &sk_XML_alloc, nullptr));
=======
    SkAutoTCallVProc<remove_ptr<XML_Parser>::type, XML_ParserFree> parser(
        XML_ParserCreate_MM(NULL, &sk_XML_alloc, NULL));
>>>>>>> miniblink49
    if (!parser) {
        SkDebugf(SK_FONTMGR_ANDROID_PARSER_PREFIX "could not create XML parser\n");
        return -1;
    }

    FamilyData self(parser, families, basePath, isFallback, filename, &topLevelHandler);
    XML_SetUserData(parser, &self);

    // Disable entity processing, to inhibit internal entity expansion. See expat CVE-2013-0340
    XML_SetEntityDeclHandler(parser, xml_entity_decl_handler);

    // Start parsing oldschool; switch these in flight if we detect a newer version of the file.
    XML_SetElementHandler(parser, start_element_handler, end_element_handler);

    // One would assume it would be faster to have a buffer on the stack and call XML_Parse.
    // But XML_Parse will call XML_GetBuffer anyway and memmove the passed buffer into it.
    // (Unless XML_CONTEXT_BYTES is undefined, but all users define it.)
    // In debug, buffer a small odd number of bytes to detect slicing in XML_CharacterDataHandler.
<<<<<<< HEAD
    static const int bufferSize = 512 SkDEBUGCODE(-507);
=======
    static const int bufferSize = 512 SkDEBUGCODE( - 507);
>>>>>>> miniblink49
    bool done = false;
    while (!done) {
        void* buffer = XML_GetBuffer(parser, bufferSize);
        if (!buffer) {
            SkDebugf(SK_FONTMGR_ANDROID_PARSER_PREFIX "could not buffer enough to continue\n");
            return -1;
        }
        size_t len = file.read(buffer, bufferSize);
        done = file.isAtEnd();
        XML_Status status = XML_ParseBuffer(parser, len, done);
        if (XML_STATUS_ERROR == status) {
            XML_Error error = XML_GetErrorCode(parser);
            int line = XML_GetCurrentLineNumber(parser);
            int column = XML_GetCurrentColumnNumber(parser);
            const XML_LChar* errorString = XML_ErrorString(error);
            SkDebugf(SK_FONTMGR_ANDROID_PARSER_PREFIX "%s:%d:%d error %d: %s.\n",
<<<<<<< HEAD
                filename, line, column, error, errorString);
=======
                     filename, line, column, error, errorString);
>>>>>>> miniblink49
            return -1;
        }
    }
    return self.fVersion;
}

/** Returns the version of the system font file actually found, negative if none. */
static int append_system_font_families(SkTDArray<FontFamily*>& fontFamilies,
<<<<<<< HEAD
    const SkString& basePath)
=======
                                       const SkString& basePath)
>>>>>>> miniblink49
{
    int initialCount = fontFamilies.count();
    int version = parse_config_file(LMP_SYSTEM_FONTS_FILE, fontFamilies, basePath, false);
    if (version < 0 || fontFamilies.count() == initialCount) {
        version = parse_config_file(OLD_SYSTEM_FONTS_FILE, fontFamilies, basePath, false);
    }
    return version;
}

/**
 * In some versions of Android prior to Android 4.2 (JellyBean MR1 at API
 * Level 17) the fallback fonts for certain locales were encoded in their own
 * XML files with a suffix that identified the locale.  We search the provided
 * directory for those files,add all of their entries to the fallback chain, and
 * include the locale as part of each entry.
 */
static void append_fallback_font_families_for_locale(SkTDArray<FontFamily*>& fallbackFonts,
<<<<<<< HEAD
    const char* dir,
    const SkString& basePath)
{
    SkAutoTCallIProc<DIR, closedir> fontDirectory(opendir(dir));
    if (nullptr == fontDirectory) {
=======
                                                     const char* dir,
                                                     const SkString& basePath)
{
#if defined(SK_BUILD_FOR_ANDROID_FRAMEWORK)
    // The framework is beyond Android 4.2 and can therefore skip this function
    return;
#endif

    SkAutoTCallIProc<DIR, closedir> fontDirectory(opendir(dir));
    if (NULL == fontDirectory) {
>>>>>>> miniblink49
        return;
    }

    for (struct dirent* dirEntry; (dirEntry = readdir(fontDirectory));) {
        // The size of the prefix and suffix.
        static const size_t fixedLen = sizeof(LOCALE_FALLBACK_FONTS_PREFIX) - 1
<<<<<<< HEAD
            + sizeof(LOCALE_FALLBACK_FONTS_SUFFIX) - 1;
=======
                                     + sizeof(LOCALE_FALLBACK_FONTS_SUFFIX) - 1;
>>>>>>> miniblink49

        // The size of the prefix, suffix, and a minimum valid language code
        static const size_t minSize = fixedLen + 2;

        SkString fileName(dirEntry->d_name);
<<<<<<< HEAD
        if (fileName.size() < minSize || !fileName.startsWith(LOCALE_FALLBACK_FONTS_PREFIX) || !fileName.endsWith(LOCALE_FALLBACK_FONTS_SUFFIX)) {
=======
        if (fileName.size() < minSize ||
            !fileName.startsWith(LOCALE_FALLBACK_FONTS_PREFIX) ||
            !fileName.endsWith(LOCALE_FALLBACK_FONTS_SUFFIX))
        {
>>>>>>> miniblink49
            continue;
        }

        SkString locale(fileName.c_str() + sizeof(LOCALE_FALLBACK_FONTS_PREFIX) - 1,
<<<<<<< HEAD
            fileName.size() - fixedLen);
=======
                        fileName.size() - fixedLen);
>>>>>>> miniblink49

        SkString absoluteFilename;
        absoluteFilename.printf("%s/%s", dir, fileName.c_str());

        SkTDArray<FontFamily*> langSpecificFonts;
        parse_config_file(absoluteFilename.c_str(), langSpecificFonts, basePath, true);

        for (int i = 0; i < langSpecificFonts.count(); ++i) {
            FontFamily* family = langSpecificFonts[i];
            family->fLanguage = SkLanguage(locale);
            *fallbackFonts.append() = family;
        }
    }
}

static void append_system_fallback_font_families(SkTDArray<FontFamily*>& fallbackFonts,
<<<<<<< HEAD
    const SkString& basePath)
{
    parse_config_file(FALLBACK_FONTS_FILE, fallbackFonts, basePath, true);
    append_fallback_font_families_for_locale(fallbackFonts,
        LOCALE_FALLBACK_FONTS_SYSTEM_DIR,
        basePath);
}

static void mixin_vendor_fallback_font_families(SkTDArray<FontFamily*>& fallbackFonts,
    const SkString& basePath)
=======
                                                 const SkString& basePath)
{
    parse_config_file(FALLBACK_FONTS_FILE, fallbackFonts, basePath, true);
    append_fallback_font_families_for_locale(fallbackFonts,
                                             LOCALE_FALLBACK_FONTS_SYSTEM_DIR,
                                             basePath);
}

static void mixin_vendor_fallback_font_families(SkTDArray<FontFamily*>& fallbackFonts,
                                                const SkString& basePath)
>>>>>>> miniblink49
{
    SkTDArray<FontFamily*> vendorFonts;
    parse_config_file(VENDOR_FONTS_FILE, vendorFonts, basePath, true);
    append_fallback_font_families_for_locale(vendorFonts,
<<<<<<< HEAD
        LOCALE_FALLBACK_FONTS_VENDOR_DIR,
        basePath);
=======
                                             LOCALE_FALLBACK_FONTS_VENDOR_DIR,
                                             basePath);
>>>>>>> miniblink49

    // This loop inserts the vendor fallback fonts in the correct order in the
    // overall fallbacks list.
    int currentOrder = -1;
    for (int i = 0; i < vendorFonts.count(); ++i) {
        FontFamily* family = vendorFonts[i];
        int order = family->fOrder;
        if (order < 0) {
            if (currentOrder < 0) {
                // Default case - just add it to the end of the fallback list
                *fallbackFonts.append() = family;
            } else {
                // no order specified on this font, but we're incrementing the order
                // based on an earlier order insertion request
                *fallbackFonts.insert(currentOrder++) = family;
            }
        } else {
            // Add the font into the fallback list in the specified order. Set
            // currentOrder for correct placement of other fonts in the vendor list.
            *fallbackFonts.insert(order) = family;
            currentOrder = order + 1;
        }
    }
}

<<<<<<< HEAD
void SkFontMgr_Android_Parser::GetSystemFontFamilies(SkTDArray<FontFamily*>& fontFamilies)
{
=======
void SkFontMgr_Android_Parser::GetSystemFontFamilies(SkTDArray<FontFamily*>& fontFamilies) {
>>>>>>> miniblink49
    // Version 21 of the system font configuration does not need any fallback configuration files.
    SkString basePath(getenv("ANDROID_ROOT"));
    basePath.append(SK_FONT_FILE_PREFIX, sizeof(SK_FONT_FILE_PREFIX) - 1);

    if (append_system_font_families(fontFamilies, basePath) >= 21) {
        return;
    }

    // Append all the fallback fonts to system fonts
    SkTDArray<FontFamily*> fallbackFonts;
    append_system_fallback_font_families(fallbackFonts, basePath);
    mixin_vendor_fallback_font_families(fallbackFonts, basePath);
    fontFamilies.append(fallbackFonts.count(), fallbackFonts.begin());
}

void SkFontMgr_Android_Parser::GetCustomFontFamilies(SkTDArray<FontFamily*>& fontFamilies,
<<<<<<< HEAD
    const SkString& basePath,
    const char* fontsXml,
    const char* fallbackFontsXml,
    const char* langFallbackFontsDir)
=======
                                                     const SkString& basePath,
                                                     const char* fontsXml,
                                                     const char* fallbackFontsXml,
                                                     const char* langFallbackFontsDir)
>>>>>>> miniblink49
{
    if (fontsXml) {
        parse_config_file(fontsXml, fontFamilies, basePath, false);
    }
    if (fallbackFontsXml) {
        parse_config_file(fallbackFontsXml, fontFamilies, basePath, true);
    }
    if (langFallbackFontsDir) {
        append_fallback_font_families_for_locale(fontFamilies,
<<<<<<< HEAD
            langFallbackFontsDir,
            basePath);
    }
}

SkLanguage SkLanguage::getParent() const
{
=======
                                                 langFallbackFontsDir,
                                                 basePath);
    }
}

SkLanguage SkLanguage::getParent() const {
>>>>>>> miniblink49
    SkASSERT(!fTag.isEmpty());
    const char* tag = fTag.c_str();

    // strip off the rightmost "-.*"
    const char* parentTagEnd = strrchr(tag, '-');
<<<<<<< HEAD
    if (parentTagEnd == nullptr) {
=======
    if (parentTagEnd == NULL) {
>>>>>>> miniblink49
        return SkLanguage();
    }
    size_t parentTagLen = parentTagEnd - tag;
    return SkLanguage(tag, parentTagLen);
}
