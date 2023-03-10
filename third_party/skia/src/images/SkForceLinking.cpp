/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkForceLinking.h"
#include "SkImageEncoder.h"

// This method is required to fool the linker into not discarding the pre-main
// initialization and registration of the encoder classes. Passing true will
// cause memory leaks.
int SkForceLinking(bool doNotPassTrue)
{
    if (doNotPassTrue) {
        SkASSERT(false);
#if defined(SK_HAS_JPEG_LIBRARY)
        CreateJPEGImageEncoder();
#endif
#if defined(SK_HAS_WEBP_LIBRARY)
        CreateWEBPImageEncoder();
#endif

        // Only link hardware texture codecs on platforms that build them. See images.gyp
#ifndef SK_BUILD_FOR_ANDROID_FRAMEWORK
        CreateKTXImageEncoder();
#endif

#if !defined(SK_BUILD_FOR_MAC) && !defined(SK_BUILD_FOR_WIN) && !defined(SK_BUILD_FOR_IOS) && defined(SK_HAS_PNG_LIBRARY)
        CreatePNGImageEncoder();
#endif
#if defined(SK_BUILD_FOR_MAC) || defined(SK_BUILD_FOR_IOS)
        CreatePNGImageEncoder_CG();
#endif
#if defined(SK_BUILD_FOR_WIN)
        CreateImageEncoder_WIC();
#endif
        return -1;
    }
    return 0;
}
