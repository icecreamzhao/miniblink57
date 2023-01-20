/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "gl/GrGLExtensions.h"
#include "gl/GrGLDefines.h"
#include "gl/GrGLUtil.h"

#include "SkTSearch.h"
#include "SkTSort.h"

namespace { // This cannot be static because it is used as a template parameter.
<<<<<<< HEAD
inline bool extension_compare(const SkString& a, const SkString& b)
{
=======
inline bool extension_compare(const SkString& a, const SkString& b) {
>>>>>>> miniblink49
    return strcmp(a.c_str(), b.c_str()) < 0;
}
}

// finds the index of ext in strings or a negative result if ext is not found.
<<<<<<< HEAD
static int find_string(const SkTArray<SkString>& strings, const char ext[])
{
=======
static int find_string(const SkTArray<SkString>& strings, const char ext[]) {
>>>>>>> miniblink49
    if (strings.empty()) {
        return -1;
    }
    SkString extensionStr(ext);
    int idx = SkTSearch<SkString, extension_compare>(&strings.front(),
<<<<<<< HEAD
        strings.count(),
        extensionStr,
        sizeof(SkString));
    return idx;
}

GrGLExtensions::GrGLExtensions(const GrGLExtensions& that)
    : fStrings(new SkTArray<SkString>)
{
    *this = that;
}

GrGLExtensions& GrGLExtensions::operator=(const GrGLExtensions& that)
{
=======
                                                     strings.count(),
                                                     extensionStr,
                                                     sizeof(SkString));
    return idx;
}

GrGLExtensions::GrGLExtensions(const GrGLExtensions& that) : fStrings(SkNEW(SkTArray<SkString>)) {
    *this = that;
}

GrGLExtensions& GrGLExtensions::operator=(const GrGLExtensions& that) {
>>>>>>> miniblink49
    *fStrings = *that.fStrings;
    fInitialized = that.fInitialized;
    return *this;
}

<<<<<<< HEAD
static void eat_space_sep_strings(SkTArray<SkString>* out, const char in[])
{
    if (!in) {
        return;
    }
    while (true) {
        // skip over multiple spaces between extensions
        while (' ' == *in) {
            ++in;
        }
        // quit once we reach the end of the string.
        if ('\0' == *in) {
            break;
        }
        // we found an extension
        size_t length = strcspn(in, " ");
        out->push_back().set(in, length);
        in += length;
    }
}

bool GrGLExtensions::init(GrGLStandard standard,
    GrGLFunction<GrGLGetStringProc> getString,
    GrGLFunction<GrGLGetStringiProc> getStringi,
    GrGLFunction<GrGLGetIntegervProc> getIntegerv,
    GrGLFunction<GrEGLQueryStringProc> queryString,
    GrEGLDisplay eglDisplay)
{
    fInitialized = false;
    fStrings->reset();

    if (!getString) {
=======
bool GrGLExtensions::init(GrGLStandard standard,
                          GrGLGetStringProc getString,
                          GrGLGetStringiProc getStringi,
                          GrGLGetIntegervProc getIntegerv) {
    fInitialized = false;
    fStrings->reset();

    if (NULL == getString) {
>>>>>>> miniblink49
        return false;
    }

    // glGetStringi and indexed extensions were added in version 3.0 of desktop GL and ES.
    const GrGLubyte* verString = getString(GR_GL_VERSION);
<<<<<<< HEAD
    GrGLVersion version = GrGLGetVersionFromString((const char*)verString);
=======
    GrGLVersion version = GrGLGetVersionFromString((const char*) verString);
>>>>>>> miniblink49
    if (GR_GL_INVALID_VER == version) {
        return false;
    }

    bool indexed = version >= GR_GL_VER(3, 0);

    if (indexed) {
<<<<<<< HEAD
        if (!getStringi || !getIntegerv) {
=======
        if (NULL == getStringi || NULL == getIntegerv) {
>>>>>>> miniblink49
            return false;
        }
        GrGLint extensionCnt = 0;
        getIntegerv(GR_GL_NUM_EXTENSIONS, &extensionCnt);
        fStrings->push_back_n(extensionCnt);
        for (int i = 0; i < extensionCnt; ++i) {
<<<<<<< HEAD
            const char* ext = (const char*)getStringi(GR_GL_EXTENSIONS, i);
            (*fStrings)[i] = ext;
        }
    } else {
        const char* extensions = (const char*)getString(GR_GL_EXTENSIONS);
        if (!extensions) {
            return false;
        }
        eat_space_sep_strings(fStrings, extensions);
    }
    if (queryString) {
        const char* extensions = queryString(eglDisplay, GR_EGL_EXTENSIONS);

        eat_space_sep_strings(fStrings, extensions);
=======
            const char* ext = (const char*) getStringi(GR_GL_EXTENSIONS, i);
            (*fStrings)[i] = ext;
        }
    } else {
        const char* extensions = (const char*) getString(GR_GL_EXTENSIONS);
        if (NULL == extensions) {
            return false;
        }
        while (true) {
            // skip over multiple spaces between extensions
            while (' ' == *extensions) {
                ++extensions;
            }
            // quit once we reach the end of the string.
            if ('\0' == *extensions) {
                break;
            }
            // we found an extension
            size_t length = strcspn(extensions, " ");
            fStrings->push_back().set(extensions, length);
            extensions += length;
        }
>>>>>>> miniblink49
    }
    if (!fStrings->empty()) {
        SkTLessFunctionToFunctorAdaptor<SkString, extension_compare> cmp;
        SkTQSort(&fStrings->front(), &fStrings->back(), cmp);
    }
    fInitialized = true;
    return true;
}

<<<<<<< HEAD
bool GrGLExtensions::has(const char ext[]) const
{
=======
bool GrGLExtensions::has(const char ext[]) const {
>>>>>>> miniblink49
    SkASSERT(fInitialized);
    return find_string(*fStrings, ext) >= 0;
}

<<<<<<< HEAD
bool GrGLExtensions::remove(const char ext[])
{
=======
bool GrGLExtensions::remove(const char ext[]) {
>>>>>>> miniblink49
    SkASSERT(fInitialized);
    int idx = find_string(*fStrings, ext);
    if (idx >= 0) {
        // This is not terribly effecient but we really only expect this function to be called at
        // most a handful of times when our test programs start.
<<<<<<< HEAD
        SkAutoTDelete<SkTArray<SkString>> oldStrings(fStrings.release());
        fStrings.reset(new SkTArray<SkString>(oldStrings->count() - 1));
=======
        SkAutoTDelete< SkTArray<SkString> > oldStrings(fStrings.detach());
        fStrings.reset(SkNEW(SkTArray<SkString>(oldStrings->count() - 1)));
>>>>>>> miniblink49
        fStrings->push_back_n(idx, &oldStrings->front());
        fStrings->push_back_n(oldStrings->count() - idx - 1, &(*oldStrings)[idx] + 1);
        return true;
    } else {
        return false;
    }
}

<<<<<<< HEAD
void GrGLExtensions::add(const char ext[])
{
=======
void GrGLExtensions::add(const char ext[]) {
>>>>>>> miniblink49
    int idx = find_string(*fStrings, ext);
    if (idx < 0) {
        // This is not the most effecient approach since we end up doing a full sort of the
        // extensions after the add
        fStrings->push_back().set(ext);
        SkTLessFunctionToFunctorAdaptor<SkString, extension_compare> cmp;
        SkTQSort(&fStrings->front(), &fStrings->back(), cmp);
    }
}

<<<<<<< HEAD
void GrGLExtensions::print(const char* sep) const
{
    if (nullptr == sep) {
=======
void GrGLExtensions::print(const char* sep) const {
    if (NULL == sep) {
>>>>>>> miniblink49
        sep = " ";
    }
    int cnt = fStrings->count();
    for (int i = 0; i < cnt; ++i) {
        SkDebugf("%s%s", (*fStrings)[i].c_str(), (i < cnt - 1) ? sep : "");
    }
}
