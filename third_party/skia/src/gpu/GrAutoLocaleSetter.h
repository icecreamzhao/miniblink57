/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrAutoLocaleSetter_DEFINED
#define GrAutoLocaleSetter_DEFINED

#include "GrTypes.h"

<<<<<<< HEAD
#if defined(SK_BUILD_FOR_WIN)
#include "SkString.h"
#endif

=======
>>>>>>> miniblink49
#if !defined(SK_BUILD_FOR_ANDROID)
#include <locale.h>
#endif

#if defined(SK_BUILD_FOR_MAC) || defined(SK_BUILD_FOR_IOS)
#include <xlocale.h>
#endif

<<<<<<< HEAD
#if defined(SK_BUILD_FOR_ANDROID) || defined(__UCLIBC__) || defined(_NEWLIB_VERSION)
#define HAVE_LOCALE_T 0
#else
#define HAVE_LOCALE_T 1
#endif

=======
>>>>>>> miniblink49
/**
 * Helper class for ensuring that we don't use the wrong locale when building shaders. Android
 * doesn't support locale in the NDK, so this is a no-op there.
 */
<<<<<<< HEAD
class GrAutoLocaleSetter : public SkNoncopyable {
public:
    GrAutoLocaleSetter(const char* name)
    {
#if defined(SK_BUILD_FOR_WIN)
        fOldPerThreadLocale = _configthreadlocale(_ENABLE_PER_THREAD_LOCALE);
        char* oldLocale = setlocale(LC_ALL, name);
        if (oldLocale) {
            fOldLocale = oldLocale;
            fShouldRestoreLocale = true;
        } else {
            fShouldRestoreLocale = false;
        }
#elif HAVE_LOCALE_T
        fLocale = newlocale(LC_ALL, name, 0);
        if (fLocale) {
            fOldLocale = uselocale(fLocale);
        } else {
            fOldLocale = static_cast<locale_t>(0);
        }
#else
        (void)name; // suppress unused param warning.
#endif
    }

    ~GrAutoLocaleSetter()
    {
#if defined(SK_BUILD_FOR_WIN)
        if (fShouldRestoreLocale) {
            setlocale(LC_ALL, fOldLocale.c_str());
        }
        _configthreadlocale(fOldPerThreadLocale);
#elif HAVE_LOCALE_T
        if (fLocale) {
            uselocale(fOldLocale);
            freelocale(fLocale);
=======
class GrAutoLocaleSetter {
public:
    GrAutoLocaleSetter (const char* name) {
#if defined(SK_BUILD_FOR_WIN)
        fOldPerThreadLocale = _configthreadlocale(_ENABLE_PER_THREAD_LOCALE);
        fOldLocale = setlocale(LC_ALL, name);
#elif !defined(SK_BUILD_FOR_ANDROID) && !defined(__UCLIBC__)
        fLocale = newlocale(LC_ALL, name, 0);
        if (fLocale) {
            fOldLocale = uselocale(fLocale);
        }
#else
        (void) name; // suppress unused param warning.
#endif
    }

    ~GrAutoLocaleSetter () {
#if defined(SK_BUILD_FOR_WIN)
        setlocale(LC_ALL, fOldLocale);
        _configthreadlocale(fOldPerThreadLocale);
#elif !defined(SK_BUILD_FOR_ANDROID) && !defined(__UCLIBC__)
        if (fLocale) {
             uselocale(fOldLocale);
             freelocale(fLocale);
>>>>>>> miniblink49
        }
#endif
    }

private:
#if defined(SK_BUILD_FOR_WIN)
    int fOldPerThreadLocale;
<<<<<<< HEAD
    bool fShouldRestoreLocale;
    SkString fOldLocale;
#elif HAVE_LOCALE_T
=======
    const char* fOldLocale;
#elif !defined(SK_BUILD_FOR_ANDROID) && !defined(__UCLIBC__)
>>>>>>> miniblink49
    locale_t fOldLocale;
    locale_t fLocale;
#endif
};

<<<<<<< HEAD
#undef HAVE_LOCALE_T

#endif
=======
#endif

>>>>>>> miniblink49
