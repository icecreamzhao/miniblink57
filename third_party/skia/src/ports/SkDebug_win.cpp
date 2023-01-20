<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2010 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkTypes.h"

#if defined(SK_BUILD_FOR_WIN32)

#include "SkLeanWindows.h"

#include <stdarg.h>
#include <stdio.h>

static const size_t kBufferSize = 2048;

void SkDebugf(const char format[], ...)
{
    char buffer[kBufferSize + 1];
    va_list args;

    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    fflush(stderr); // stderr seems to be buffered on Windows.

    va_start(args, format);
    vsnprintf(buffer, kBufferSize, format, args);
=======


#include "SkTypes.h"

static const size_t kBufferSize = 2048;

#include <stdarg.h>
#include <stdio.h>
#include <windows.h>

void SkDebugf(const char format[], ...) {
    char    buffer[kBufferSize + 1];
    va_list args;

    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    // When we crash on Windows we often are missing a lot of prints. Since we don't really care
    // about SkDebugf performance we flush after every print.
//    fflush(stdout);

    va_start(args, format);
#if USING_VC6RT == 1
    vsprintf(buffer, format, args);
#else
    vsnprintf_s(buffer, kBufferSize, format, args);
#endif
>>>>>>> miniblink49
    va_end(args);

    OutputDebugStringA(buffer);
}
<<<<<<< HEAD
#endif //defined(SK_BUILD_FOR_WIN32)
=======
>>>>>>> miniblink49
