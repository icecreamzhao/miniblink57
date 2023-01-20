<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkTypes.h"
#if !defined(SK_BUILD_FOR_WIN32) && !defined(SK_BUILD_FOR_ANDROID)
=======

#include "SkTypes.h"
>>>>>>> miniblink49

#include <stdarg.h>
#include <stdio.h>

<<<<<<< HEAD
void SkDebugf(const char format[], ...)
{
=======
void SkDebugf(const char format[], ...) {
>>>>>>> miniblink49
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}
<<<<<<< HEAD
#endif //!defined(SK_BUILD_FOR_WIN32) && !defined(SK_BUILD_FOR_ANDROID)
=======
>>>>>>> miniblink49
