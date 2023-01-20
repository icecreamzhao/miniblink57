/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkJpegDecoderMgr_DEFINED
#define SkJpegDecoderMgr_DEFINED

#include "SkCodec.h"
#include "SkCodecPriv.h"
<<<<<<< HEAD
#include "SkJpegUtility.h"
#include <stdio.h>

extern "C" {
#include "jpeglib.h"
=======
#include "SkJpegUtility_codec.h"
#include "SkSwizzler.h"
#include "SkTemplates.h"

// stdio is needed for jpeglib
#include <stdio.h>

extern "C" {
    #include "jpeglibmangler.h"
    #include "jpeglib.h"
>>>>>>> miniblink49
}

class JpegDecoderMgr : SkNoncopyable {
public:
<<<<<<< HEAD
=======

>>>>>>> miniblink49
    /*
     * Print a useful error message and return false
     */
    bool returnFalse(const char caller[]);

    /*
     * Print a useful error message and return a decode failure
     */
    SkCodec::Result returnFailure(const char caller[], SkCodec::Result result);

    /*
     * Create the decode manager
     * Does not take ownership of stream
     */
    JpegDecoderMgr(SkStream* stream);

    /*
     * Initialize decompress struct
     * Initialize the source manager
     */
<<<<<<< HEAD
    void init();

    /*
     * Returns true if it successfully sets outColor to the encoded color,
     * and false otherwise.
     */
    bool getEncodedColor(SkEncodedInfo::Color* outColor);
=======
    void  init();

    /*
     * Recommend a color type based on the encoded format
     */
    SkColorType getColorType();
>>>>>>> miniblink49

    /*
     * Free memory used by the decode manager
     */
    ~JpegDecoderMgr();

    /*
     * Get the jump buffer in order to set an error return point
     */
    jmp_buf& getJmpBuf();

    /*
     * Get function for the decompress info struct
     */
    jpeg_decompress_struct* dinfo();

private:
<<<<<<< HEAD
    jpeg_decompress_struct fDInfo;
    skjpeg_source_mgr fSrcMgr;
    skjpeg_error_mgr fErrorMgr;
    bool fInit;
=======

    jpeg_decompress_struct fDInfo;
    skjpeg_source_mgr      fSrcMgr;
    skjpeg_error_mgr       fErrorMgr;
    bool                   fInit;
>>>>>>> miniblink49
};

#endif
