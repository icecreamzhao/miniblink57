<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkErrorInternals_DEFINED
#define SkErrorInternals_DEFINED

#include "SkError.h"

class SkErrorInternals {

public:
    static void ClearError();
<<<<<<< HEAD
    static void SetError(SkError code, const char* fmt, ...);
    static SkError GetLastError();
    static const char* GetLastErrorString();
    static void SetErrorCallback(SkErrorCallbackFunction cb, void* context);
    static void DefaultErrorCallback(SkError code, void* context);
};

=======
    static void SetError(SkError code, const char *fmt, ...);
    static SkError GetLastError();
    static const char *GetLastErrorString();
    static void SetErrorCallback(SkErrorCallbackFunction cb, void *context);
    static void DefaultErrorCallback(SkError code, void *context);
};



>>>>>>> miniblink49
#endif /* SkErrorInternals_DEFINED */
